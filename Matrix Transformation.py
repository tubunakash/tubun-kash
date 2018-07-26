    from numpy import median
     
    for _ in range(int(raw_input())):
    	n,m=map(int ,raw_input().split())
    	a=list(map(int ,raw_input().split()) for _ in range(n))
    	b=list(map(int ,raw_input().split()) for _ in range(n))
    	for i in range(n):
    		for j in range(m):
    			a[i][j]=a[i][j]-b[i][j]
    	k=any((a[i][j]-a[i][0]-a[0][j]+a[0][0])!=0 for i in range(n) for j in range(m))
    	if (k):
    		print -1
    		continue
    	l=[(a[i][0]-a[0][0]) for i in range(n)]
    	l+=[-a[0][j] for j in range(m)]
    	x=median(l)
    	print int(sum(abs(i-x) for i in l))