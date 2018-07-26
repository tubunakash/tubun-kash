#include <bits/stdc++.h>
using namespace std;
 
const int P = 1e9 + 7;
const int K = 55;
 
int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = 1LL * a * a % p) if (n & 1) ret = 1LL * ret * a % p;
	return ret;
}
 
int Z1[K][K], Z2[K][K], Z[K][K];
int A[K][K], B[K][K], X[K][K], Y[K][K];
int x[K][K], y[K][K];
 
void mul(int A[K][K], int B[K][K], int C[K][K]) {
	memcpy(x, A, sizeof x);
	memcpy(y, B, sizeof y);
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			C[i][j] = 0;
			for (int k = 0; k < K; k++) {
				C[i][j] = (C[i][j] + 1LL * x[i][k] * y[k][j]) % P;
			}
		}
	}
}
 
void add(int A[K][K], int B[K][K], int C[K][K]) {
	memcpy(x, A, sizeof x);
	memcpy(y, B, sizeof y);
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			C[i][j] = (x[i][j] + y[i][j]) % P;
		}
	}
}
 
void sub(int A[K][K], int B[K][K], int C[K][K]) {
	memcpy(x, A, sizeof x);
	memcpy(y, B, sizeof y);
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			C[i][j] = (x[i][j] + P - y[i][j]) % P;
		}
	}
}
 
int main() {
	int n, k, a, b; cin >> n >> k >> a >> b;
	for (int i = 0; i < k; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i + j >= 0 && i + j < k) A[i][i + j] = 1;
		}
	}
	for (int i = 0; i < k; i++) {
		if (i >= a && i < b - 1) {
			B[i][i] = 1;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) X[i][j] = (i == j);
	}
	for (int i = 29; i >= 0; i--) {
		if ((1 << i) > n) continue;
		mul(Y, X, Z1);
		mul(X, Y, Z2);
		add(Z1, Z2, Y);
		mul(Z, X, Z);
		mul(X, X, X);
		if (n >> i & 1) {
			mul(Y, A, Z1);
			mul(X, B, Z2);
			add(Z1, Z2, Y);
			memcpy(Z, X, sizeof Z);
			mul(X, A, X);
		}
	}
	mul(Z, B, Z1);
	mul(B, Z, Z2);
	sub(Y, Z1, Y);
	sub(Y, Z2, Y);
	cout << modExp(n - 2, P - 2, P) * 1LL * Y[k/2-1][k/2-1] % P << endl;
	return 0;
}
