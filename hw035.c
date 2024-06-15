#include <stdio.h>
#include <stdlib.h>
#define max(a,b)(a>b?a:b);

typedef struct node_s{
    int time;
    int waiteNodeNum;
    struct node_s *waitNode[100];
}node_t;

int search(node_t pointer){
    int ma=0,i=0;
    while(pointer.waitNode[i]!=0){
        int tmp=search(*pointer.waitNode[i++]);
        ma=max(ma,tmp);
    }
    return ma+pointer.time;
}

int main(){
    int oo;
    scanf("%d",&oo);
    for(int d=0;d<oo;d++){
        node_t root[100]={0,0,{0}};
        int co,num,tmp,ans=0,start[100]={0},x=0;
        scanf("%d",&co);
        for(int u=0;u<co;u++){
            scanf("%d %d",&root[u].time,&num);
            for(int i=0;i<num;i++){
                scanf("%d",&tmp);
                root[u].waitNode[i]=&root[tmp-1];
            }
            if(num==0){start[x++]=u;}
        }
        ans=search(root[0]);
        for(int i=0;i<x;i++){
            ans=max(ans,search(root[start[i]]));
        }
        printf("%d\n",ans);
    }

}