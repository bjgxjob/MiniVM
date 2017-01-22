#ifndef _MVM_REGISTER_H
#define _MVM_REGISTER_H

#include <stdlib.h>
#include <stdint.h>
#include <vector>

#include "mvm_memory.h"

namespace mvm
{
	struct mvm_register_block
	{
		mvm_mem_block data;
		bool is_eax;
		bool is_ebx;
		bool is_ecx;
		bool is_edx;
		bool is_esp;
		bool is_ebp;
		bool is_esi;
		bool is_edi;
		bool is_eflags;
		bool is_tsc;
		bool is_eip;
		bool is_seg;
	};

}


#endif