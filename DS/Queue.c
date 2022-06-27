//Queue
#include<stdio.h>
#define que_size 5

struct queue{
	int data[que_size];
	int head,count;
};
typedef struct queue que;

void queue_enqueue(que *q,int data){
	printf("enqueue %d\n",data);
	if(q->count==que_size){
		printf("-- Overflow\n");
		return;
	}
	q->data[(q->head+q->count)%que_size]=data;
    q->count++;
}

void queue_dequeue(que *q){
	printf("dequeue\n");
	if(q->count==0){
		printf("-- Underflow\n");
		return;
	}
	q->head++;
    q->head%=que_size;
    q->count--;
}


void queue_display(que *q){
	printf("DISPLAY\n");
	if(q->count==0){
		printf("-- queue is empty\n");
		return;
	}
	printf("--  ");
    for(int i=0;i<q->count;i++){
        printf("%d ",q->data[(q->head+i)%que_size]);
    }
	printf("\n");
}

/*
// Priority queue
que s1,s2,s3;
void priority_enqueue(int priority,int data){
	switch (priority){
		case 1:
			queue_enqueue(&s1,data);
			break;
		case 2:
			queue_enqueue(&s2,data);
			break;
		case 3:
			queue_enqueue(&s3,data);
			break;
		
		default:
			break;
	}
}

void priority_dequeue(){
	if(s1.count!=0){
		queue_dequeue(&s1);
	}
	else if(s2.count!=0){
		queue_dequeue(&s2);
	}
	else if(s3.count!=0){
		queue_dequeue(&s3);
	}
}
*/

int main(){
	que s;
	s.count=0;
    s.head=0;
	queue_display(&s);
	queue_enqueue(&s,2);
	queue_enqueue(&s,4);
	queue_enqueue(&s,6);
	queue_display(&s);
	queue_dequeue(&s);
	queue_dequeue(&s);
	queue_dequeue(&s);
	queue_dequeue(&s);
	queue_enqueue(&s,2);
	queue_enqueue(&s,4);
	queue_enqueue(&s,6);
	queue_enqueue(&s,2);
	queue_display(&s);
	queue_enqueue(&s,4);
	queue_enqueue(&s,6);
	queue_display(&s);
	return 0;
}
