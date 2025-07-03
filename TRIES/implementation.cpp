#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *link[26];
    bool flag = false;
    bool isPresent(char ch)
    {
        return link[ch - 'a'] != NULL;
    }
    void put(char ch, Node *newNode)
    {
        link[ch - 'a'] = newNode;
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
    Node *getAddress(char ch)
    {
        return link[ch - 'a'];
    }
};

class trie
{
public:
    Node *root;

    trie()
    {
        root = new Node;
    }
    void insert(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!(temp->isPresent(word[i])))
            {
                Node *newNode=new Node;
                temp->put(word[i], newNode);
            }
            temp = temp->getAddress(word[i]); // move to next node
        }
        temp->setEnd();
    }

    bool isWordPresent(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!temp->isPresent(word[i]))
            {
                return false;
            }
            temp = temp->getAddress(word[i]);
        }
        return temp->isEnd(); // flag indicates end of the word,it is possible that word does not ecist but word as suffix does, giving us false positive
    }

    bool isSuffixPresent(string suffix)
    {
        Node *temp = root;
        for (int i = 0; i < suffix.length(); i++)
        {
            if (!temp->isPresent(suffix[i]))
            {
                return false;
            }
            temp = temp->getAddress(suffix[i]);
        }
        return true;
    }
};
