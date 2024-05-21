#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s{
    int data;
    struct node_s *next;
}node_t;

void push(int value,node_t **head,node_t **tail){
    node_t *new=malloc(sizeof(node_t));
    new->data=value;
    new->next=NULL;
    if(*head==NULL){*head=*tail=new;}
    else{(*tail)->next=new;*tail=new;}
}

void print(int co,node_t *head){
    int result,xxxx=co;
    node_t *temp=head;
    while(1){
        if(temp==NULL){break;}
        result=temp->data;
        temp=temp->next;
        if(co!=xxxx && result>0){printf("+");}
        else if(co!=xxxx && result<0){printf("");}
        
        if((--co)==0){printf("%d",result);}
        else if(co==1){
            if(result==1 || result==-1){printf("x");}
            else{printf("%dx",result);}
        }
        else if(result==0){NULL;}
        else if(result==1 || result==-1){printf("x^%d",co);}
        else{printf("%dx^%d",result,co);}
    }
}

void addnode(){
    node_t *head=NULL;
    node_t *tail=NULL;
    


}


int main(){
    char tmp[100],tmp1;
    int aco=0,bco=0,temp;
    node_t *ahead=NULL;
    node_t *atail=NULL;
    node_t *bhead=NULL;
    node_t *btail=NULL;

    while(1){
        scanf("%s",tmp);
        tmp1=getchar();
        push(atoi(tmp),&ahead,&atail);aco++;
        if(tmp1=='\n'){break;}
    }
    while(1){
        scanf("%s",tmp);
        tmp1=getchar();
        push(atoi(tmp),&bhead,&btail);bco++;
        if(tmp1=='\n'){break;}
    }
}