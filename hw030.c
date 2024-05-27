#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s{
    int data;
    struct node_s *next;
}node_t;

node_t *head=NULL;
node_t *tail=NULL;

void push(int value){
    node_t *Stack=malloc(sizeof(node_t));
    Stack->data = value;
    Stack->next = NULL;
    if(tail==NULL){
        head=tail=Stack;
    }
    else{
        tail->next=Stack;
        tail=Stack;
    }
}

void pop(){
    if(head==NULL){printf("Queue is empty\n");return;}
    int result=head->data;
    head=head->next;
    printf("%d\n",result);
}

void front(){
    if(head==NULL){printf("Queue is empty\n");return;}
    printf("%d\n",head->data);
}

void print(){
    int result;
    node_t *temp=head;
    while(1){
        if(temp==NULL){break;}
        result=temp->data;
        temp=temp->next;
        printf("%d\n",result);
    }
}

int main(){
    int co=0,value;
    char tmp[10];
    scanf("%d",&co);
    for(int i=0;i<co;i++){
        scanf("%s",tmp);
        if(strcmp(tmp,"push")==0){scanf("%d",&value);push(value);}
        else if(strcmp(tmp,"pop")==0){pop();}
        else if(strcmp(tmp,"empty")==0){
            if(head==NULL){printf("Queue is empty\n");}
            head=tail=NULL;
        }
        else if(strcmp(tmp,"front")==0){front();}
        else if(strcmp(tmp,"print")==0){
            if(head==NULL){printf("Queue is empty\n");}
            else{print();}
        }
    }
}