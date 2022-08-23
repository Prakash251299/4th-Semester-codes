#include<stdio.h>
int main(){
	int i=0,j=0,a=0,sum=0,n=4;
	int B[n][n];
	int A[n][n] = {{0,3,100,7},{8,0,2,100},{5,100,0,1},{2,100,100,0}};
//	int A[n][n] = {{0,5,100,10},{100,0,3,100},{100,100,0,1},{100,100,100,0}};
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			B[i][j] = 0;
//			scanf("%d",&A[0][i][j]);
		}
	}
	for(a=0;a<n;a++){
		for(i=0;i<n;i++){
			if(i==a){
				for(j=0;j<n;j++){
					B[i][j] = A[i][j];
				}
				continue;
			}
			for(j=0;j<n;j++){
				if(j==a){
					B[i][j] = A[i][j];
					continue;
				}
				if(i==j){
					B[i][j] = A[i][j];
					continue;
				}
				sum = A[i][a] + A[a][j];
				if(A[i][j]>sum){
					B[i][j] = sum;
				}
				else{
					B[i][j] = A[i][j];
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				A[i][j] = B[i][j];
			}
		}
	}
	printf("  ");
	for(i=0;i<n;i++){
		printf(" %d",i);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("---");
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d| ",i);
		for(j=0;j<n;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	return 0;
}