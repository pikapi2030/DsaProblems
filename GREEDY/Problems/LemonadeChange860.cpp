#include <bits/stdc++.h>
using namespace std;
/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy
from you and order one at a time (in the order specified by bills).
Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.
You must provide the correct change to each customer so that the net transaction is
that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays,
return true if you can provide every customer with the correct change, or false otherwise.



Example 1:

Input: bills = [5,5,5,10,20]
Output: true
Explanation:
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.

Example 2:

Input: bills = [5,5,10,10,20]
Output: false
Explanation:
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can not give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.
*/

/*aproach(greedy)
we will keep two cnt variables keeping count of 5 and 10  dollar bills we have
//! best strategy to give change is to use largest dollar bill first than a smaller bill
as smaller bills are more flexible, so must be used when no other option is left
20$ bill is useless as we can't pay any change with it so no point in keeping count

it's like i have tier 2 and teir 4 bullets in AB, i will kill scavs with tier2 bullets
so that i can kill operators with tier 4 bullets, even though t4 bullets can kill scavs as well
*/

bool lemonadeChange(vector<int> &bills)
{
    int cnt5 = 0;
    int cnt10 = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            cnt5++;
        }
        else if (bills[i] == 10)
        {
            if (cnt5 != 0)
            {
                cnt5--;
                cnt10++;
            }
            else
            {
                return false;
            } // cant give change
        }
        else if (bills[i] == 20)
        {
            if (cnt5 == 0||(cnt5<3&&cnt10==0))
            {
                return false;
            }
            if(cnt10==0)
            {
                cnt5=cnt5-3;
                
            }
            else if(cnt10!=0&&cnt5!=0)
            {
                cnt10--;
                cnt5--;
            }

            
        }
    }
    return true;
}
