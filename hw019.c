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

void sol(int *ans,int tmp,int ud[5]){
    int d=(tmp>=3?2:0);
    int ori=*ans,f=ud[tmp%2+d];
    *ans=ud[(tmp+1)%2+d];
    ud[tmp%2+d]=ori;
    ud[(tmp+1)%2+d]=ud[4];
    ud[4]=f;
}

int main(){
    int co,ans[4]={1,1,1,1},ud[4][5]={{3,4,5,2,6},{3,4,5,2,6},{3,4,5,2,6},{3,4,5,2,6}};
    char tmp[5];
    scanf("%d",&co);
    for(int i=0;i<co;i++){
        for(int u=0;u<4;u++){
            scanf("%s",&tmp[u]);
            sol(&ans[u],tmp[u]-'0',ud[u]);
        }
    }
    score(ans);
}