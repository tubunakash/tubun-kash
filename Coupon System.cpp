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
          int c[n],l[n],d[n];
          int d1=0,d2=0,d3=0;
          int c1,c2,c3;
          for(int i=0;i<n;i++)
          {
              cin>>c[i]>>l[i]>>d[i];
              if(l[i]==1)
              {
                  if(d[i]>d1)
                  {    d1=d[i];
                      c1=c[i];
                  }
                  else if(d[i]==d1)
                  {
                      c1=min(c1,c[i]);
                  }
              }
              if(l[i]==2)
              {
                  if(d[i]>d2)
                  {    d2=d[i];
                      c2=c[i];
                  }
                  else if(d[i]==d2)
                  {
                      c2=min(c2,c[i]);
                  }
              }
              if(l[i]==3)
              {
                  if(d[i]>d3)
                  {    d3=d[i];
                      c3=c[i];
                  }
                  else if(d[i]==d3)
                  {
                      c3=min(c3,c[i]);
                  }
              }
          }
          cout<<d1<<" "<<c1<<endl;
          cout<<d2<<" "<<c2<<endl;
          cout<<d3<<" "<<c3<<endl;
        }
        return 0;
    } 
