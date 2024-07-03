#include "memory_pool.h"

int Memory_pool::m_Cout=5;
Memory_pool::obj_p* Memory_pool::free_pos=nullptr;

void* Memory_pool::operator new(size_t size)
{
    if (free_pos == nullptr) {
        Memory_pool* tmp = (Memory_pool*)new char[sizeof(Memory_pool) * m_Cout];
        free_pos = (obj_p *)tmp;
        for (int i = 0; i < m_Cout-1; i++) {
            ((obj_p*)tmp)->next = (obj_p*)(tmp + 1);
            tmp = tmp+1;
        }
        ((obj_p*)tmp)->next = nullptr;
    }
    Memory_pool* tmp = (Memory_pool *)free_pos;
    free_pos = free_pos->next;
    return tmp;
}

void Memory_pool::operator delete(void* phead)
{
    ((obj_p*)phead)->next=free_pos;
    free_pos = (obj_p*)phead;
}
