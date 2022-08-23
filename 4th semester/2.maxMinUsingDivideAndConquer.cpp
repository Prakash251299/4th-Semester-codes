#include<stdio.h>
int C[2];
//int maxMin(int C[],int max,int min){
int maxMin(int max,int min){
	if(max>C[0]){
		C[0] = max;
	}
	if(min<C[1]){
		C[1] = min;
	}
	return 0;
}

int divide(int A[],int a, int b){
	int max = A[a], min = A[a];
	if(a+1>=b){
		if(A[a]>A[b]){
			max = A[a];
			min = A[b];
		}
		else{
			max = A[b];
			min = A[a];
		}
//		maxMin(C,max,min); // C[] is the container of max and min values of previous array length
		maxMin(max,min);
		return 0;
	}
	int m = (a+b)/2;
	divide(A,a,m);
	divide(A,m+1,b);
	return 0;
}

int main(){
	int n = 9;
	int A[n] = {7,9,8,15,17,13,16,5,9};
	C[0] = A[0];
	C[1] = A[0];
	divide(A,0,n-1);
	printf("max: %d, min: %d",C[0],C[1]);
	return 0;
}