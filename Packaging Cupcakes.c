#include <stdio.h>
#include <stdlib.h>
int cup (unsigned int x);
int main()
{
    int i,n;
    unsigned int j;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d", &j);
        arr[i]= cup(j);
    }
        for(i=0;i<n;i++)
        {
            printf("%d \n", arr[i]);
        }
        return 0;
}
int cup (unsigned int x)
{
   unsigned int i;
if (x%2 == 0)
    {
        i = x/2 +1;
    }
    else
    {
        i = (x+1)/2;
    }
    return i;
}
