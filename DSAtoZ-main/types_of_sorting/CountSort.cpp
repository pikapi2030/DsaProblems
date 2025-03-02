#include <bits/stdc++.h>
using namespace std;


void PrintArray(int v[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<" "<<v[i]<<" ";
    }
}

int MaxElement(int v[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    return max;
}

void CountSort(int v[], int n)
{
    int MaxEl = MaxElement(v, n);
    int hash[MaxEl + 1]={};//!INITIALIZATION to zero
    for (int i = 0; i < n; i++)
    {
        hash[v[i]]++;
    }

    int sum = 0;

    for (int i = 0; i < MaxEl + 1; i++)
    {
        sum = sum + hash[i];
        hash[i]=sum;
    }
    int ans[n];
    for(int i=0;i<n;i++)
    {
      int index=hash[v[i]]-1;
      ans[index]=v[i];
      hash[v[i]]--; 
    }
    //COPY LOOP
    for(int i=0;i<n;i++)
    {
        v[i]=ans[i];
    }
}

int main()
{
    int n=6;
    int v[6]={4,9876,234,654,234,734};
    CountSort(v,n);
    PrintArray(v,n);

}
