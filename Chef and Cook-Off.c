    #include <stdio.h>
     
    int main(void)
    {
        int t,a,b,c,d,e,s;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
            s=a+b+c+d+e;
            if(s==0)
            {
                printf("Beginner\n");   
            }
            else if(s==1)
            {
                printf("Junior Developer\n");  
            }
            else if(s==2)
            {
                printf("Middle Developer\n");
            }
            else if(s==3)
            {
                printf("Senior Developer\n");
            }
            else if(s==4)
            {
                printf("Hacker\n");
            }
            else
            {
                printf("Jeff Dean\n");
            }
                
        }
        return 0;
    }
     
     
