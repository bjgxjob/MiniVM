#ifndef _MVM_FUNC_H
#define _MVM_FUNC_H
#include <string>
#include <algorithm>  
#include <functional> 

namespace mvm
{
	inline std::string mvm_func_get_parent_path(const std::string & str)
	{
		size_t pos = str.rfind(MVM_PATH_DIVIDER);
		return str.substr(0, pos);
	}
	inline void mvm_func_trim_spaces(std::string & str)
	{
		size_t pos = 0;
		while ((pos = str.find(' ', 0))!= std::string::npos)
		{
			str.erase(pos, 1);
		}
	}
	inline void mvm_func_trim_tabs(std::string & str)
	{
		size_t pos = 0;
		while ((pos = str.find('\t', 0)) != std::string::npos)
		{
			str.erase(pos, 1);
		}
	}
	inline void mvm_func_trim_string_left_right(std::string & str)
	{
		std::string::iterator iter = find_if(str.begin(), str.end(), std::not1(std::ptr_fun<int>(::isspace)));
		str.erase(str.begin(), iter);
		std::string::reverse_iterator  rev_iter = find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun<int>(::isspace)));
		str.erase(rev_iter.base(), str.end());
	}
	inline void mvm_func_remove_surplus_spaces(std::string & str)
	{
		std::string result = "";
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] != ' ')
				result.append(1, str[i]);
			else
				if (str[i + 1] != ' ')
					result.append(1, str[i]);
		}
		str.assign(result);
	}
	inline std::string mvm_func_divide(std::string & str)
	{
		size_t pos = 0;
		std::string left;

		pos = str.find(' ');
		if (pos == std::string::npos)
			return str;

		left = str.substr(0, pos);
		str.erase(0,pos+1);

		return left;
	}
	inline void mvm_func_replace(std::string & src, const std::string & str1, const std::string & str2)
	{
		size_t pos = 0;
		size_t size1 = str1.size(), size2 = str2.size();
		while ((pos = src.find(str1, pos)) != std::string::npos)
		{
			src.replace(pos, size1,str2);
			pos += size2;
		}
	}
}

#endif