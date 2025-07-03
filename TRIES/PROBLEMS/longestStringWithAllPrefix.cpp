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
                Node *newNode = new Node;
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

    bool isComplete(string word)//!new function
    {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->isPresent(word[i]))
            {
                return false;
            }
            temp=temp->getAddress(word[i]);
            if(!temp->isEnd())
            {
                return false;
            }
        }
        return true;
    }

};

/*
Ninja developed a love for arrays and strings so this time his teacher gave him an array of
strings, ‘A’ of size ‘N’. Each element of this array is a string. The teacher taught Ninja about prefixes in the past, so he wants to test his knowledge.
A string is called a complete string if every prefix of this string is also present in the
array ‘A’. Ninja is challenged to find the longest complete string in the array ‘A’.
If there are multiple strings with the same length, return the lexicographically smallest
one and if no string exists, return "None".
Note :
Example :

N = 4
A = [ “ab” , “abc” , “a” , “bp” ]

Explanation :

Only prefix of the string “a” is “a” which is present in array ‘A’. So, it is one of the
possible strings.
Prefixes of the string “ab” are “a” and “ab” both of which are present in array ‘A’. So,
it is one of the possible strings.
Prefixes of the string “bp” are “b” and “bp”. “b” is not present in array ‘A’. So, it
cannot be a valid string.
Prefixes of the string “abc” are “a”,“ab” and “abc” all of which are present in array ‘A’.
So, it is one of the possible strings.
We need to find the maximum length string, so “abc” is the required string.

*/
/*approach
store all strings in arr in a trie
now check for every string example abc, check if a is present as a word then ab is present as
a word
to do this simply check if word[i] exists and it is also an  end( flag=true ) to confirm
that the word exists and not a suffix

*/

string completeString(vector<string> &nums)
{
    trie tr;
    for(auto it:nums)
    {
        tr.insert(it);
    }
    string ans="";
    for(auto it:nums)
    {
      if(tr.isComplete(it))
      {
        if( it.size()>ans.size() )
        {
            ans=it;
        }
        else if( it.size()==ans.size() )
        {
            if( it<ans )//lexographycally smaller
            {
                ans=it;
            }
        }
      }
    }
    if(ans=="")
    {
        return "None";
    }
    return ans;
}
