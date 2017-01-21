#ifndef _MVM_MEMORY_H
#define _MVM_MEMORY_H

#include <stdlib.h>
#include <stdint.h>
#include <vector>

namespace mvm
{
	union mvm_mem_block
	{
		int32_t i32;
		struct 
		{
			int16_t l16;
			int16_t h16;
		} i16;
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