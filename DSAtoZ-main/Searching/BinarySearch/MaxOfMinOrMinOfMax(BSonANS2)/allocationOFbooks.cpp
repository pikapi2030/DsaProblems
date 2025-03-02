#include <bits/stdc++.h>
using namespace std;

/*
similar to problem 410 in leetcode

Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number
of pages in the ‘i-th’ book.



There are ‘m’ number of students, and the task is to allocate all the books to the students.



Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.(can't leave any book as well)
3. Book allocation should be in a contiguous manner.
contiguous manner means lagatar, yo cannot allocate
2nd book first and first book after that, the way array has been given
you should allocate books in same order


You have to allocate the book to ‘m’ students such that the maximum
number of pages assigned to a student is minimum.



If the allocation of books is not possible, return -1.



Example:
Input: ‘n’ = 4 ‘m’ = 2
‘arr’ = [12, 34, 67, 90]

Output: 113

Explanation: All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to
student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’,
 so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to
 student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’,
 so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to
 student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’,
  so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.

Hence answer is ‘113’.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4 2
12 34 67 90
Sample Output 1:
113
Explanation of sample input 1:
All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to
student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’,
so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated
 to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’,
 so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to
 student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is
 ‘max(113, 90)= 113’.

We are getting the minimum in the last case.

Hence answer is ‘113’.
Sample Input 2:
5 4
25 46 28 49 24
Sample Output 2:
71
Explanation of sample input 2:
All possible ways to allocate the ‘5’ books to '4' students are:

25 | 46 | 28 | 49 24 - the sum of all the pages of books allocated to
 students 1, 2, 3, and 4 are '25', '46', '28', and '73'. So the maximum is '73'.

25 | 46 | 28 49 | 24 - the sum of all the pages of books allocated to
students 1, 2, 3, and 4 are '25', '46', '77', and '24'. So the maximum is '77'.

25 | 46 28 | 49 | 24 - the sum of all the pages of books allocated to
students 1, 2, 3, and 4 are '25', '74', '49', and '24'. So the maximum is '74'.

25 46 | 28 | 49 | 24 - the sum of all the pages of books allocated to
students 1, 2, 3, and 4 are '71', '28', '49', and '24'. So the maximum is '71'.

We are getting the minimum in the last case.

Hence answer is ‘71’.
Expected time complexity:
The expected time complexity is O(n * log(s)), where ‘n’
 is the number of integers in the array ‘arr’ and ‘s’ is the sum of all the elements of ‘arr’.
Constraints:
2 <= 'n' <= 10 ^ 3
1 <= 'm' <= 10 ^ 3
1 <= 'arr[i]' <= 10 ^ 9
The sum of all arr[i] does not exceed 10 ^ 9.

Where ‘n’ denotes the number of books and ‘m’ denotes the number of students.
 ‘arr[i]’ denotes an element at position ‘i’ in the sequence.


*/

/*BRUTE
what we need to return is the minimum of (max allowed limit a student can have pages(total))
now this limit cannot be less than max of array(the book with max pages)
as this book need to be allocated, if limit is less than max of array, then this book
won't be allocated
so our answer start is max of the array, we can set our ending range to be sum of all
pages, since that is the maximum we can allocate if we have one student only

so now we know range of our ans max of array to sum of array
we wiil do a iterative search us a function which counts how many students are neede
to allocate n book with a particular limit, if number of student come same
as number given to us(input) than we return that particular limit

T.C O((sum-max+1)*N)

*/

int StudentsNeededToAllocate(vector<int> v, int allowedPages)
{
    int studentCount = 1;
    int PagesCurrentlyAllocated = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (PagesCurrentlyAllocated + v[i] <= allowedPages) // limit is our allowedpages
        {
            PagesCurrentlyAllocated += v[i];
        }
        else
        {
            studentCount++;
            PagesCurrentlyAllocated = v[i];
        }
    }
    return studentCount;
}

int BRUTE(vector<int> v, int num_of_students)
{
    int mins = *(max_element(v.begin(), v.end()));
    int sum = accumulate(v.begin(), v.end(), 0); // this calculates total sum of vector, 0 represents initial value
    for (int i = mins; i <= sum; i++)            // i represents possible ans
    {
        if (num_of_students == StudentsNeededToAllocate(v, i))
        {

            return i; // we need min value first possible ans is the ans
        }
    }
    return -1;
}

/*OPTIMAL
we know the range of the ans, so we use BS

T.C O((log_2 sum-max+1)*N)
*/

int opti(vector<int> v, int Num_of_students)
{
    if(Num_of_students>v.size())//num of books=v.size()
    {
    return -1;//each stundent can't get a book, voilatinf first rule
    }
    long long low = *(max_element(v.begin(), v.end()));
    long long high = accumulate(v.begin(), v.end(), 0); // sum
    while (high >= low)
    {
        long long mid = (low + high) / 2;
        if (StudentsNeededToAllocate(v, mid) <= Num_of_students) /*we need same amount, but there
              might be a limit lower than as an ans,
              or if students needed are less than we have, we might be giving too many pages
              per student(limit is too high)
              */
        {
            high = mid - 1;
        }
        else//too less limit as students needed are more than usual so increas limit
        {
            low = mid + 1;
        }
    }
    return (int)low;
    /*
    at start low was at values where more students were needed(than given), 
    high at values where less students are needed(than given) we can say high was pointing to
    somewhat possible cases, low at not poosible cases so polarity reversed 
    */
    

}

int main()
{
    vector<int> v = {25, 46, 28, 49, 24};
    cout << opti(v, 4);
}
