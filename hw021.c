#include <stdio.h>
#include <string.h>

int tok(char a[200],char b[10][200]){
    int co=0,x=0,i=0;
    while(a[i]!='\0'){
        if(a[i]==' '){x++;co=0;i++;}
        else{b[x][co++]=a[i++];}
    }
    return x+1;
}

int fun(char *a,char b[200]){
    //互補對
    char *token,bb[200]={0};
    memccpy(bb,b,'\0',strlen(b));
    token=strtok(bb," ");
    
    while(token != NULL){
        if(strcmp(a,token)==0){return 1;}
        token=strtok(NULL," ");
    }
    return 0;
}

int sol(char a[200],char b[200],char s[200]){
    char aa[10][200]={0},ss[10][200]={0};
    int x;
    x=tok(a,aa);
    for(int i=0;i<x;i++){
        if(fun(aa[i],b)){return 0;}
    }

    x=tok(s,ss);
    for(int i=0;i<x;i++){
        if(fun(ss[i],a) || fun(ss[i],b)){NULL;}
        else{return 0;}
    }
    return 1;
}

int main(){
    char s[200]={0},S1[10][200]={0},tmp;
    int co,ans=0,co1=0;
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
    for(int i=0;i<co;i++){
        for(int u=i+1;u<co;u++){
            ans+=sol(S1[i],S1[u],s);
        }
    }
    printf("%d",ans);
}