/* You are given a grid with n rows and m columns. Each cell of this grid can either be empty or it contains one particle. It can never contain more than one particle. Let's denote the cell in the i-th row and j-th column by (i,j), with the top left corner being (0,0). From a cell (i,j)

, a particle could move in one of the following four directions:

    to the left, i.e. to the cell (i,j-1)

to the right, i.e. to the cell (i,j+1)
up, i.e. to the cell (i-1,j)
down, i.e. to the cell (i+1,j)

It is not possible for a particle to move to a cell that already contains a particle or to a cell that does not exist (leave the grid).

It is possible to apply a force in each of these directions. When a force is applied in a given direction, all particles will simultaneously start moving in this direction as long as it is still possible for them to move.

You are given a sequence of forces. Each subsequent force is applied only after all particles have stopped moving. Determine which cells of the grid contain particles after all forces from this sequence are applied in the given order.
Input

    The first line of the input contains a single integer T

denoting the number of test cases. The description of T
test cases follows.
The first line of each test case contains two space-separated integers n
and m
.
n
lines describing the initial grid follow. For each i (1=i=n), the i-th of these lines contains a binary string with length m describing the i-th row of the grid. For each j (1=j=m), if the j-th character of this string is '1', then the cell (i,j) contains a particle, and if it is '0', then the cell (i,j)
is empty.
The last line contains a single string S

    describing the sequence of applied forces. Each character of this string corresponds to applying a force in some direction; forces applied in the directions left, right, up, down correspond to characters 'L', 'R', 'U', 'D' respectively.

Output

For each test case, print n
lines each containing a binary string of length m

, describing the resulting grid (after all the forces are applied) in the same format as the input grid.
Constraints

    1=T=200

1=n,m=100
1=|S|=2·104

Subtasks

Subtaks #1 (30 points):

    1=T=10

1=n,m=10
1=|S|=100

Subtask #2 (70 points): Original constraints
Example Input

3
4 4
1010
0010
1001
0100
LRDU
4 3
000
010
001
101
LRL
3 2
01
10
00
D

Example Output

0011
0011
0001
0001
000
100
100
110
00
00
11

Explanation

Example case 1: The initial grid is:

1010
0010
1001
0100

After applying the first force (in the direction "L", i.e. to the left), the grid is:

1100
1000
1100
1000

After applying the second force (in the direction "R"), the grid is:

0011
0001
0011
0001

After applying the third force (in the direction "D"), the grid is:

0001
0001
0011
0011

After applying the fourth force (in the direction "U"), the final grid is:

0011
0011
0001
0001 */


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
     ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string g[n];
        for(int i=0;i<n;i++){
            cin>>g[i];
        }
        string s;
        cin>>s;
      //  cout<<" dfg"<<s<<"fg";
        int vc[1100];
        memset(vc,0,sizeof(vc));
 
        char temp=s[s.size()-1];
        vector<char> v;
        if(temp=='L')
            v.push_back(temp);
        if(temp=='R')
            v.push_back(temp);
        if(temp=='D')
            v.push_back(temp);
        if(temp=='U')
            v.push_back(temp);
        vc[int(temp)-65]=3;
        for(int i=s.size()-2;i>=0;i--){
            if(vc[int(s[i])-65]!=3){
                vc[int(s[i])-65]=3;
                v.push_back(s[i]);
                if(v.size()==4)
                    break;
            }
        }
        memset(vc,0,sizeof(vc));
        vector<char> vv;
        for(int i=0;i<s.size();i++){
            if(vc[int(s[i])-65]!=3){
                vc[int(s[i])-65]=3;
                vv.push_back(s[i]);
                if(vv.size()==4)
                    break;
            }
        }
        for(int ii=vv.size()-1;ii>=0;ii--){
            v.push_back(vv[ii]);
        }
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]=='L'){//cout<<"tt";
                for(int j=0;j<n;j++){
                     int c=0;
                     for(int k=0;k<g[j].size();k++){
                        if(g[j][k]=='1')
                            c++;
                     }
                     for(int k=0;k<g[j].size();k++){
                        if(c>0)
                        {
                            g[j][k]='1';
                            c--;
                        }
                        else
                            g[j][k]='0';
                     }
                }
            }
            if(v[i]=='R'){//cout<<"tt";
                for(int j=0;j<n;j++){
                     int c=0;
                     for(int k=0;k<g[j].size();k++){
                        if(g[j][k]=='1')
                            c++;
                     }
                     for(int k=g[j].size()-1;k>=0;k--){
                        if(c>0)
                        {
                            g[j][k]='1';
                            c--;
                        }
                        else
                            g[j][k]='0';
                     }
                }
            }
            if(v[i]=='D'){
                for(int j=0;j<m;j++){
                     int c=0;
                     for(int k=0;k<n;k++){
                        if(g[k][j]=='1')
                            c++;
                     }
                     for(int k=n-1;k>=0;k--){
                        if(c>0)
                        {
                            g[k][j]='1';
                            c--;
                        }
                        else
                            g[k][j]='0';
                     }
                }
 
            }
            if(v[i]=='U'){
 //  cout<<"rtt";
                    for(int j=0;j<m;j++){
                     int c=0;
                     for(int k=0;k<n;k++){
                        if(g[k][j]=='1')
                            c++;
                     }
                     for(int k=0;k<n;k++){
                        if(c>0)
                        {
                            g[k][j]='1';
                            c--;
                        }
                        else
                            g[k][j]='0';
                     }
                }
 
            }
        }
        for(int i=0;i<n;i++){
            cout<<g[i]<<"\n";
        }
    }
}
