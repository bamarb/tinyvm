#ifndef TVM_MEMORY_H_
#define TVM_MEMORY_H_

#include <stdlib.h>

#define BYTE int8_t
#define WORD int32_t
#define DBYTE int16_t
#define DWORD int64_t

typedef union
{
	WORD i32;

	union
	{
		DBYTE h;
		DBYTE l;
	} i16;

} tvm_register;

typedef struct
{

	/*
	Similar to x86 FLAGS register

	0x1	EQUAL
	0x2	GREATER

	*/

	unsigned int FLAGS;
	int remainder;

	void* mem_space;
	int mem_space_size;

	tvm_register* registers;

} memory;

memory* create_memory(size_t size);
void destroy_memory(memory* mem);

#endif