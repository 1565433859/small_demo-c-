#include"CLur_cache.h"

LRUCache::LRUCache(int _capa) :size(),capacity(_capa) {
	head = new Node(0,0);
	tail = new Node(0, 0);
	head->next = tail;
	tail->pre = head;
}

LRUCache::~LRUCache() {
	Node* p = head->next;
	while (p != tail) {
		Node* tmp = p->next;
		delete p;
		p = tmp;
	}
}

int LRUCache::get(int key) {
	if (m_map.count(key) != 0) {
		Node* node = remove(m_map[key]);
		add(node);
		return m_map[key]->value;
	}
	return -1;
}

void LRUCache::put(int key, int value){
	if (m_map.count(key) == 1) {
		remove(m_map[key]);
		Node* node = new Node(key, value);
		add(node);
		m_map[key] = node;
	}
	else {
		if (size == capacity) {
			m_map.erase(tail->pre->key);
			remove(tail->pre);
		}
		Node* new_node = new Node(key, value);
		add(new_node);
		m_map[key] = new_node;
	}
}

Node* LRUCache::remove(Node *node)
{
	node->pre->next = node->next;
	node->next->pre = node->pre;
	size--;
	return node;
}

void LRUCache::add(Node* node)
{
	node->pre = head;
	node->next = head->next;
	head->next = node;
	node->next->pre = node;
	size++;
}
