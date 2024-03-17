#include <stdio.h>
#include <string.h>
#include <math.h>

int char_to_int(char *input,int base){
    int xx=strlen(input)-1,ans=0,co=0;
    while(co<strlen(input)){
        if('A'<=input[co] && input[co]<='Z'){
            ans+=(input[co]-'A'+10)*(int)floor(pow(base,xx));
        }
        else{
            ans+=(input[co]-'0')*(int)floor(pow(base,xx));
        }
        co++;
        xx--;
    }
    return ans;
}

int int_to_base(int input,char ans[100],int base){
    int tmp,co=0;
    while(input>0){
        tmp=input%base;
        input/=base;
        if(tmp>=10){
            ans[co]=(char)(tmp-10+'A');
        }
        else{
            ans[co]=(char)(tmp+'0');

        }
        co++;
    }
    return co;
}

void rever(char * ans,int x){
    if(x==0){printf("0");}
    for(int i=0;i<x;i++){
        printf("%c",ans[x-i-1]);
    }
}

int main(){
    int base,b,tmp;
    char input[10],ans[100];
    scanf("%d",&base);
    scanf("%s",input);
    scanf("%d",&b);
    tmp=char_to_int(input,base);
    int x=int_to_base(tmp,ans,b);
    rever(ans,x);
}