/* You have an initially empty string S, a target string T and a sequence of n strings p1,p2,…,pn. You may perform any number of operations; let's denote by |S| the length of the string S

before the current operation. Each operation should be of one of the following types:

    insert a lowercase English letter x

at the beginning of the string S; the cost of this operation is clx·|S|
append a lowercase English letter x
to the end of S with cost crx·|S|
choose a valid index i
and insert the string pi at the beginning of S with cost kli·|S|
choose a valid index i
and append the string pi to the end of S with cost kri·|S|

Note that in the first two types of operations, x

refers to any English lower case letter. Not just the letter 'x'.

Your task is to calculate the minimum total cost of building the target string T
, i.e. the minimum sum of costs of operations needed to make S equal to T

.
Input

    The first line of the input contains a single integer n

.
n
lines follow. For each valid i, the i-th of these lines contains the string pi
.
The next line contains 26
space-separated integers cla,clb,…,clz
.
The next line contains 26
space-separated integers cra,crb,…,crz
.
The next line contains n
space-separated integers kl1,kl2,…,kln
.
The next line contains n
space-separated integers kr1,kr2,…,krn
.
The last line contains a single string T

    .

Output

Print a single line containing one integer — the minimum cost of building the target string.
Constraints

    1=n=104

1=|pi|=100
for each valid i
1=|T|=1,000
1=cli,cri=109
for each lowercase English letter i
1=kli,kri=109
for each valid i

    all strings contain only lowercase English letters

Subtasks

Subtask #1 (30 points):

    n=10

|pi|=10
for each valid i

Subtask #2 (70 points): original constraints
Example Input

3
aba
ba
xy
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
3 2 1 3 5 9 10 11 11 9 9 8 7 6 5 1 33 22 11 90 1 1 2 3 5 8
1 2 3
1 1 1
abacaba

Example Output

5

Explanation

First of all, we should perform an operation of the first or second type and add the letter "c" to the initial empty string S
, with cost 0 because |S|=0 currently. Next, we should perform an operation of the third type, inserting the string "aba" at the beginning of S with cost 1·1=1 (since |S|=1 currently); after this operation, S is "abac". Finally, we should perform an operation of the fourth type, appending the string "aba" to S with cost 1·4=4 (since |S|=4 currently). After this operation, S=T, so the total cost is 0+4+1=5. */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
 
using namespace std;
 
#define MAXN 10500
#define MAXNODE 3500000
#define VERYBIG (1LL<<60)
 
long long n, i, j, k, top, rtop, id, sl;
string p[MAXN]; 
string target;
long long cl[26], cr[26], pl[MAXN], pr[MAXN];
 
// trie
long long val[MAXNODE];		// -1 if invalid
long long pnext[MAXNODE][26];	// pointer; -1 if invalid
long long rval[MAXNODE];		// -1 if invalid
long long rpnext[MAXNODE][26];	// pointer; -1 if invalid
 
int init_node() {
	int p = top;
	top++;
 
	for (int i = 0; i < 26; i++) pnext[p][i] = -1;
	val[p] = -1;
 
	return p;
}
 
int rinit_node() {
	int p = rtop;
	rtop++;
 
	for (int i = 0; i < 26; i++) rpnext[p][i] = -1;
	rval[p] = -1;
 
	return p;
}
 
 
void add_trie(string s, long long v) {
	int id = 0, t, idd;
 
	for (auto ch : s) {
		t = ch - 'a';
		if (pnext[id][t] == -1) {
			idd = init_node();
			pnext[id][t] = idd;
			id = idd;
		}
		else id = pnext[id][t];
	}
	if (val[id] == -1) val[id] = v;
	else val[id] = min(val[id], v);
}
 
void radd_trie(string s, long long v) {
	int id = 0, t, idd;
 
	for (auto ch : s) {
		t = ch - 'a';
		if (rpnext[id][t] == -1) {
			idd = rinit_node();
			rpnext[id][t] = idd;
			id = idd;
		}
		else id = rpnext[id][t];
	}
	if (rval[id] == -1) rval[id] = v;
	else rval[id] = min(rval[id], v);
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (i = 0; i < n; i++) cin >> p[i];
 
	for (i = 0; i < 26; i++) cin >> cl[i];
	for (i = 0; i < 26; i++) cin >> cr[i];
	for (i = 0; i < n; i++) cin >> pl[i];
	for (i = 0; i < n; i++) cin >> pr[i];
 
	cin >> target;
	sl = target.length();
 
	// build forward trie
	top = 0;
	id = init_node();
 
	for (i = 0; i < 26; i++) {
		id = init_node();
		pnext[0][i] = id;
		val[id] = cr[i];
	}
	
	for (i = 0; i < n; i++) add_trie(p[i], pr[i]);
 
	// build backward trie
	rtop = 0;
	id = rinit_node();
 
	for (i = 0; i < 26; i++) {
		id = rinit_node();
		rpnext[0][i] = id;
		rval[id] = cl[i];
	}
 
	for (i = 0; i < n; i++) {
		reverse(p[i].begin(), p[i].end());
		radd_trie(p[i], pl[i]);
	}
 
	// dp
	vector<vector<long long>> dp(sl, vector<long long>(sl, -(1LL<<60)));
	priority_queue<pair<long long, pair<int, int>>>	pq;	// <negative cost, <start, end>>
 
	// feed initial free ride ones
	for (i = 0; i < sl; i++) {
		dp[i][i] = 0;
		pq.push({ 0, {i,i} });
	}
	for (i = 0; i < sl; i++) {
		id = 0;
		for (j = i; j < sl; j++) {
			int t = target[j] - 'a';
			if (pnext[id][t] == -1) break;
			id = pnext[id][t];
			if (val[id] != -1) {
				dp[i][j] = 0;
				if (i != j) pq.push({ 0, {i, j} });		// avoid duplication
			}
		}
	}
 
	if (dp[0][sl - 1] == 0) {
		cout << "0\n";
		return 0;
	}
 
	long long x, y, xx, yy, w, ww;
 
	while (!pq.empty()) {
		w = pq.top().first;
		x = pq.top().second.first;
		y = pq.top().second.second;
		pq.pop();
 
		//cout << "Processing " << x << " " << y << " - " << w << "\n";
 
		//if ((x == 0) && (y == sl - 1)) break;
 
		if (w != dp[x][y]) continue;  //???
 
		// look forward from y onwards
		id = 0;
		for (i = y + 1; i < sl; i++) {
			int t = target[i] - 'a';
			if (pnext[id][t] == -1) break;
			id = pnext[id][t];
			if (val[id] != -1) {
				if (dp[x][i] < w - (y - x + 1) * val[id]) {
					dp[x][i] = w - (y - x + 1) * val[id];
					pq.push({ dp[x][i],{ x, i } });		// avoid duplication
					//cout << x << " " << i << " - " << dp[x][i] << "\n";
				}
			}
		}
 
		// look backwards
		id = 0;
		for (i = x - 1; i >= 0; i--) {
			int t = target[i] - 'a';
			if (rpnext[id][t] == -1) break;
			id = rpnext[id][t];
			if (rval[id] != -1) {
				if (dp[i][y] < w - (y - x + 1) * rval[id]) {
					dp[i][y] = w - (y - x + 1) * rval[id];
					pq.push({ dp[i][y],{ i, y } });		// avoid duplication
					//cout << i << " " << y << " - " << dp[i][y] << "\n";
				}
			}
		}
	}
 
	cout << -dp[0][sl - 1] << "\n";
 
	return 0;
}
