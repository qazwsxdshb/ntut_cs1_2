#include <stdio.h>
#include <string.h>

int tok(char a[20],char b[10][20]){
    int co=0,x=0,i=0;
    while(a[i]!='\0'){
        if(a[i]==' '){x++;co=0;i++;}
        else{b[x][co++]=a[i++];}
    }
    return x+1;
}

//互補對
int fun(char *a,char b[200]){
    char bb[10][20]={0};
    int x=0;
    x=tok(b,bb);
    for(int i=0;i<x+1;i++){
        if(strcmp(a,bb[i])==0){return 1;}
    }
    return 0;
}

int sol(char a[200],char b[200],char s[200]){
    char tmp[10][20]={0},tmp1[10][20]={0};
    int x=0;
    x=tok(a,tmp);
    for(int i=0;i<x;i++){
        if(fun(tmp[i],b)){return 0;}
    }
    
    x=tok(s,tmp1);
    for(int i=0;i<x+1;i++){
        if(!(fun(tmp1[i],a) || fun(tmp1[i],b))){return 0;}
    }
    return 1;
}

int main(){
    char s[200]={0},S1[100][200]={0},tmp=0;
    int co=0,ans=0,co1=0;
    while(1){
        scanf("%c",&tmp);
        if(tmp=='\n'){break;}
        s[co1++]=tmp;
    }
    scanf("%d",&co);scanf("%c",&tmp);
    for(int i=0;i<co;i++){
        co1=0;
        while(1){
            scanf("%c",&tmp);
            if(tmp=='\n'){break;}
            S1[i][co1++]=tmp;
        }
    }
    char sss[100][200]={0};
    for(int i=0;i<co;i++){
        for(int u=i+1;u<co;u++){
            ans+=sol(S1[i],S1[u],s);
        }
    }
    printf("%d",ans);
}