#include<stdio.h>
int main()
{int t,l,i,b;
scanf("%d",&t);
while(t--)
{scanf("%d %d",&l,&b);
int l1=0,b1=0;
for(i=1; ;i++)
{if(i%2==0)
{b1=b1+i;
if(b1>b)
{printf("Limak\n");
break;}}
else 
{l1=l1+i;
if(l1>l)
{printf("Bob\n");
break;}}}}
return 0;
}
