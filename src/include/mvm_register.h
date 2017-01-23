#ifndef _MVM_REGISTER_H
#define _MVM_REGISTER_H

#include <stdlib.h>
#include <stdint.h>
#include <map>

#include "mvm_memory.h"

namespace mvm
{
	enum class mvm_register_type : unsigned short
	{

	};
	struct mvm_register_block
	{
		union mvm_mem_block
		{
			union sign_value
			{
				int32_t i32;
				uint32_t ui32;
			};
			struct
			{
				int16_t l16;
				int16_t h16;
			} i16;
			struct
			{
				int8_t ll8;
				int8_t l8;
				int8_t h8;
				int8_t hh8;
			};
		} value = { 0 };
		mvm_register_type type;
	};

}


#endif