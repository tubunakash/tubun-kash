    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
             int n;
             cin>>n;
             for(int i=0;i<=n;i++)
             {
                 if(i*(i+1)==n*2)
                 {
                     cout<<i<<endl;
                     break;
                 }
                 else if(i*(i+1)>n*2)
                 {
                     cout<<i-1<<endl;
                     break;
                 }
             }
     
     
     
     
        }
    }
     
