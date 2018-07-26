    n = input()
    i = 1
    while i <= int(n):
    	
    	b = input()
    	b = int(b)
    	new_b = b-3
    	if new_b <= 0:
    		print("0")
    	else:
    		ap_b = b/2
    		ap_b = int(ap_b)
    		ap_b -= 1
    		output = ((ap_b)*(ap_b+1))/2
    		print(int(output))
    	
    	i = i+1 