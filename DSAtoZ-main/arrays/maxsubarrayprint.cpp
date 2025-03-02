#include<bits/stdc++.h>
using namespace std;
/*
give start and end indexes of sub array with maximum sum
*/

//this is a follow up up quetion of kadane's algo
// we will slightly modify kadane's algo

/*
T.C O(n)
S.C O(1)
*/
void printv(vector <int>a)
{
    for( auto it=a.begin();it!=a.end();it++  )
{
    cout<<*(it)<<" ";
    
}
cout<<endl;

}


vector<int> KAD( vector<int>v)
{

int sum=0,maxs=INT_MIN;
int start=0;
int anstart=-1,ansend=-1;

for(int i=0;i<v.size();i++)
{
    if(sum<0)
{
    sum=0;
    start=i;//any sub array starts when sum becomes =0
}

sum=sum+v[i];
if(sum>maxs)
{
    maxs=sum;
    anstart=start;
    ansend=i;//keep updating i if max is updated
}
}
return {anstart,ansend};
}
int main()
{
     vector<int>v={ 4,5,-26,-89,-1 };
     printv(KAD(v));
}
