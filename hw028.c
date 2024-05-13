#include <stdio.h>
#define max(a,b)(a>b?a:b);

typedef struct _project{
    int day;
    int wait;
    int node[10];
}project;

int sol(project pro[101],int endnode,int ans,int pointer){
    int ma=0;
    if(endnode==pointer){return ans+pro[pointer].day;}
    else if(pro[pointer].wait==1){
        ma=sol(pro,endnode,ans+pro[pointer].day,(pro[pointer].node[0]-1));
    }
    else{
        for(int i=0;i<pro[pointer].wait;i++){
            ma=max(ma,sol(pro,endnode,ans+pro[pointer].day,(pro[pointer].node[i]-1)));
        }
    }
    return ma;
}

int main(){
    int co,tmp[101],ma,o,z;
    project pro[101];
    scanf("%d",&o);
    for(int p=0;p<o;p++){
        ma=0;z=0;
        scanf("%d",&co);
        for(int i=0;i<co;i++){
            scanf("%d %d",&pro[i].day,&pro[i].wait);
            for(int u=0;u<pro[i].wait;u++){
                scanf("%d",&pro[i].node[u]);
            }
            if(pro[i].wait==0){tmp[z++]=i;}
        }
        for(int u=0;u<z;u++){
            for(int i=0;i<co;i++){
                ma=max(ma,sol(pro,tmp[u],0,i));
            }
        }
        printf("%d\n",ma);
    }
    
}