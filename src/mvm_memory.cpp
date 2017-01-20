#include "include\mvm_memory.h"

mvm::mvm_memory::mvm_memory()
{
	mem = nullptr;
}

mvm::mvm_memory::~mvm_memory()
{
	free();
}

bool mvm::mvm_memory::alloc(size_t size)
{
	if (mem) free();
	mem = (uint32_t *)calloc(size,sizeof uint32_t);
	return mem ? m_size = size, true : m_size = 0, false;
}

void mvm::mvm_memory::free()
{
	if (mem) ::free(mem),m_size = 0;
}

uint32_t mvm::mvm_memory::at(size_t pos)
{
	if (pos >= m_size)
		return 0;
	return mem[pos];
}
