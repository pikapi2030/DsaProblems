class Solution {
public:

    long long myPow(long long x, long long n) 
    {
        long long mod=1e9+7;
        long long ans=1;
        while( n!=0 )
        {
            if(n%2!=0)
            {
                n--;
                ans=(ans*x)%mod;
            }
            n=n/2;
            x=(x*x)%mod;
        }
    
        return ans;
    }

    int countGoodNumbers(long long n) 
    {
        long long mod=1e9+7;

        if( n&1 )//n is odd
        {
            long long ans= ((myPow(5,(n+1)/2))*(myPow(4,n/2)))%mod;
            return (int)ans;  
        }
        else//n is even
        {
            long long ans= ((myPow(5,n/2))*(myPow(4,n/2)))%mod;
            return (int)ans;
        }



    }
};