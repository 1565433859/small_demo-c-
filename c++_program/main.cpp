#include<iostream>
#include<semaphore>
#include<mutex>
#include<thread>
#include"LRU_cache.h"
#include"global.h"
#include"shared_ptr.h"
#include"skip_list.h"
using namespace std;
using namespace skiplist1;
class tmp {
public:
	tmp() {};
	tmp(const tmp& t):m_val(t.m_val) {
		cout << "拷贝构造函数被调用" << endl;
	}
	tmp& operator=(const tmp& t) {
		cout << "拷贝复制运算符被调用" << endl;
		if (this == &t)return *this;
		m_val = t.m_val;
		return *this;
	}

private:
	int m_val;
};

namespace virtual_test {
	class Base {
		virtual void f() {
			cout << "Base f()" << endl;
		}

		virtual void g() {
			cout << "Base g()" << endl;
		}
	};

	class Derive : public Base {
	};

	void test() {
		Base b;
		long long* tmp = (long long*)(&b);
		long long* pvptr = (long long*)(*tmp); //0x00007ff6714ebd78
		for (int i = 0; i < 4; i++) {
			printf("vptr[%d]=0x%p\n", i, pvptr[i]);
		}
		printf("----------------------\n");
		Derive d;
		long long* tmp2 = (long long*)(&d);
		long long* pvptr2 = (long long*)(*tmp2);//0x00007ff6714ebdb8
		for (int i = 0; i < 4; i++) {
			printf("vptr[%d]=0x%p\n", i, pvptr2[i]);
		}
		Derive d2;
		long long* tmp3 = (long long*)(&d2);
		long long* pvptr3 = (long long*)(*tmp3); //0x00007ff6714ebdb8
		for (int i = 0; i < 4; i++) {
			printf("vptr[%d]=0x%p\n", i, pvptr3[i]);
		}
	}
}

counting_semaphore sm_A(1);
counting_semaphore sm_B(0);
mutex mutex1;
int g_count = 0;
void printA() {
	while (g_count<99) {
		/*sm_A.acquire();
		cout << "A" <<g_count<< endl;
		g_count++;
		sm_B.release(1);*/
		if (g_count % 2 != 0)continue;
		mutex1.lock();
		cout << "A" << g_count << endl;
		g_count++;
		mutex1.unlock();
	}
}

void printB() {
	while (g_count < 99) {
		if (g_count % 2 != 1)continue;
		mutex1.lock();
		cout << "B" << g_count << endl;
		g_count++;
		mutex1.unlock();
	}
}

int main() {
	thread t1(printA);
	thread t2(printB);
	t1.join();
	t2.join();
	cout << "test" << endl;
	return 0;
}
