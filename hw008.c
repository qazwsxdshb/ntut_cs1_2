#include <stdio.h>
#include <math.h>

int abs(int tmp){
    if(tmp>0){return tmp;}
    return -1*tmp;
}

int catch_int(char* tmp){
    int fake=0,co=0;
    while('0'<=(int)*(tmp+co) && (int)*(tmp+co)<='9'){
        fake=fake*10+((int)*(tmp+co)-'0');
        co++;
    }
    return fake;
}

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
    int n,k;
    while(1){
        scanf("%d",&n);
        if(n==-1){break;}
        scanf("%d",&k);
        if(1<=n && n<=10){
            char ans[n+1];
            gary(n,k,ans,0);
            if(catch_int(ans)!=0){
                for(int i=0;i<n-(int)(log10(abs(catch_int(ans)))+1);i++){
                    printf("0");
                }
            }
            else{
                for(int i=0;i<n-1;i++)
                    printf("0");
            }
            printf("%d\n",catch_int(ans));
        }
        else{
            printf("0");
        }
    }
}