#pragma once
#include<unordered_map>
using namespace std;

typedef struct Node {
	int key;
	int value;
	Node* pre;
	Node* next;
	Node(int _key, int _value) :key(_key), value(_value), pre(nullptr), next(nullptr) {};
}Node;

class LRU_cache {
public:
	LRU_cache(int _capacity) :size(0), capacity(_capacity) {
		head = new Node(0, 0);
		tail = new Node(0, 0);
		head->next = tail;
		tail->pre = head;
	}

	int get(int key) {
		if (node_map.find(key) != node_map.end()) {
			Node* tmp = node_map[key];
			del_node(tmp);
			add_node(tmp);
			return tmp->value;
		}
		else {
			return -1;
		}
	}

	void put(int key, int value) {
		if (node_map.find(key) != node_map.end()) {
			Node* tmp = node_map[key];
			del_node(tmp);
			add_node(tmp);
			tmp->value = value;
		}
		else {
			if (capacity == size) {
				Node* tmp = tail->pre;
				del_node(tmp);
				node_map.erase(tmp->key);
				delete tmp;
				size--;
			}
			Node* tmp = new Node(key, value);
			add_node(tmp);
			node_map[key] = tmp;
			size++;
		}
	}

	void add_node(Node* node) {
		head->next->pre = node;
		node->next = head->next;
		head->next = node;
		node->pre = head;
	}

	void del_node(Node* node) {
		node->next->pre = node->pre;
		node->pre->next = node->next;
	}

private:
	unordered_map<int, Node*>node_map;
	Node* tail;
	Node* head;
	int capacity;
	int size;
};