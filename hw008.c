#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void gary(int n,int k,char ans[],int co){
    if(n==1){
        ans[co]=(char)(k+(int)'0');
        return;
    }
    else if(k<pow(2,(n-1))){
        ans[co]='0';
        gary(n-1,k,ans,++co);
    }
    else if(k>=pow(2,(n-1))){
        ans[co]='1';
        gary(n-1,pow(2,n)-1-k,ans,++co);
    }
}

int main(){
    int n=0,k;
    while(1){
        scanf("%d",&n);
        if(n==-1){break;}
        scanf("%d",&k);
        if(1<=n && n<=8){
            char ans[n+1];
            gary(n,k,ans,0);
            for(int i=0;i<n-(int)(log10(abs(atoi(ans)))+1);i++){
                printf("0");
            }
            printf("%d\n",atoi(ans));
        }
        else{
            printf("0");
        }
    }
}