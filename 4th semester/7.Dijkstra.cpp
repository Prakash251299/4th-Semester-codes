#include<stdio.h>
int main(){
	int a = 0, b = 4, n = 5,i = 0, j = 0, min = 0, dist = 0, k = 0, t = 0;
//	int A[n][n] = {{0,3,100,7,11},{8,0,2,100,100},{5,100,0,1,100},{2,100,100,0,100}};
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	int visited[n],A[n][n];;
	printf("Enter start point\n");
	scanf("%d",&a);
	printf("Enter end point\n");
	scanf("%d",&b);
	

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				A[i][j] = 0;
				continue;
			}
			printf("Enter distance of %d to %d\n",i,j);
			scanf("%d",&A[i][j]);
		}
	}
	min = A[a][b];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<n;i++){
		visited[i] = 0;
	}
	visited[a] = 1;
	dist = 0;
	for(i=a;;){
		if(i!=0){
			min = A[i][0];
			t = 0;
		}
		else{
			min = A[0][1];
			t = 1;
		}
		for(j=0;j<n;j++){
			if(i!=j){
				if(A[i][j]<min){
					if(visited[j]==1){
						dist = A[a][b];
						printf("smallest path: %d ",dist);
						return 0;
					}
					min = A[i][j];
					t = j;
				}
			}
		}
		if(min==A[a][b]){
			dist = min;
			printf("smallest path: %d",dist);
			return 0;
		}
		dist = min + dist;
		i = t;
		visited[i] = 1;
		if(i==b){
			printf("smallest path: %d ",dist);
			return 0;
		}
	}
	return 0;
}