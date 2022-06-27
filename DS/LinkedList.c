//LinkedList
#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int data;
	struct NODE *next;
};
typedef struct NODE node;

node* list_append(node *head,int data){
	printf("APPEND %d\n",data);
    node *new_node=(node*) malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    if(head==NULL)head=new_node;
    else{
        node *pointer=head;
        while (pointer->next!=NULL){
            pointer=pointer->next;
        }
        pointer->next=new_node;
    }
    return head;
}

node* list_pop(node *head){
	printf("POP\n");
    if(head==NULL){
        printf("-- list is empty\n");
        return head;
    }
    node *pointer=head;
    if(pointer->next==NULL){
        printf("-- deleted a node with value %d\n",pointer->data);
        free(head);
        head=NULL;
        return head;
    }
    while (pointer->next->next!=NULL) pointer=pointer->next;
    printf("-- deleted a node with value %d\n",pointer->next->data);
    free(pointer->next);
    pointer->next=NULL;
    return head;
}

void list_display(node *head){
	printf("DISPLAY\n");
	if(head==NULL){
		printf("-- list is empty\n");
		return;
	}
	printf("--  ");
    node *pointer=head;
    while (pointer!=NULL){
        printf("%d ",pointer->data);
        pointer=pointer->next;
    }
	printf("\n");
}

node* list_insert(node *head,int index,int data){
	printf("INSERT %d AT INDEX %d\n",data,index);
    node *new_node=(node*) malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    if(index==0){
        new_node->next=head;
        head=new_node;
        return head;
    }
    else{
        node *pointer=head;
        for(int i=1;i<index;i++){
            if(pointer->next==NULL)break;
            pointer=pointer->next;
        }
        new_node->next=pointer->next;
        pointer->next=new_node;
    }
    return head;
}
/*
node* list_remove(node *head,int index){
    printf("REMOVE NODE AT INDEX %d\n",index);
	node *pointer,*pointer2;
    node *dummy_node;
    dummy_node=(node*) malloc(sizeof(node));
    dummy_node->next=head;
    head=dummy_node;
    pointer=head;
    for(int i=0;i<index;i++){
        if(pointer==NULL){
            printf("-- invalid range");
            head=dummy_node->next;
            free(dummy_node);
            return head;
        }
        pointer=pointer->next;
    }
    pointer2=pointer->next;
    pointer->next=pointer2->next;
    int val=pointer2->data;
    free(pointer2);
    free(dummy_node);
    printf("-- removed node at index %d with value %d\n",index,val);
    return head;
}
*/
int main(){
	node *head;
  head=NULL;
	list_display(head);
	head=list_append(head,2);
	head=list_append(head,4);
	head=list_append(head,6);
	list_display(head);
	head=list_pop(head);
	head=list_pop(head);
	head=list_pop(head);
	head=list_pop(head);
	head=list_append(head,2);
	head=list_append(head,4);
	head=list_append(head,6);
	head=list_append(head,2);
	list_display(head);
	head=list_append(head,4);
	head=list_append(head,6);
	list_display(head);
  head=list_insert(head,0,99);
  head=list_insert(head,3,99);
  head=list_insert(head,30,99);
  list_display(head);
  /*
  head=list_remove(head,2);
  list_display(head);
  head=list_remove(head,5);
  list_display(head);
  head=list_insert(head,3,0);
  list_display(head);
  //head=list_remove(head,20);
  */
	return 0;
}
