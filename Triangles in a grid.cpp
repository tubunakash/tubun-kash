    #include <cstdio>
    #include <algorithm>
     
    typedef long long int64;
     
    struct IO_Tp
    {
    	bool is_digit(const char ch)
    	{
    		return '0' <= ch && ch <= '9';
    	}
    	
    	IO_Tp &operator>>(int &res)
    	{
    		static char ch;
    		while (ch = getchar(), !is_digit(ch))
    			;
    		res = ch & 15;
    		while (ch = getchar(), is_digit(ch))
    			(res *= 10) += ch & 15;
    		return *this;
    	}
    } IO;
     
    const int Max_N(5000005), Mod(1000000007);
     
    int N, M;
    int F[Max_N], Ans1, Ans2;
     
    int64 Inv(const int64 x)
    {
    	if (x <= 1)
    		return x;
    	return (Mod - Mod / x) * Inv(Mod % x) % Mod;
    }
     
    int main(int argc, char **argv)
    {
    	IO >> N >> M;
    	int64 s(static_cast<int64>(N) * M % Mod);
    	for (int d(std::max(N, M) - 1); d; --d)
    	{
    		int cx(0), cy(0);
    		for (int i(N - d); i > 0; i -= d)
    			cx = (cx + i) % Mod;
    		for (int i(M - d); i > 0; i -= d)
    			cy = (cy + i) % Mod;
    		F[d] = static_cast<int64>(cx) * cy % Mod;
    		for (int i(d + d); i < N; i += d)
    			F[d] = (F[d] + Mod - F[i]) % Mod;
    		int res(F[d] * 2 % Mod);
    		if (d < N)
    			res = (res + static_cast<int64>(N - d) * M) % Mod;
    		if (d < M)
    			res = (res + static_cast<int64>(M - d) * N) % Mod;
    		Ans1 = (Ans1 + res * (s + Mod - (d + 1)) % Mod * d + Mod - res * (d - 1LL) % Mod * d % Mod) % Mod;
    		Ans2 = (Ans2 + res * (s + Mod - (d + 1)) + Mod - res * (d - 1LL) % Mod * 2 % Mod) % Mod;
    	}
    	
    	printf("%lld", Ans1 * Inv(Ans2) * 3 % Mod);
    	
    	return 0;
    } 
