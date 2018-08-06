/*There are three squares, each with side length a placed on the x-axis. The coordinates of centers of these squares are (x1, a/2), (x2, a/2) and (x3, a/2) respectively. All of them are placed with one of their sides resting on the x-axis.

You are allowed to move the centers of each of these squares along the x-axis (either to the left or to the right) by a distance of at most K. Find the maximum possible area of intersections of all these three squares that you can achieve. That is, the maximum area of the region which is part of all the three squares in the final configuration.
Input

    The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
    The first line of each test case contains two space-separated integers a, K denoting side length of the squares, and the maximum distance that you can move the center of any square.
    The second line contains three space separated integers x1, x2, x3

Output

For each test case, output a real number corresponding to the maximum area of the intersection of the three squares that you can obtain. Your answer will be considered correct if it has an absolute error of less than or equal to 10-2.
Constraints

    1 = T = 105
    1 = a = 105
    0 = K = 106
    -106 = x1, x2, x3 = 106

Example

Input
3
1 0
1 2 3
1 1
1 2 3
1 1
1 4 6

Output
0.000000
1.0000
0.0

Explanation

Testcase 1: The figure below shows the three squares:

Since K = 0, they cannot be moved, and since there is no region which belongs to all three squares, the answer is 0.

Testcase 2: The starting configuration is the same as above, but now each of the squares can move 1 unit. So we can move the first square 1 unit to the right and the third square one unit to the left, and have all the three squares at x-coordinate = 2. Thus the entire square is part of all three squares, and the answer is 1. */   
	
	#include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef pair<int, int> ii; 
     
    bool intersect(double l1, double r1, double l2, double r2, double &la, double &ra) {
    	if(l1 > l2) swap(l1, l2), swap(r1, r2); 
    	if(r1 < l2 || l1 > r2) return 0; 
    	la = max(l1, l2); 
    	ra = min(r1, r2); 
    	return 1; 
    }
    int main(int argc, char const *argv[]) {
    	int t; scanf("%d", &t); while(t--) {
    		int a, k;
    		scanf("%d %d", &a, &k);
    		int x1, x2, x3;
    		scanf("%d %d %d", &x1, &x2, &x3); 
    		double l1 = x1 - a / 2.0 - k; 
    		double r1 = x1 + a / 2.0 + k;
    		double l2 = x2 - a / 2.0 - k; 
    		double r2 = x2 + a / 2.0 + k;
    		double l3 = x3 - a / 2.0 - k; 
    		double r3 = x3 + a / 2.0 + k;
     
    		double l, r, la, ra; 
    		if(!intersect(l1, r1, l2, r2, l, r)) 
    			{ puts("0.0"); continue; }
     
    		if(!intersect(l, r, l3, r3, la, ra)) 
    			{ puts("0.0"); continue; }
     
    		double ans = a * min(ra - la, (double)a); 
    		printf("%.3f\n", ans);
    	}
    } 
