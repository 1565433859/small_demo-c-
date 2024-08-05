#include<iostream>
#include<queue>
#include<functional>
#include<time.h>
#include"global.h"
#include"CLur_cache.h"
#include"sort.h"
#include"func2.h"
#include"huawei1.h"
#include"memory_pool.h"
using namespace std;

char* test() {
	char* str = "hello";
	return str;
}

template<typename F,typename T,typename E>
void forward(F f, T&& a, E b) {
	f(a, b);
}

void func1(int a, int b) {
	cout << "func1������"<<endl;
	a++;
}

void func2(int& a, int b) {
	cout << "func2������" << endl;
	a++;
}

class A {
public:

	A() {};
	A(int _v1, int _v2) :m_v1(_v1), m_v2(_v2) {
		cout << "���캯������" << endl;
	};

	A(const A& a){
		m_v1 = a.m_v1;
		m_v2 = a.m_v2;
		cout << "�������캯��������" << endl;
	};

	A& operator=(const A& a) {
		if (this == &a)return *this;
		m_v1 = a.m_v1;
		m_v2 = a.m_v2;
		cout << "�����������㱻����" << endl;
	}
	A(const A&& a) {
		m_v1 = a.m_v1;
		m_v2 = a.m_v2;
		cout << "�ƶ�����������" << endl;
	};

	A& operator=(const A&& a) {
		if (this == &a)return *this;
		m_v1 = a.m_v1;
		m_v2 = a.m_v2;
		cout << "�ƶ��������㱻����" << endl;
	}


	~A() {
		cout << "��������������" << endl;
	}
	int m_v1;
	int m_v2;
};

A test_a() {
	A a(10, 20);
	return a;
}

int main() {
	time_t start, end;
	start = clock();
	//Memory_pool* tmp = new Memory_pool;
	Memory_pool* ptmp[5];
	for (int i = 0; i < 5; i++) {
		ptmp[i] = new Memory_pool;
		cout << ptmp[i] << endl;
	}
	end = clock();
	cout << "��������ʱ��Ϊ" << end - start;
}