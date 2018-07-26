    import math
     
    t = int(input())
    for i in range(t):
        p, s = map(int, input().split())
        p = float(p)
        s = float(s)
        d = math.sqrt(((p/6)*(p/6))-((2*s)/3))
        b = ((p/6) - d)/2
        v = (b * b * b) - ((p/4) * b * b) + ((s/2) * b)
        print(round(v,2)) 