/* Chef has a useless clock which does not run properly. More specifically, it runs at K times the rate of a correct clock, where K≠1. It may even be that K is negative, which means the clock runs backwards. Chef also has a clock which precisely shows the current time without error.

At 12 am on day 1
Chef sets the useless clock to point to 12:00. Of course Chef's correct clock already points to 12:00. Chef wonders on which day the time shown by the useless clock will coincide with the correct clock for the Nth

time.

Can you help him find the answer without having to wait for that many days?
Note that 12 am of day d
is considered the first instant of day d. Since the clocks initially show the same time at 12 am of day 1

, that is counted as the first time they coincide.
Input:

    First line will contain T

, the number of test cases.
The next T
lines each contain 3 integers p, q and N, where pq=K

    .

Output:

    For each test case, output a single integer which is the day on which the times of the clocks coincide for the Nth

    time.

Constraints

    1≤T≤105

−100≤K≤100
K≠1
1≤q≤104
1≤N≤106

Sample Input:

4
0 1 5
-1 2 3
2 1 10
99 100 2

Sample Output:

3
1
5
51

Explanation:

    Case 1: Here K=0

. A broken clock is right twice a day. So it will be right for the fifth time on day 3
.
Case 2: Here K=−1/2
. The clock moves backwards at half the rate of the correct clock. The time displayed will coincide with the true time first at 12 am, then at 8 am and for the third time at 4 pm on day 1 */    


#include <stdio.h>
    void main()
    {
    	int T;
    	scanf("%d",&T);
    	long long int p,q,n,r,t;
     
    	while(T--)
    	{
    		scanf("%lld%lld%lld",&p,&q,&n);
    				n--;
     
    		if (p==q)
    		{
    			r=1;
    		}
    		else
    		{
    			t=((n*q)/(2*(p-q)));
     
    		
    		if (p<q)
    		{
    			t=-t;
    		}
    		r=t+1;
    	}
    		printf("%lld\n",r);
			}
     
    }
