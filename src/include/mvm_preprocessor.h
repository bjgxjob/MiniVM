#ifndef _MVM_PREPROCESSOR_H
#define _MVM_PREPROCESSOR_H

#include "mvm_token.h"
#include "mvm_func.h"
#include "mvm_file.h"
#include <string>

namespace mvm
{
	class mvm_preprocessor
	{
	public:
		mvm_preprocessor(std::string path) :tmp(""), include_tmp(""), beg_pos(0), end_pos(0) ,file_path(path){};
	public:
		void preprocess(std::string &);
	public:
		size_t beg_pos, end_pos;
	private:
		bool parse_include(std::string &);
		bool parse_define (std::string &);
	private:
		std::string tmp;
		std::string include_tmp;
		std::string file_path;
	};
	
}
#endif
