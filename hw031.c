#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b)a>b?a:b

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

void print(int co,node_t *ahead){
    int result,xxxx=co,z=0;
    node_t *temp=ahead;
    while(1){
        if(temp==NULL){break;}
        result=temp->data;
        temp=temp->next;
        if(result!=0){z++;}
        if(co!=xxxx && result>0){printf("+");z++;}
        
        if((--co)==0 && result!=0){printf("%d",result);}
        else if(co==1){
            if(result==0){NULL;}
            else if(result==1){printf("x");}
            else if(result==-1){printf("-x");}
            else{printf("%dx",result);}
        }
        else if(result==0){NULL;}
        else if(result==1){printf("x^%d",co);}
        else if(result==-1){printf("-x^%d",co);}
        else{printf("%dx^%d",result,co);}
    }
    if(z==0){printf("0");}
    printf("\n");
}

int main(){
    char tmp[100],tmp1;
    int aco=0,bco=0,temp,a[100]={0},b[100]={0};
    node_t *addhead=NULL;
    node_t *addtail=NULL;
    node_t *subhead=NULL;
    node_t *subtail=NULL;
    node_t *mulhead=NULL;
    node_t *multail=NULL;

    while(1){
        scanf("%s",tmp);
        tmp1=getchar();
        a[aco++]=atoi(tmp);
        if(tmp1=='\n'){break;}
    }
    while(1){
        scanf("%s",tmp);
        tmp1=getchar();
        b[bco++]=atoi(tmp);
        if(tmp1=='\n'){break;}
    }
    int teemp=max(aco,bco),mulans[100]={0},d=-1;
    for(int i=0;i<teemp;i++){
        int aaa=0,bbb=0;
        if(teemp-aco<=i){aaa=a[i-(teemp-aco)];}
        if(teemp-bco<=i){bbb=b[i-(teemp-bco)];d++;}
        push(aaa+bbb,&addhead,&addtail);
        push(aaa-bbb,&subhead,&subtail);

        for(int u=0;u<aco;u++){
            mulans[d+u]+=a[u]*bbb;
        }
    }
    print(teemp,addhead);
    print(teemp,subhead);
    for(int u=0;u<aco+bco;u++){
        push(mulans[u],&mulhead,&multail);
    }
    print(aco+bco-1,mulhead);
}