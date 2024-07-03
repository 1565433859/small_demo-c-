#pragma once
#include<vector>
#include<random>
using namespace std;
namespace skiplist1 {
    struct Node {
    public:
        int value;
        vector<Node*> next;
        int level;
        Node() {};

        Node(int val, int lv) : value(val), level(lv), next({ nullptr }) {
            next.resize(level);
        };
    };

    class Skiplist {
    public:
        Skiplist() :cur_level(0), max_level(30), gen(rd()),dis(0,1){
            head = new Node(0, 30);
            head->next.resize(max_level, nullptr);
        }

        bool search(int target) {
            Node* p = head;
            for (int i = cur_level - 1; i >= 0; i--) {
                while (p->next[i] != nullptr && p->next[i]->value < target)p = p->next[i];
            }
            if (p->next[0] == nullptr || p->next[0]->value > target)return false;
            return true;
        }

        void add(int num) {
            int level = randomLevel();
            if (level > cur_level)cur_level = level;
            Node* tmp = new Node(num, level);
            vector<Node*>update(cur_level, nullptr);
            Node* p = head;
            for (int i = level - 1; i >= 0; i--) {
                while (p->next[i] != nullptr && num > p->next[i]->value)p = p->next[i];
                update[i] = p;
            }
            for (int i = level - 1; i >= 0; i--) {
                tmp->next[i] = update[i]->next[i];
                update[i]->next[i] = tmp;
            }
        }

        bool erase(int num) {
            vector<Node*>update(cur_level, nullptr);
            Node* p = head;
            for (int i = cur_level - 1; i >= 0; i--) {
                while (p->next[i] != nullptr && num > p->next[i]->value)p = p->next[i];
                update[i] = p;
            }
            p = p->next[0];
            if (p == nullptr || p->value != num)return false;
            for (int i =0; i < cur_level; i++) {
                if (update[i]->next[i] != p) {
                    break;
                }
                update[i]->next[i] = p->next[i];
            }
            delete p;
            return true;
        }

        int randomLevel() {
            int level = 1;
            while (dis(gen) <= prob && level < max_level) {
                level++;
            }
            return level;
        }

    private:
        int cur_level;
        int max_level;
        Node* head;
        std::random_device rd;
        mt19937_64 gen;
        uniform_real_distribution<double> dis;
        double prob = 0.25;
    };
}