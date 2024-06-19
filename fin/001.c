#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split1(char string[1000],char str[100],char x[100]){
    char tmp[100]={0};
    int co=0,xx=0;
    for(int i=0;i<strlen(string);i++){
        if(string[i]==' '){
            if(xx!=0){printf(" ");}
            if(strcmp(str,tmp)==0){printf("%s ",x);}
            printf("%s",tmp);
            for(int u=0;u<co;u++){tmp[u]=0;}
            co=0;xx++;
        }
        else{tmp[co++]=string[i];}
    }
    if(xx!=0){printf(" ");}
    if(strcmp(str,tmp)==0){printf("%s ",x);}
    printf("%s",tmp);
}

void split2(char string[1000],char str[100],char x[100]){
    char tmp[100]={0};
    int co=0,xx=0;
    for(int i=0;i<strlen(string);i++){
        if(string[i]==' '){
            if(xx!=0){printf(" ");}
            if(strcmp(str,tmp)==0){printf("%s",x);}
            else{printf("%s",tmp);}
            for(int u=0;u<co;u++){tmp[u]=0;}
            co=0;xx++;
        }
        else{tmp[co++]=string[i];}
    }
    if(xx!=0){printf(" ");}
    if(strcmp(str,tmp)==0){printf("%s",x);}
    else{printf("%s",tmp);}
}

void split3(char string[1000],char str[100],char x[100]){
    char tmp[100]={0};
    int co=0,xx=0,cccc=0;
    for(int i=0;i<strlen(string);i++){
        if(string[i]==' '){
            if(strcmp(str,tmp)==0){cccc=1;}
            else if(xx!=0){printf(" ");}
            if(cccc==0){printf("%s",tmp);}
            cccc=0;
            for(int u=0;u<co;u++){tmp[u]=0;}
            co=0;xx++;
        }
        else{tmp[co++]=string[i];}
    }
    if(xx!=0){printf(" ");}
    if(strcmp(str,tmp)==0){NULL;}
    else{printf("%s",tmp);}
}

void split4(char string[1000],int N){
    char tmp[100]={0},ans[100][100]={0};
    int co=0,xx=0,anss[100]={0};
    for(int i=0;i<strlen(string);i++){
        if(string[i]==' '){
            int cc=0;
            for(int u=0;u<xx;u++){
                if(strcmp(tmp,ans[u])==0){anss[u]+=1;cc++;break;}
            }
            if(cc==0){
                anss[xx]+=1;
                for(int u=0;u<strlen(tmp);u++){ans[xx][u]=tmp[u];}
                xx++;
            }
            for(int u=0;u<100;u++){tmp[u]=0;}
            co=0;
        }
        else{tmp[co++]=string[i];}
    }

    int cc=0;
    for(int u=0;u<xx;u++){
        if(strcmp(tmp,ans[u])==0){anss[u]+=1;cc++;break;}
    }
    if(cc==0){
        for(int u=0;u<strlen(tmp);u++){ans[xx][u]=tmp[u];}
        xx++;
    }

    for(int i=0;i<strlen(string);i++){
        if(string[i]==' '){
            for(int u=0;u<xx;u++){
                if(strcmp(tmp,ans[u])==0){
                    if(anss[u]>=N){
                        printf("%s ",tmp);
                    }
                }
            }
            for(int u=0;u<100;u++){tmp[u]=0;}
            co=0;
        }
        else{tmp[co++]=string[i];}
    }
    for(int u=0;u<xx;u++){
        if(strcmp(tmp,ans[u])==0){
            if(anss[u]>=N){
                printf("%s ",tmp);
            }
        }
    }
}

void split5(char string[100]){
    char tmp[100]={0},ans[100][100]={0};
    int co=0,xx=0,anss[100]={0};
    for(int i=0;i<strlen(string);i++){
        if(string[i]==' '){
            int cc=0;
            for(int u=0;u<xx;u++){
                if(strcmp(tmp,ans[u])==0){anss[u]+=1;cc++;break;}
            }
            if(cc==0){
                anss[xx]+=1;
                for(int u=0;u<strlen(tmp);u++){ans[xx][u]=tmp[u];}
                xx++;
            }
            for(int u=0;u<100;u++){tmp[u]=0;}
            co=0;
        }
        else{tmp[co++]=string[i];}
    }

    int cc=0;
    for(int u=0;u<xx;u++){
        if(strcmp(tmp,ans[u])==0){anss[u]+=1;cc++;break;}
    }
    if(cc==0){
        for(int u=0;u<strlen(tmp);u++){ans[xx][u]=tmp[u];}
        xx++;
    }

    for(int i=0;i<3;i++){
        int xxx=-1,z=0;
        for(int o=0;o<xx;o++){
            if((xxx==-1 || anss[o]<xxx) && anss[o]!=-1){z=o;xxx=anss[o];}
        }
        printf("%s:%d\n",ans[z],anss[z]);
        anss[z]=-1;
    }
}

int main(){
    char str[100]={0},str1[100]={0},string[1000]={0},tmp=0;
    int co=-1,cco;
    while(tmp!='\n'){
        scanf("%s",str);tmp=getchar();
        if(co!=-1){string[co]=' ';}
        for(int i=0;i<strlen(str);i++){
            string[i+co+1]=str[i];
        }
        co+=strlen(str)+1;
    }
    scanf("%s",str);scanf("%s",str1);scanf("%d",&cco);
    if(cco==1){
        split1(string,str,str1);
    }
    else if(cco==2){
        split2(string,str,str1);
    }
    else if(cco==3){split3(string,str,str1);}
    else if(cco==4){scanf("%d",&cco);split4(string,cco);}
    else if(cco==5){split5(string);}
}