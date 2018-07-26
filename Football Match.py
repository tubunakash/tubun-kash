    for _ in range(int(input())):
        n=int(input())
        l=[]
        if(n!=0):
            for i in range(n):
                x=str(input())
                l.append(x)
            if(n==1):
                print(l[0])
            else:    
                for j in range(n):
                    if(l[0]!=l[j]):
                        ce=j
                        break
                team1=l.count(l[0])
                team2=l.count(l[ce])
                if(team1>team2):
                    print(l[0])
                elif(team2>team1):
                    print(l[ce])
                else:
                    print("Draw")
        else:
            print("Draw") 