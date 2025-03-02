#include<iostream>
#include<string>

using namespace std;

/*
character hashing is couting freq of character in a string and stroing it in a hash array
with 0th index  as a's freq, 1th index as b's freq and so on;
*/
/*
character hashing of string with lower case letters

*/
/*
int main()
{  cout<<"ENTER STRING:";
    string s;
    cin>>s;
/*lets assume our string has lower case letters 
so we make hash array size of 26(26 letter and a is considered at 0th index)


int hash[26]={0};
//pre-storing
for(int i=0;i<s.size();i++)
{
hash[s[i]-'a']++;//a is subtracted to make a's freq stored a 0th index, b's freq at 1th index...
}
//fetching
int q;//q stands for number of queries
cout<<"ENTER NUM OF QUERIES:";
cin>>q;
while(q--)
{
    char c;//the num you need freq of
    cout<<"ENTER THE char:";
    cin>>c;
    cout<<hash[c-'a']<<endl;
}
}
/*TO DO CHARACTER HASHING OF A STRING WITH LOWER AND UPPERCASE LETTERS 
MAKE HASH SIZE 256

*/
//CHARACTER HASHING OF STRING CONTAING LOWER AND UPPERCASE LETTERS
int main()
{  cout<<"ENTER STRING:";
    string s;
    cin>>s;
/*
 we make hash array size of 256
*/
int hash[256]={0};
//pre-storing
for(int i=0;i<s.size();i++)
{
hash[s[i]]++;//a is subtracted to make a's freq stored a 0th index, b's freq at 1th index...
}
//fetching
int q;//q stands for number of queries
cout<<"ENTER NUM OF QUERIES:";
cin>>q;
while(q--)
{
    char c;//the num you need freq of
    cout<<"ENTER THE char:";
    cin>>c;
    cout<<hash[c]<<endl;
}
}




