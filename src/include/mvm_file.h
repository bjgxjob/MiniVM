#ifndef _MVM_FILE_H
#define _MVM_FILE_H

#include <string>
#include <stdio.h>

namespace mvm
{
	class mvm_file
	{
	public:
		bool open(const std::string);
		bool read(std::string &);
		void close();
	public:
		size_t length = 0;
	private:
		FILE  *filp = { 0 };
	};
}
#endif