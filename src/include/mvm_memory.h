#ifndef _MVM_MEMORY_H
#define _MVM_MEMORY_H

#include <stdlib.h>
#include <stdint.h>
#include <vector>

namespace mvm
{
	struct mvm_mem_block
	{
		int8_t i8 = 0;
	};
	class mvm_memory
	{
	public:
		mvm_memory(size_t);
		~mvm_memory();
		mvm_mem_block & at(size_t);
	private:
		std::vector<mvm_mem_block> mem;
	};
}


#endif