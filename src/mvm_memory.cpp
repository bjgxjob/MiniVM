#include "include\mvm_memory.h"

mvm::mvm_memory::mvm_memory(size_t count) { mem.reserve(count); }

mvm::mvm_memory::~mvm_memory() { mem.~vector(); }

mvm::mvm_mem_block & mvm::mvm_memory::at(size_t pos)
{
	return mem.at(pos);
}
