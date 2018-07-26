#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main()
{
    int t,i;
    float time1,time2,n,v1,v2;
    scanf("%d",&t);
    for (i=0;i<t;i=i+1)
    {
        scanf("%f %f %f",&n,&v1,&v2);
        time1= (sqrt(2)*n)/v1;
        time2= (2*n)/v2;
        if (time1<time2){printf("Stairs\n");}
        else if (time1>time2) {printf("Elevator\n");}
 
    }
}
