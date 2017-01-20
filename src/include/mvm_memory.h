#ifndef _MVM_MEMORY_H
#define _MVM_MEMORY_H

#include <stdlib.h>
#include <stdint.h>

namespace mvm
{
	class mvm_memory
	{
	public:
		mvm_memory();
		~mvm_memory();
		bool alloc(size_t);
		void free();
		uint32_t at(size_t);
	private:
		uint32_t * mem;
		size_t m_size = 0;
	};
}


#endif