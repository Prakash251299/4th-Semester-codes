#include<stdio.h>
rotate(int A[], int n){
	int i = 0;
	int a = A[0];
	while(i+1<n){
		A[i] = A[i+1];
		i++;
	}
	A[n-1] = a;
	return 0;
}

int main(){
	int n = 0, d = 0;
//	int A[1] = {10000000};
//	printf("%d",A[0]);
	printf("Enter length of the array\n");
	scanf("%d",&n);
	int A[n], i = 0;
	while(i<n){
		A[i] = i+1;
		i++;
	}
	printf("Enter number of rotations\n");
	scanf("%d",&d);
	i = 1;
	while(i<=d%n){
		rotate(A,n);
		i++;
	}
	i = 0;
//	printf("\n");
	while(i<n){
		printf("%d ",A[i]);
		i++;
	}
	return 0;
}