#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a>b?a:b

typedef struct node_s{
    int machine;
    int time;
    struct node_s* next;
}node_t;

node_t *head[10]={0};
node_t *tail[10]={0};

void print(int size,int co){
    int machine[10][100]={0},work[10]={0},mech_time[10]={0},sel,t=0;
    while(co!=t++){
        int min=9999999;
        for(int i=0;i<size;i++){
            if(head[i]==NULL){NULL;}
            else{
                int tmp=max(mech_time[head[i]->machine],work[i]);
                int value=tmp+head[i]->time;
                if(min>value){
                    min=value;sel=i;
                }
            }
        }
        int tmp=max(mech_time[head[sel]->machine],work[sel]);
        for(int i=0;i<head[sel]->time;i++){machine[head[sel]->machine][tmp+i]=sel+1;}
        mech_time[head[sel]->machine]=tmp+head[sel]->time;
        work[sel]=tmp+head[sel]->time;
        head[sel]=head[sel]->next;
    }

    int ans=0,coo[10]={0};
    for(int i=0;i<10;i++){
        for(int u=0;u<100;u++){
            if(machine[i][u]!=0){
                coo[machine[i][u]-1]=max(coo[machine[i][u]-1],u+1);
            }
        }
    }
    for(int i=0;i<10;i++){ans+=coo[i];}
    printf("%d",ans);
}

void newnode(int in_machine,int in_time,int sel){
    node_t *x=malloc(sizeof(node_t));
    x->machine=in_machine;
    x->time=in_time;
    x->next=NULL;
    if(head[sel]==0){head[sel]=x;tail[sel]=x;}
    else{tail[sel]->next=x;}
    tail[sel]=x;
}

int main(){
    int machine,work,pro,in_machine,in_time,co=0;
    node_t *wo=NULL;
    scanf("%d %d",&machine,&work);
    for(int i=0;i<work;i++){
        scanf("%d",&pro);
        for(int u=0;u<pro;u++){
            scanf("%d %d",&in_machine,&in_time);co++;
            newnode(in_machine,in_time,i);
        }
    }
    print(work,co);
}