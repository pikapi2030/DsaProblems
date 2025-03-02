#include <iostream>
#include <vector>
using namespace std;
/*
merge sort hypothetically breaks down array from midlle and keeps breaking it down until only one
element is left then merges the all pieces in a sorted manner
it breaks by using recursion

time complexity-
O(N*log_2(N))
N*log base 2 N
 space complexity - O(N)

*/

void printv(vector<int> a)
{
  for (auto it = a.begin(); it != a.end(); it++)
  {
    cout << *(it) << " ";
  }
  cout << endl;
}

void merge(vector<int> &v, int low, int mid, int high)
{
  vector<int> temp;
  int left = low;
  int right = mid + 1;

  while (left <= mid && right <= high)
  {
    if (v[left] <= v[right])
    {
      temp.push_back(v[left]);
      left++;
    }
    else
    {
      temp.push_back(v[right]);
      right++;
    }
  }
  while (left <= mid)
  {
    temp.push_back(v[left]);
    left++;
  }
  while (right <= high)
  {
    temp.push_back(v[right]);
    right++;
  }

  for (int i = low; i <= high; i++)
  {
    v[i] = temp[i - low]; // this is the line where our sorted orignal array forms
  }
}

void mergesort(vector<int> &v, int low, int high)
{
  int mid = (high + low) / 2;
  if (low >= high)
  {
    return;
  }
  mergesort(v, low, mid);
  mergesort(v, mid + 1, high);
  merge(v, low, mid, high);
}

int main()
{
  vector<int> v = {6, 99, 4, 5, 2, 42, 4, 2, -4, 0, -6};
  mergesort(v, 0, v.size() - 1);
  printv(v);
}
