#include "include\mvm_memory.h"

mvm::mvm_memory::mvm_memory(){}

mvm::mvm_memory::~mvm_memory() { mem.~vector(); }

void mvm::mvm_memory::alloc(size_t size)
{
	mem.resize(size);
}

mvm::mvm_mem_block & mvm::mvm_memory::at(size_t pos)
{
	return mem.at(pos);
}
