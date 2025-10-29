#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    int key;
    node *next;
    node *prev;

    node(int k, int v)
    {
        val = v;
        key = k;
        next = NULL;
        prev = NULL;
    }
};

node *insertAfterHead(node *head, int key, int value) // returns pointer adressing to newNode
{
    node *nodeAfterHead = head->next;
    node *newNode = new node(key, value);

    head->next = newNode;
    newNode->prev = head;

    newNode->next = nodeAfterHead;
    nodeAfterHead->prev = newNode;
    return newNode;
}

int deleteBeforeTail(node *tail) // returns key of deleted node
{
    node *del = tail->prev;
    int keyOfdeleting = del->key;
    node *nodeBeforeDeletingNode = del->prev;
    tail->prev = nodeBeforeDeletingNode;
    nodeBeforeDeletingNode->next = tail;
    delete del;
    return keyOfdeleting;
}

void moveNodeAfterHead(node *head, node *cur)
{
    if (head->next == cur)
    {
        return;
    }
    node *nextTohead = head->next;
    node *nextTocur = cur->next;
    node *prevTocur = cur->prev;

    nextTocur->prev = prevTocur;
    prevTocur->next = nextTocur;

    head->next = cur;
    cur->prev = head;

    cur->next = nextTohead;
    nextTohead->prev = cur;
}

class LRUCache
{
public:
    int cap;
    node *head;
    node *tail;
    unordered_map<int, node *> mp;

    LRUCache(int capacity)
    {
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        node *cur = mp[key];
        moveNodeAfterHead(head, cur);
        return cur->val;
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end()) // does not exist, therefore insert after checking size
        {
            if (mp.size() == cap) // cache full
            {
                int keyOfDeleted = deleteBeforeTail(tail);
                mp.erase(keyOfDeleted); // erased from map
            }
            mp[key] = insertAfterHead(head, key, value);
        }
        else
        {
            node *cur = mp[key];
            cur->val = value; // updated
            moveNodeAfterHead(head, cur);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */