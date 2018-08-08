/* Chef has garden full of mango trees, the only source of its income. Now a days, the chef's mangoes aren't doing well in the market. Due to which the chef income is decreasing rapidly. The chef wants to find out the problem with mangoes. He asked his friend for the same. His friend suggest him to check for insects,etc in the garden. Luckily chef came to know that the branches of some trees are under pests attack.

So he decided to cut off the attacked branches. Also he wants to check how many mangoes are wasted by pests. He is busy with his daily routine,so help him to find out the number of wasted mangoes.
Input:

    First line contain two integers N

& M, N number of nodes, M
number edges,
Next M
lines gives the connection between nodes
(M+2)t
h line gives number queries Q
Next Q

    lines gives the edge which is to be cut off.

Output:

For every query output a single integer representing the number of mangoes wasted .

Note: assuming that, there is a mango at each node.
Constraints

    10=N=2*103

1=M<N
1=Q<104

Subtasks

    30 points : 1=N=50

70 points : 1=N=2*103

Sample Input:

13 10
3 10
1 8
6 7
1 11
3 12
0 3
3 9
3 4
1 6
0 1
9
1 6
1 11
0 1
1 8
1 11
3 9
1 8
3 10
3 12

Sample Output:

2
1
5
1
1
1
1
1
1
*/

    #include<stdio.h>
    #include<math.h>
    #include<stdlib.h>
    #include<algorithm>
    using namespace std;
    #define fo(i,a,b) for(int i=a;i<=b;i++)
    #define fd(i,a,b) for(int i=a;i>=b;i--)
    int n,m,et,fa[110000],be[110000],siz[110000],x,y,q;
    struct edg{
    	int y,ne;
    };
    edg e[220000];
    inline void add_edge(int x,int y){
    	e[++et].y=y;
    	e[et].ne=be[x];
    	be[x]=et;
    	fa[y]=x;
    }
    int dfs(int x){
    	siz[x]=1;
    	for(int i=be[x];i;i=e[i].ne){
    		dfs(e[i].y);
    		siz[x]+=siz[e[i].y];
    	}
    }
    int main(){
    	scanf("%d%d",&n,&m);
    	fo(i,1,m){
    		scanf("%d%d",&x,&y);
    		x++;y++;
    		add_edge(x,y);
    	}
    	fo(i,1,n) if (!fa[i]) dfs(i);
    	scanf("%d",&q);
    	while (q--){
    		scanf("%d%d",&x,&y);
    		x++;y++;
    		printf("%d\n",siz[y]);
    	}
    	return 0;
    }
