#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dnode_s {
    int data;
    struct dnode_s *front;
    struct dnode_s *back;
} node_t;
node_t *head=NULL;
node_t *tail=NULL;

void addFront(int value){
    node_t *stack=malloc(sizeof(node_t));
    stack->data=value;
    stack->front=NULL;
    stack->back=NULL;
    if(head==NULL){
        head=tail=stack;
    }
    else{
        tail->front=stack;
        stack->back=tail;
        tail=stack;
    }
}

void addBack(int value){
    node_t *stack=malloc(sizeof(node_t));
    stack->data=value;
    stack->front=NULL;
    stack->back=NULL;
    if(head==NULL){
        head=tail=stack;
    }
    else{
        head->back=stack;
        stack->front=head;
        head=stack;
    }
}

void removeFront(){
    if(tail==NULL){printf("Double link list is empty\n");}
    else{
        if(tail->back==NULL){head=tail=NULL;return;}
        tail=tail->back;
        tail->front=NULL;
    }
}

void removeBack(){
    if(head==NULL){printf("Double link list is empty\n");}
    else{
        if(head->front==NULL){head=tail=NULL;return;}
        head=head->front;
        head->back=NULL;
    }
}

void nodeinsert(int node,int value){
    node_t *stack=malloc(sizeof(node_t));
    stack->data=value;
    node_t *tmp=tail;
    if(node==2){
        if(tmp->back==NULL){printf("Invalid command\n");return;}tmp=tmp->back;
        stack->front=tmp;
        stack->back=tmp->back;
        tmp->back->front=stack;
        tmp->back=stack;
    }
    else{
        for(int i=0;i<node-1;i++){
            tmp=tmp->back;
            if(tmp==NULL){printf("Invalid command\n");return;}
        }
        if(tmp->back==NULL){printf("Invalid command\n");return;}
        stack->front=tmp;
        stack->back=tmp->back;
        tmp->back->front=stack;
        tmp->back=stack;
    }
}

void noderemove(int node){
    node_t *tmp=tail;
    if(node==1){
        if(tmp->back==NULL){printf("Invalid command\n");return;}
        tail=tail->back;
        free(tail->front);
    }
    else{
        for(int i=0;i<node-2;i++){
            tmp=tmp->back;
            if(tmp==NULL){printf("Invalid command\n");return;}
        }
        if(tmp->back==NULL){printf("Invalid command\n");return;}
        if(tmp->back==NULL){printf("Invalid command\n");return;}
        if(tmp->back->back==NULL){tmp->back->front=NULL;tmp->back=NULL;return;}
        tmp->back=tmp->back->back;
        tmp->back->front=tmp;
    }
}

void print(){
    node_t *tmp=tail;
    if(tail==NULL){printf("Double link list is empty\n");}
    else{
        while(1){
            printf("%d\n",tmp->data);
            if(tmp->back==NULL){break;}
            tmp=tmp->back;
        }
    }
}

int main(){
    int co,cotmp,cotmp2;
    char tmp[20];
    scanf("%d",&co);
    for(int i=0;i<co;i++){
        scanf("%s",tmp);
        if(strcmp(tmp,"addFront")==0){
            scanf("%d",&cotmp);
            addFront(cotmp);
        }
        else if(strcmp(tmp,"addBack")==0){
            scanf("%d",&cotmp);
            addBack(cotmp);
        }
        else if(strcmp(tmp,"removeFront")==0){removeFront();}
        else if(strcmp(tmp,"removeBack")==0){removeBack();}
        else if(strcmp(tmp,"empty")==0){
            if(tail==NULL){printf("Double link list is empty\n");}
            head=tail=NULL;
        }
        else if(strcmp(tmp,"insert")==0){
            scanf("%d %d",&cotmp,&cotmp2);
            nodeinsert(cotmp,cotmp2);
        }
        else if(strcmp(tmp,"remove")==0){
            scanf("%d",&cotmp);
            noderemove(cotmp);
        }
        else if(strcmp(tmp,"print")==0){print();}
    }
}