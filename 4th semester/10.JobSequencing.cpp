#include<stdio.h>
int main(){
	int n = 5,maxTime = 0,sum = 0, count = 0, i = 0, j = 0;
	printf("Enter total number of jobs\n");
	scanf("%d",&n);
	int profit[n],deadline[n];
	for(i=0;i<n;i++){
		printf("Enter profit of job - %d\n",i);
		scanf("%d",&profit[i]);
	}
	for(i=0;i<n;i++){
		printf("Enter deadline of job - %d\n",i);
		scanf("%d",&deadline[i]);
	}
//	int profit[n] = {15,11,10,5,1};
//	int deadline[n] = {2,2,1,3,3};
	for(i=0;i<n;i++){
		if(maxTime<deadline[i]){
			maxTime = deadline[i];
 		}
	}
	int slots[maxTime-1];
	for(i=0;i<maxTime;i++){
		slots[i] = -1;
	}
	for(i=0;i<n;i++){
		for(j = deadline[i];j>0;j--){
			if(slots[j-1]<0){
				slots[j-1] = i;
				sum = sum + profit[i];
				count++;
				break;
			}
			if(count==maxTime){ // If all slots filled then further checks for any job
				break;
			}
		}
	}
	for(i = 0;i<maxTime;i++){
		printf("j(%d) ",slots[i]);
	}
	printf("\nMax profit: %d",sum);
	return 0;
}