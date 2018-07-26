#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int arr[26]={0};
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            arr[s[i]-97]++;
        }
        sort(arr,arr+26);
        //for(int i=0;i<26;i++)
          //  cout<<arr[i]<<" ";
        if(arr[23]==0)
            cout<<"Dynamic"<<endl;
        else
        {
            int count1=0,count2=0,j;
        for(int i=0;i<26;i++)
        {
            if(arr[i]!=0)
            {
                j=i;
                break;
            }
        }
        for(int i=j+2;i<26;i++)
        {
            if(arr[i-1]+arr[i-2]!=arr[i])
               count1=1;
        }
        swap(arr[j],arr[j+1]);
        for(int i=j+2;i<26;i++)
        {
            if(arr[i-1]+arr[i-2]!=arr[i])
               count2=1;
        }
            if(count1==0||count2==0)
                cout<<"Dynamic"<<endl;
            else
                cout<<"Not"<<endl;
        }
    }
    return 0;
}
