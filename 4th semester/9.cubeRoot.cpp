#include<stdio.h>
int main(){
	int n=16,a[n/2],k=0,i=0,j=0,res=1,sq=1,m=n;
	while(n!=1){
		for(i=2;i<=n;i++){
			if(n%i==0){
				a[k] = i;
				k++;
				n=n/i;
				break;
			}
		}
	}
	for(i=0;i<k;i++){
		printf("%d ",a[i]);
	}
	for(i=0;i<k;i++){
		if(a[i] == a[i+1] and a[i]==a[i+2]){
			res = res*a[i];
			i=i+2;
		}
		else{
			sq = sq*a[i];
		}
	}
	printf("\nCubeRoot of %d is %d|/%d",m,res,sq);
	return 0;
}