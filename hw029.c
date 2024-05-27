#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s{
    int data;
    struct node_s *next;
}node_t;
node_t *head=NULL;

void push(int value){
    node_t *Stack=malloc(sizeof(node_t));
    Stack->data=value;
    Stack->next=head;
    head=Stack;
}

void pop(){
    if(head==NULL){printf("Stack is empty\n");return;}
    int result=head->data;
    head=head->next;
    printf("%d\n",result);
}

void top(){
    if(head==NULL){printf("Stack is empty\n");return;}
    printf("%d\n",head->data);
}

int print(){
    int co=0;
    node_t *temp=head;
    while(1){
        if(temp==NULL){return co;}
        int result=temp->data;
        temp=temp->next;co++;
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
            if(head==NULL){printf("Stack is empty\n");}
            head=NULL;
        }
        else if(strcmp(tmp,"top")==0){top();}
        else if(strcmp(tmp,"print")==0){
            if(print()==0){printf("Stack is empty\n");}
        }
    }    
}