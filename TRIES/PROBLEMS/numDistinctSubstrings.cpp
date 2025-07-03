#include <bits/stdc++.h>
using namespace std;
/*
Given a string 'S', you are supposed to return the number of distinct substrings(including
empty substring) of the given string. You should implement the program using a trie.
Note :
A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of,
several characters(possibly none) from the start of ‘A’ and several characters(possibly none)
from the end of ‘A’.
Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’  such that
the character of ‘X’ at index ‘i’ is different from the character of ‘Y’ at index ‘i’
(X[i]!=Y[i]).

‘S’ contains only lowercase English letters.
Sample Input 1 :
2
sds
abc
Sample Output 1 :
6
7
Explanation of Sample Input 1 :
In the first test case, the 6 distinct substrings are { ‘s’,’ d’, ”sd”, ”ds”, ”sds”, “” }
In the second test case, the 7 distinct substrings are {‘a’, ‘b’, ‘c’, “ab”, “bc”, “abc”, “” }.
Sample Input 2 :
2
aa
abab
Sample Output 2 :
3
8
Explanation of Sample Input 2 :
In the first test case, the two distinct substrings are {‘a’, “aa”, “” }.
In the second test case, the seven distinct substrings are {‘a’, ‘b’, “ab”, “ba”, “aba”, “bab”, “abab”, “” }
*/
class Node
{
public:
    Node *link[26];

    bool isPresent(char ch)
    {
        return link[ch - 'a'] != NULL;
    }
    void put(char ch, Node *newNode)
    {
        link[ch - 'a'] = newNode;
    }
    Node *getAddress(char ch)
    {
        return link[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    int ans=0;
    Node*root=new Node;
    for (int i = 0; i < s.size(); i++)
    {
        Node *temp=root;
        for (int j = i; j < s.size(); j++)
        {
         if( !temp->isPresent(s[j]))
         {
           ans++;
           temp->put(s[j],new Node);
         }
         temp=temp->getAddress(s[j]);
        }
    }
    return ans+1;//+1 for empty string counted in ans
}
