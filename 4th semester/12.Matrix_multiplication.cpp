#include<stdio.h>
int main(){
	int i=0,j=0,k=0,n=4,l=0,var=0;
	int M[n][n], multiplyTo[n][n];
//	int A[n] = {1,2,3,4,5}, B[n] = {2,3,4,5,6};
	int A[n] = {5,4,6,2}, B[n] = {4,6,2,7};
//	for(i=1;;i++){
//		for(j=1;;j++){
//			printf("%d %d, ",j,j+i);
//			if(j+i>=n){
//				break;
//			}
//		}
//		printf("\n");
//		if(i+1>=n){
//			break;
//		}
//	}
//
//printf("\n");

	for(i=0;i<n;i++){
		M[i][i] = 0;
//		multiplyTo[i][i] = i;
//		printf("%d ",M[i][i]);
	}
	printf("\n");
	for(i=0;i+1<n;i++){
		M[i][i+1] = A[i]*B[i]*B[i+1];
		multiplyTo[i][i+1] = i;
		printf("%d ",M[i][i+1]);
	}
	for(i=0;i<n-2;i++){
		for(j=i+2;j<n;j++){
			M[i][j] = 999; // Max value so that value cna be changed in next step
		}
	}
	printf("\n");
	for(l=2,j=2;l<=n;j++){
		j=l;
		for(i=0;j<=n;j++){
			for(k=i;;k++){
				printf("M[%d][%d]+M[%d][%d] ",i,k,k+1,j);
				var = M[i][k]+M[k+1][j]+A[i]*A[k+1]*B[j];
				if(var<M[i][j]){
					M[i][j] = var;
					multiplyTo[i][j] = k;
				}
				if(k+1==j){
					break;
				}
			}
			printf("\n");
			i++;
			if(j>=n){
				break;
			}
		}
		l++;
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			printf("%d ",M[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			printf("%d ",multiplyTo[i][j]);
		}
		printf("\n");
	}
	return 0;
}