#include<stdio.h>
#include<string.h>
int main(void)
{
    int r,l,i,j,k=0,f=0;
    char s[501],a[501];
    scanf("%d",&r);
    for(i=1;i<=r;i++)
    {
        scanf("%d\n",&l);
        gets(s);
        for(j=0;j<strlen(s);j++)
        {
            if(s[j]=='H'||s[j]=='T')
            {
                a[k]=s[j];
                k++;
            }
        }
        if((k%2)!=0)
            printf("Invalid\n");
        else
        {
            for(j=0;j<(k-1);j=j+2)
            {
                if(a[j]!='H'||a[j+1]!='T')
                    f=1;
                if(f==1)
                    break;
            }
            if(f==0)
                printf("Valid\n");
            else
                printf("Invalid\n");
        }
        f=k=0;
    }
    return 0;
}
