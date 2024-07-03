#pragma once
#include<unordered_map>

using namespace std;
typedef struct Node {
	int key;
	int value;
	Node* next;
	Node* pre;
	Node(int _key, int _value):next(nullptr),pre(nullptr) {
		key = _key;
		value = _value;
	}
}Node;


class LRUCache {
public:
	LRUCache(int _size = 0);

	~LRUCache();

	int get(int key);

	void put(int key, int value);

	Node* remove(Node* node);

	void add(Node *node);
private:
	unordered_map<int, Node*>m_map;
	Node* head;
	Node* tail;
	int capacity;
	int size;
};