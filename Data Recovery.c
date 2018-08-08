/* Unfortunately Semcrack has lost its employee data. The data is very necessary hence Semcrack wants to recover it. The only source to recover the data is a string consists of first letter of employee's name.

With the recovery algorithm Semcrack can only recover the number of employee groups in organization. A group of employee is consists of even number of employee's. But recently the recovery algorithm has been stolen by a group of hackers.

Semcrack wants your help to recover it's data. Design an algorithm for the same.

Note that the group can only contain the continuous letters from the given string.
Input:

    First line will contain T

, number of testcases. Then the testcases follow.
The first and only line of each testcase contains of a single line of input, a string of length N

    .

Output:

For each testcase, output in a single line the total number of emplyee groups possible.
Constraints

    1=T=105

1=N=105

Subtasks

    30 points : 1=T=100

70 points : 1=T=105

Sample Input:

2
asdf
amb

Sample Output:

4
2

Explanation:

In first case, ad and sf can't form a group , because skipping of characters are not allowed. */

#include<stdio.h>
#include<string.h>
void main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[100002];
		long long n,count=0;
		scanf("%s",str);
		n=strlen(str);
		if(n%2==0)
		{
			count=n*n/4;
		}
		else
		{
			count=(n*n-1)/4;
		}
		printf("%lld\n",count);
	}
}
