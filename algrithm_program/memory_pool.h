#pragma once

class Memory_pool {
public:

	static void* operator new(size_t size);
	static void operator delete(void* phead);

private:
	struct obj_p {
		obj_p* next;
	};
;
	static obj_p* free_pos;
	static int m_Cout;
	int m_a;
	int m_b;
	
};