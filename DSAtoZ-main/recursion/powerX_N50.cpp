#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, long long n) 
    {
        
        bool xsign=true;
        bool nsign=true;
        if( x<0&&n%2!=0 )
        {
            xsign=false;
        }
        if(n<0)
        {
            nsign=false;
        }
        x=abs(x);
        n=abs(n);
         double ans=1;
        while( n!=0 )
        {
            if(n%2!=0)
            {
                n--;
                ans=ans*x;
            }
            n=n/2;
            x=x*x;
        }
    
        if(!xsign)
        {
            ans=-ans;
        }
        if(!nsign)
        {
            ans=1.0/ans;
        }
        return (double)ans;
    }
};