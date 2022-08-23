#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	struct node *next,*prev;
	int data = 0;
}*start=NULL,*q=start;

int height = 1, incr = 1, j = 0;
int changedValue = 1;

int del(node *q, int i, int h, int A[]){
	if(h==1){
		if(i==2){
			A[j] = start->data;
			j++;
			start->data = q->next->data;
			q->next = NULL;
		}
		if(i==1){
			A[j] = start->data;
			j++;
			start->data = q->prev->data;
			q->prev = NULL;
		}
		if(incr==1){
			height--; incr = pow(2,height);
		}
		else{
			incr--;
		}
		return 0;
	}
	if(i<=(pow(2,h)/2)){
		del(q->prev,i,h-1,A);
	}
	if(i>(pow(2,h)/2)){
		del(q->next,i-(pow(2,h)/2),h-1,A);
	}
	return 0;
}
int arr = 0; // Value container for arrangement process
int arrange(node *q){
//	int arr = 0; // Declaring here, it is giving error (Finally not giving error here too)
	if(q==NULL){
		return 0;
	}
	arrange(q->prev);
	arrange(q->next);
	if(q->prev!=NULL and q->next!=NULL){
		if(q->prev->data >= q->next->data){ //		3    Here child equality must be checked
			if(q->prev->data > q->data){//		   / \
//												  5	 5
				arr = q->data;
				q->data = q->prev->data;
				q->prev->data = arr;
			}
		}
		else{
			if(q->prev->data < q->next->data){
				if(q->next->data > q->data){
					arr = q->data;
					q->data = q->next->data;
					q->next->data = arr;
				}
			}
		}
	}
	if(q->prev!=NULL and q->next==NULL){
		if(q->prev->data>q->data){	//		3   Here child equality need not to be checked
//										   /
//										  3
			arr = q->data;
			q->data = q->prev->data;
			q->prev->data = arr;
		}
	}
	return 0;
}

Inorder(node *q){
	if(start==NULL){
		printf("No elements to traverse\n");
		return 0;
	}
	if(q->prev==NULL){
		printf("%d ",q->data);
		if(q->next!=NULL){
			Inorder(q->next);
		}
	}
	else{
		Inorder(q->prev);
		printf("%d ",q->data);
		if(q->next!=NULL){
			Inorder(q->next);
		}
	}
	return 0;
}

int ins(node *q, int i, int h){
	int a = 0;
	if(h==0){
		a = changedValue;
		changedValue++;
//		printf("Enter: ");
//		scanf("%d",&a);
//		a = rand()%100;
		q->data = a;
		q->prev = NULL;
		q->next =NULL;
		if(incr == pow(2,height)){
			incr = 1; height++;
		}
		else{
			incr++;
		}
		return 0;
	}
	if(i<=pow(2,h)/2){
//		h=h-1;
//		if(h==0){
//			q->prev = (struct node*)malloc(sizeof(struct node));
//		}
//		ins(q->prev,i,h);

//		q->prev = (struct node*)malloc(sizeof(struct node));
		if(q->prev==NULL){
			q->prev = (struct node*)malloc(sizeof(struct node));
		}
		ins(q->prev,i,h-1);
		
	}
	if(i>pow(2,h)/2){
//		int b = h;
//		h=h-1;
//		if(h==0){
//			q->next = (struct node*)malloc(sizeof(struct node));
//		}
//		ins(q->next,i-(pow(2,b)/2),h);
//		q->next = (struct node*)malloc(sizeof(struct node));
		if(q->next==NULL){
			q->next = (struct node*)malloc(sizeof(struct node));
		}
		ins(q->next,i-(pow(2,h)/2),h-1);
	}
	return 0;			
}

int main(){
	int choice = 0, h = 0, i = 0, k = 0, m = 0,n = 0;
	while(1){
		printf("1.Insert\n2.Delete and sort\n3.Exit\n");
		choice=0;
		scanf("%d",&choice);
		if(choice==1){
			incr=1;height=1;
			start = (struct node*)malloc(sizeof(struct node));
			printf("Enter root node value\n");
			scanf("%d",&start->data);
			start->prev = NULL;
			start->next = NULL;
			printf("Enter number of elements\n");
			scanf("%d",&n);
		}
		m=0;
		int A[n];
		switch(choice){
			case 1:
				i = 0;
				if(start==NULL){
					printf("Enter root node value\n");
					start = (struct node*)malloc(sizeof(struct node));
					scanf("%d",&start->data);
					start->prev = NULL;
					start->next = NULL;
				}
				while(i<n){
					ins(start,incr,height);
					i++;
				}
				changedValue=1;
				break;
			case 2:	
				while(1){
					if(start==NULL){
						printf("No elements in the tree");
						break;
					}
					if(start->prev==NULL){
						m = j+1;
						A[j] = start->data;
						start = NULL;
						break;
					}
					i = incr - 1;
					h = height;
					if(i==0){
						h = height - 1;
						i = pow(2,h);
					}
					arrange(start);
					del(start,i,h,A);
				}
				j = 0; // After process array can be reused for next sorting process again
				changedValue = 1; // So that autoinserted values always start with 1
				if(i<m){
					printf("Sorted data: ");
				}
				for(i=0;i<m;i++){
					printf("%d ",A[i]);
				}
				printf("\n");
				break;       
			case 3:return 0;
			default:printf("Inavlid choice\n");
		}
	}
	return 0;
}