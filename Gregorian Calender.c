    #include<stdio.h>
    int main()
    {
        int t,year,i,count;
        scanf("%d",&t);
        while(t--)
        {count=1;
            scanf("%d",&year);
            for(i=1901;i<=year;i++)
            {if((i-1)%400==0)
            count+=2;
          else if ((i-1)%100!=0&&(i-1)%4==0)
           count+=2;
           else
            count+=1;}
            if(count%7==0)
            printf("sunday\n");
            else if(count%7==1)
            printf("monday\n");
            else if(count%7==2)
            printf("tuesday\n");
            else if(count%7==3)
            printf("wednesday\n");
            else if(count%7==4)
            printf("thursday\n");
            else if(count%7==5)
            printf("friday\n");
            else if(count%7==6)
            printf("saturday\n");
			}
		}
