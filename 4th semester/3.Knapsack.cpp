#include<stdio.h>
#include<malloc.h>
struct node{
	float data;
	int priority = 0  ;
	struct node *next,*prev;
}*start = NULL,*q;

//int j = 0;
int p[4]; // It can be used for storing more than 4 elements as required because array is never ending

float profitCounter(int p[],float included[],int profit[],int n){
//	printf("\n%d %d %d %d  %d",p[0],p[1],p[2],p[3],profit[p[0]]);
	int i = 0;
	float sum = 0;
//	printf("%f",sum);
	while(i<n){
		sum = sum + (profit[p[i]] * included[i]);
//		printf("\n%d",sum);
		i++;
	}
//	printf("\n%f",sum);
	return sum;
}

int j = 0;
int InorderTraverse(node* q){
	if(q == NULL){
		return 0;
	}
	InorderTraverse(q->next);
	p[j] = q->priority;
//	printf("%d %0.2f\n",q->priority,q->data);
	j++;
	InorderTraverse(q->prev);
	return 0;
}

ins(node* q,float data,int i){
	if(data <= q->data){
		if(q->prev==NULL){
			q->prev = (struct node*)malloc(sizeof(struct node));
			q = q->prev;
			q->data = data;
			q->priority = i;
//			printf("%d %0.2f\n",q->priority,q->data);
			q->prev = NULL;
			q->next = NULL;
		}
		if(q->prev!=NULL){
			ins(q->prev,data,i);
		}
	}
	if(data > q->data){
		if(q->next==NULL){
			q->next = (struct node*)malloc(sizeof(struct node));
			q = q->next;
			q->data = data;
			q->priority = i;
//			printf("%d %0.2f\n",q->priority,q->data);
			q->next = NULL;
			q->prev = NULL;
		}
		if(q->next!=NULL){
			ins(q->next,data,i);
		}
	}
	return 0;
}

int main(){
	int n = 0, i = 0;
	printf("Enter number of objects \n");
	scanf("%d",&n);
	int profit[n], weight[n], priority[n];
//	int priority[n];
	float maxWt;
	printf("Enter maximum weight of the knapsack\n");
	scanf("%f",&maxWt);
	float remWt = maxWt;
	float ratio[n], included[n], prof = 0.0;
//	float included[n], prof = 0.0;
//	int profit[n] = {20,60,10,25};
//	int weight[n] = {10,20,10,10};
	for(i=0;i<n;i++){
		printf("\nEnter profit of obj - %d: ",i+1);
		scanf("%d",&profit[i]);
//		profit[i] = 
	}
	for(i=0;i<n;i++){
		printf("\nEnter weight of obj - %d: ",i+1);
		scanf("%d",&weight[i]);
	}
	for(i=0;i<n;i++){
//		printf("%f ",float(float(profit[i])/float(weight[i])));
		ratio[i] = float(float(profit[i])/float(weight[i]));
//		printf("%f ",ratio[i]);
	}
//	printf("\n");
//	float ratio[n] = {2,3,1,2.5};
//	float included[n], prof = 0.0;
	q = start;
	if(n>0){
		start = (struct node*)malloc(sizeof(struct node));
		start->data = ratio[0];
		start->priority = 0;
		start->prev = NULL;
		start->next = NULL;
		for(i = 1;i<n;i++){
			q = start;
			ins(start,ratio[i],i); // Ratio array is stored in a binary search tree
		}
		InorderTraverse(start);
//		printf("%d %d %d %d",p[0],p[1],p[2],p[3]);
		i = 0;
		while(i<n){
			if(remWt>=weight[p[i]]){
				included[i] = 1;
				remWt = remWt - weight[p[i]]; // 1 3  0 2
				i++;continue;
			}
			if(remWt<weight[p[i]]){
				included[i] = remWt/weight[p[i]];
//				printf("\n%f\n",included[i]);
				remWt = 0;
				i++;
			}
		}
		
		float prof = profitCounter(p,included,profit,n);
		printf("\nMaximum profit: %f",prof);
	}
	return 0;
}

//int main(){
//	int n = 4, i = 0;
//	float maxWt = 25, remWt = maxWt;
//	int profit[n] = {20,60,10,25};
//	int weight[n] = {10,20,10,10},priority[n];
//	float ratio[n] = {2,3,1,2.5};
//	float included[n], prof = 0.0;
//	q = start;
//	if(n>0){
//		start = (struct node*)malloc(sizeof(struct node));
//		start->data = ratio[0];
//		start->priority = 0;
//		start->prev = NULL;
//		start->next = NULL;
//		for(i = 1;i<n;i++){
//			q = start;
//			ins(start,ratio[i],i);
//		}
//		InorderTraverse(start);
//		printf("%d %d %d %d",p[0],p[1],p[2],p[3]);
//		i = 0;
//		while(i<n){
//			if(remWt>=weight[p[i]]){
//				included[i] = 1;
//				remWt = remWt - weight[p[i]]; // 1 3  0 2
//				i++;continue;
//			}
//			if(remWt<weight[p[i]]){
//				included[i] = remWt/weight[p[i]];
////				printf("\n%f\n",included[i]);
//				remWt = 0;
//				i++;
//			}
//		}
//		
//		float prof = profitCounter(p,included,profit,n);
//		printf("\nMaximum profit: %f",prof);
//	}
//	return 0;
//}