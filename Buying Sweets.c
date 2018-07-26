    #include<stdio.h>
    int main()
    {
        int i,t,s,k1;
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
            int j,sum=0,a[100],s1=0,s2=0,k,x;
            scanf("%d %d",&k,&x);
            for(j=0;j<k;j++)
            {
               scanf("%d",&a[j]); 
               sum=sum+a[j];
            }  
            s1=sum/x;
            s2=sum%x;
            if(s2==0)
                printf("%d\n",s1);
            else
            {
                    for(k1=0;k1<k;k1++)
                    {
                        s=(sum-a[k1])/x;
                        if(s==s1)
                        {
                            printf("-1\n");
                            break;
                        }
                    }    
                     if(s!=s1)
                       printf("%d\n",s1);
                    
            }
        }
    } 
