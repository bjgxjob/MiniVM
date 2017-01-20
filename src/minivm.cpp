#include <iostream>

#include "include\mvm.h"

using namespace mvm;
using std::cout;
using std::endl;

int main(int argc,char **argv)
{
	cout.sync_with_stdio(false);
	if (argc == 2)
	{
		mvm_file file;
		std::string str;
		bool ret;
		ret = file.open(argv[1]);
		if (!ret)
		{
			cout << "open fail" << endl;
			return 1;
		}
		ret = file.read(str);
		if (!ret)
		{
			cout << "read fail" << endl;
			return 1;
		}
		
		mvm_preprocessor preprocessor(argv[1]);
		preprocessor.preprocess(str);
		cout.write(str.c_str(),str.size());
		file.close();
	}
	else
	{
		cout << "error args" << endl;
	}
}