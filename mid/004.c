#include <stdio.h>
#include <string.h>

void cal(int score[3],int x,int *total,int tmp,int ans[10][2]){
    ans[tmp][0]+=1;
    for(int i=0;i<x;i++){
        if(score[2]!=-1){(*total)++;ans[score[2]][1]+=1;score[2]=-1;}
        if(score[1]!=-1){ans[score[1]][1]+=1;}
        if(score[0]!=-1){ans[score[0]][1]+=1;}
        score[2]=score[1];
        score[1]=score[0];
        if(i==0){score[0]=tmp;ans[tmp][1]+=1;}
        else{score[0]=-1;}
    }
}

int main(){
    int co,tmp=0,x=0,total=0,score[3]={0},ans[10][2]={0};
    char player[10][10],input;
    memset(score,-1,12);
    for(int i=0;i<9;i++){
        scanf("%d",&co);
        for(int u=0;u<co*2;u++){
            scanf("%c",&input);
            if(u%2==1){
                player[i][u/2]=input;
            }
        }
    }
    scanf("%d",&co);
    int d=co;
    while(d>0){
        if(player[tmp%10][tmp/10]=='O'){x++;d--;}
        if(x==3){memset(score,-1,12);x=0;}
        else{
            if(player[tmp%10][tmp/10]=='H'){cal(score,4,&total,tmp%10,ans);}
            else if(player[tmp%10][tmp/10]=='3'){cal(score,3,&total,tmp%10,ans);}
            else if(player[tmp%10][tmp/10]=='2'){cal(score,2,&total,tmp%10,ans);}
            else if(player[tmp%10][tmp/10]=='1'){cal(score,1,&total,tmp%10,ans);}
        }
        tmp++;
    }
    printf("%d\n",total);
    x=0;
    for(int u=0;u<3;u++){
        for(int i=0;i<10;i++){if(ans[x][1]<ans[i][1]){x=i;}}
        printf("%d %d %d\n",x+1,ans[x][0],ans[x][1]);
        ans[x][1]=-1;
    }
}