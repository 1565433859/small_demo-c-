#include<iostream>
#include"global.h"
#include"shared_ptr.h"
using namespace std;

class tmp {
public:
	void test() {
		cout << m_val << endl;
	}

	int m_val;
};


int main() {
	Cust_shared_ptr<tmp>p1(new tmp);
	p1->m_val = 10;
	p1->test();
	Cust_shared_ptr<tmp>p2(p1);
	cout << *(p1.m_pcount) << endl;
	cout << *(p2.m_pcount) << endl;
	Cust_shared_ptr<tmp>p3(new tmp);
	p3->m_val = 20;
	p2 = p3;
	p1 = p3;
	p1->test();
	cout << *(p1.m_pcount) << endl;
	return 0;
}