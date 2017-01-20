#include "include\mvm_file.h"

using std::string;

using mvm::mvm_file;


bool mvm_file::open(const string filename)
{
	filp = fopen(filename.c_str(), "r");
	return (filp != nullptr) ? true : false;
}

bool mvm_file::read(string & str)
{
	str.erase();
	if (filp != nullptr)
	{
		while (!feof(filp))
		{
			str.push_back(fgetc(filp));
		}
		fseek(filp, 0, SEEK_SET);
		return true;
	}
	return false;
}

void mvm::mvm_file::close()
{
	if (filp)
		fclose(filp);
	length = 0;
}