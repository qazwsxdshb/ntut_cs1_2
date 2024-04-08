#include <stdio.h>

void sol(int *ans,char tmp,int ud[2],int rl[2]){
    if(tmp==1){
        *ans=ud[0];
    }
}

void score(int ans[4]){
    int tmp[4]={0};
    for(int i=0;i<4;i++){
        for(int u=0;u<4;u++){
            if(ans[i]==ans[u]){tmp[i]++;}
        }
    }
    if(tmp[0]==4){printf("18");}
    else if(tmp[0]==3 || tmp[1]==3){printf("0");}
    else if(tmp[0]==2 && tmp[1]==2 && tmp[2]==2){
        int max=ans[0];
        for(int i=1;i<4;i++){if(max<ans[i]){max=ans[i];}}
        printf("%d",max);
    }
    else if(tmp[0]==2 || tmp[1]==2 || tmp[2]==2){
        int aa=0;
        for(int i=0;i<4;i++){if(2!=tmp[i]){aa+=ans[i];}}
        printf("%d",aa);
    }
    else{printf("0");}
}

int main(){
    int co,ans[4]={1,1,1,1},ud[4][2]={{3,4},{3,4},{3,4},{3,4}},rl[4][2]={{5,2},{5,2},{5,2},{5,2}};
    char tmp[5];
    scanf("%d",&co);
    for(int i=0;i<co;i++){
        for(int u=0;u<4;u++){
            scanf("%s",&tmp[u]);
            sol(&ans[u],tmp[u],ud[u],rl[u]);
        }
    }
    for(int u=0;u<4;u++){
        printf("%d ",ans[u]);
    }printf("\n");
    score(ans);
}