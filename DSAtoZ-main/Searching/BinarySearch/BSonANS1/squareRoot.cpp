/*
calulate square root of an intger
return floor value
*/

/*BRUTE
using a for loop
*/

int brute(int n)
{
    int ans = 0;
    // linear search on the answer space:
    for (long long i = 1; i <= n; i++)
    {
        long long val = i * i;
        if (val <= n * 1ll)//*1ll means multiplying with 1 where 1 is of lon long data type
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}

/*opti using BS
since lowest poosible ans for square root of any number is 1 
we will take low as 0 anf high as n
we calculate mid and if n>= mid*mid then we store it in our ans value
and eliminate left search space(asw we need maximum mid to be less thanor equal n)
if mid*mid>n, we eliminate right search space

// WE CAN ALSO RETURN HIGH AS IT WILL ALWAYS END ON RIGH ANSWER

*/

int opti(int n)
{
        long long  ans=0;//min possible ans
long long  low=0,high=n;
while(high>=low)
{
    long long  mid=(low+high)/2;
    if(n>=mid*mid)//we can also do n/mid>=mid(to prevent overflow)
    {
     ans=mid;
     low=mid+1;
    }
    else
    {
        high=mid-1;
    }
}
return (int)ans;

}
