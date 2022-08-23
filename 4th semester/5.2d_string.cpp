#include<stdio.h>
#include<string.h>
int main(){
	char A[4][10],a[10];
//	strcpy(A[0],"uad");
//	printf("%s",A[1]);
	for(int j=0;j<4;j++){
		scanf("%s",a);
		strcpy(A[j],a);
//		for(int i = 0;i<10;i++){
//			scanf("%s",&A[j][i]);
//		}
	}
	for(int j=0;j<4;j++){
//		for(int i = 0;i<10;i++){
			printf("%s\n",A[j]);
//		}
	}
	return 0;
}