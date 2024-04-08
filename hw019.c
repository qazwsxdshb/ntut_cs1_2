#include <stdio.h>

void score(int ans[4]){
    int tmp[4]={0},fin=0;
    for(int i=0;i<4;i++){
        for(int u=0;u<4;u++){
            if(ans[i]==ans[u]){tmp[i]++;}
        }
    }
    if(tmp[0]==4){fin=18;}
    else if(tmp[0]==2 && tmp[1]==2 && tmp[2]==2){
        int max=ans[0];
        for(int i=1;i<4;i++){if(max<ans[i]){max=ans[i];}}
        fin=max*2;
    }
    else if(tmp[0]==2 || tmp[1]==2 || tmp[2]==2){
        for(int i=0;i<4;i++){if(2!=tmp[i]){fin+=ans[i];}}
    }
    printf("%d",fin);
}

void sol(int *ans,int tmp,int ud[2],int rl[2],int *back){
    if(tmp<=2){
        int ori=*ans,f=ud[tmp%2];
        *ans=ud[(tmp+1)%2];
        ud[tmp%2]=ori;
        ud[(tmp+1)%2]=*back;
        *back=f;
    }
    else if(3<=tmp){
        int ori=*ans,f=rl[tmp%2];
        *ans=rl[(tmp+1)%2];
        rl[tmp%2]=ori;
        rl[(tmp+1)%2]=*back;
        *back=f;
    }
}

int main(){
    int co,ans[4]={1,1,1,1},ud[4][2]={{3,4},{3,4},{3,4},{3,4}},rl[4][2]={{5,2},{5,2},{5,2},{5,2}},back[4]={6,6,6,6};
    char tmp[5];
    scanf("%d",&co);
    for(int i=0;i<co;i++){
        for(int u=0;u<4;u++){
            scanf("%s",&tmp[u]);
            sol(&ans[u],tmp[u]-'0',ud[u],rl[u],&back[u]);
        }
    }
    score(ans);
}