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
