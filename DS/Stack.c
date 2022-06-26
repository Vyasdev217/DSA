//Stack
#include<stdio.h>
#define stk_size 5
void printarr(int *arr,int size){
	for(int i=0;i<size;i++){
		printf("%d ",*(arr+i));
	}
}

struct stack{
	int data[stk_size];
	int count;
};
typedef struct stack stk;

void stack_push(stk *s,int data){
	printf("PUSH %d\n",data);
	if(s->count==stk_size){
		printf("-- Overflow\n");
		return;
	}
	s->data[s->count]=data;
	s->count++;
}

void stack_pop(stk *s){
	printf("POP\n");
	if(s->count==0){
		printf("-- Underflow\n");
		return;
	}
	s->count--;
}

void stack_peep(stk *s){
	printf("PEEP\n");
	if(s->count==0){
		printf("-- Stack is empty\n");
		return;
	}
	printf("--  ");
	printf("%d\n",s->data[s->count-1]);
}

void stack_display(stk *s){
	printf("DISPLAY\n");
	if(s->count==0){
		printf("-- Stack is empty\n");
		return;
	}
	printf("--  ");
	printarr(s->data,s->count);
	printf("\n");
}

int main(){
	stk s;
	s.count=0;
	stack_display(&s);
	stack_push(&s,2);
	stack_push(&s,4);
	stack_push(&s,6);
	stack_peep(&s);
	stack_display(&s);
	stack_pop(&s);
	stack_peep(&s);
	stack_pop(&s);
	stack_pop(&s);
	stack_pop(&s);
	stack_push(&s,2);
	stack_push(&s,4);
	stack_push(&s,6);
	stack_push(&s,2);
	stack_display(&s);
	stack_push(&s,4);
	stack_push(&s,6);
	stack_display(&s);
	return 0;
}
