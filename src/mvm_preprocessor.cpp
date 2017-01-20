#include "include\mvm_preprocessor.h"

using std::string;

using mvm::mvm_file;

void mvm::mvm_preprocessor::preprocess(std::string & str)
{
	while (parse_include(str));
	while (parse_define(str));
	mvm_func_remove_surplus_spaces(str);
}

bool mvm::mvm_preprocessor::parse_include(std::string & str)
{

	beg_pos = str.find(MVM_INCLUDE);
	end_pos = str.find(MVM_NEWLINE, beg_pos);
	if (beg_pos == string::npos)
		return false;
	if (end_pos == string::npos)
		end_pos = str.find(MVM_EOF, beg_pos);

	tmp.erase();
	tmp.assign(str, beg_pos, end_pos - beg_pos);
	tmp.erase(0,9);

	mvm_func_trim_string(tmp);

	mvm_file file;

	if (!file.open(tmp))
		if (!file.open(mvm_func_get_parent_path(file_path) + MVM_PATH_DIVIDER + tmp))
		{
			str.erase(beg_pos, end_pos - beg_pos);
			return false;
		}
			

	if (!file.read(include_tmp))
	{
		file.close();
		str.erase(beg_pos, end_pos - beg_pos);
		return false;
	}

	file.close();
	
	include_tmp.pop_back();

	str.replace(beg_pos, end_pos - beg_pos, include_tmp);

	return true;
}
bool mvm::mvm_preprocessor::parse_define(std::string & str)
{
	beg_pos = str.find(MVM_DEFINE);
	end_pos = str.find(MVM_NEWLINE, beg_pos);

	if (beg_pos == string::npos)
		return false;
	if (end_pos == string::npos)
		end_pos = str.find(MVM_EOF, beg_pos);
	
	tmp.erase();
	tmp.assign(str, beg_pos, end_pos - beg_pos);
	tmp.erase(0, 8);

	str.erase(beg_pos, end_pos - beg_pos);

	mvm_func_trim_string_left_right(tmp);


	string left = mvm_func_divide(tmp);

	if (left == tmp)
		return true;

	mvm_func_trim_string_left_right(tmp);

	mvm_func_replace(str, left, tmp);

	return true;

}