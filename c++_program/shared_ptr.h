#pragma once

//自定义实现智能指针
template<typename T>
class Cust_shared_ptr {
public:
	Cust_shared_ptr(T* _ptr) :m_ptr(_ptr), m_pcount(new int(1)) {

	};

	Cust_shared_ptr(const Cust_shared_ptr<T>& _shap):m_ptr(_shap.m_ptr),m_pcount(_shap.m_pcount) {
		(*m_pcount)++;
	}

	Cust_shared_ptr<T>& operator=(const Cust_shared_ptr<T>& _shap) {
		if (&_shap != this) {
			(*m_pcount)--;
			if (*(this->m_pcount) == 0) {
				delete m_ptr;
				delete m_pcount;
				m_pcount = nullptr;
				m_ptr = nullptr;
			}
			m_ptr = _shap.m_ptr;
			m_pcount = _shap.m_pcount;
			(*m_pcount)++;
			return *this;
		}
	}

	T& operator*() {
		return *m_ptr;
	}

	T* operator->() {
		return m_ptr;
	}

	~Cust_shared_ptr() {
		--(*m_pcount);
		if((*m_pcount)==0){
			delete m_pcount;
			delete	m_ptr;
			m_pcount = nullptr;
			m_ptr = nullptr;
		}
	}
public:
	T* m_ptr;
	int* m_pcount;
};