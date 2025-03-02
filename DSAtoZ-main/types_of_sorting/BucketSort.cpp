#include <bits/stdc++.h>
using namespace std;

void PrintArray(float v[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << " " << v[i] << " ";
  }
}

/*
this is used to sort floating point numbers ranging between 0 and 1
*/

void BucketSort(float v[], int size)

{
  vector<vector<float>> bucket(size, vector<float>()); // 2d array with row=size
  //! we can set number of bukets to 10 but keeping number of buckets equal to number of rows help in more uniform distribution thus better time complexcity
 
  for (int i = 0; i < size; i++)
  {
    int index = v[i] * size; //! number of buckets is equal to size (and not 10)
    bucket[index].push_back(v[i]);
  }
  // sorting each indivisual bucket
  for (int i = 0; i < size; i++)
  {
    sort(bucket[i].begin(), bucket[i].end());
  }
  // concatente all buckets
  int index = 0;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < bucket[i].size(); j++)
    {
      v[index] = bucket[i][j];
      index++;
    }
  }
}

int main()
{
  float v[] = {0.02, 0.132, 0.5, 0.3, 0.14, 0.2343, 0.22, 0.23};
  BucketSort(v, 8);
  PrintArray(v, 8);
}
