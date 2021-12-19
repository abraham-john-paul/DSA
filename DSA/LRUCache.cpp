#include "header.h"

struct DLLNode {
    int key;
    int val;
    DLLNode* next;
    DLLNode* prev;
    
    DLLNode(int key, int data) 
        : key{key}, val {data}, 
        next {nullptr},
        prev {nullptr} {}
};

class DLL {
    DLLNode* head;
    DLLNode* tail;

public:
    DLL() {
        head = new DLLNode(-1, -1);
        tail = new DLLNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    DLLNode* getTail() {
        return tail;
    }

    void add(DLLNode* node) {
        if (!node) return;
        
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    DLLNode* remove(DLLNode* node) {
        if (!node) return nullptr;
        if (!node->prev || !node->next) {
            return node;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        return node;
    }
};

class LRUCache {
public:
    unordered_map<int, DLLNode*> mKeyMap;
    DLL mStorage;
    int mCapacity;
    LRUCache(int capacity): mCapacity {capacity} {
        mKeyMap.reserve(mCapacity);
    }
    
    int get(int key) {
        auto itr = mKeyMap.find(key);
        if (itr == mKeyMap.end()) {
            return -1;
        }
        
        auto* node = mStorage.remove(itr->second);
        mStorage.add(node);
        return node->val;
    }
    
    void put(int key, int value) {
        auto itr = mKeyMap.find(key);
        if (itr != mKeyMap.end()) {
            auto* node = mStorage.remove(itr->second);
            node->val = value;
            mStorage.add(node);
            return;
        }
        
        if (mKeyMap.size() == mCapacity) {
            auto* node = mStorage.remove(mStorage.getTail()->prev);
            mKeyMap.erase(node->key);
            delete node;
        }
        auto* node = new DLLNode(key, value);
        mKeyMap.insert({key, node});
        mStorage.add(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */