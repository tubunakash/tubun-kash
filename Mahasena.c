#include<stdio.h>
 
int main(){
	int t;
	int a;
	int n;
	int even=0;
	int odd=0;
	
	
	scanf("%d",&t);
	while(t--){
		
		scanf("%d",&a);
		
			if(a%2 == 0)
				even++;
			else
				odd++;
		
	}
		if(even> odd)
			printf("READY FOR BATTLE\n");
		else
			printf("NOT READY\n");
return 0;
}
