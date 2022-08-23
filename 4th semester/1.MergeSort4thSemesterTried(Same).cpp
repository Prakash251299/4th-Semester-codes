#include<stdio.h>
#include<stdlib.h>
merge(int A[], int a1, int a2, int b1, int b2){
	int a = a1, b = b1, k = 0, C[b2-a1+1];
	while(1){
		if(A[a]<A[b]){
			C[k] = A[a];
			k++; a++;
		}
		else{
			C[k] = A[b];
			b++; k++;
		}
		if(a>a2 or b>b2){
			break;
		}
	}
	if(a>a2 and b<=b2){
		for(int j = b; j<=b2; j++){
			C[k] = A[j];
			k++;
		}
	}
	if(b>b2 and a<=a2){
		for(int j = a; j<=a2; j++){
			C[k] = A[j];
			k++;
		}
	}
	for(int i=a1;i<=b2;i++){
		A[i] = C[i-a1];
	}
	return 0;
}

mergeSort(int A[],int a,int b){
	if(a>=b){
		return 0;
	}
	int m = 0;
	m = (a+b)/2;
	mergeSort(A,a,m);
	mergeSort(A,m+1,b);
	merge(A,a,m,m+1,b);
	return 0;
}

int main(){
	int n = 100000, i = 0, A[n];
//	int A[n] = {1,5,7,12,13,2,3,4,5,6,7,8,14};
	for(i = 0;i<n;i++){
		A[i] = rand()%1000;
//		printf("%d ",A[i]);
	}
	printf("\nSTART\n");
//	int A[n] = {7,8,5,1,6,4};
//	int A[n] = {7,8,5,1,6,4};
//	merge(A,0,4,5,12);
	mergeSort(A, 0, n-1);
//	for(int i = 0; i<n; i++){
//		printf("%d ",A[i]);
//	}
	return 0;
}