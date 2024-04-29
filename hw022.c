#include <stdio.h>
#include <string.h>

void sol(char tmp[51],int k){
    int a[51]={0},ans[20]={0};
    for(int i=0;i<strlen(tmp);i++){
        if('a'<=tmp[i] && tmp[i]<='z'){a[i]=1;}
        else if('A'<=tmp[i] && tmp[i]<='Z'){a[i]=2;}
    }
    
    int status,co,co2,max=0;
    for(int i=0;i<strlen(tmp);i++){
        status=a[i];co=0,co2=0;
        for(int u=i;u<strlen(tmp);u++){
            co2+=1;co+=1;
            if(a[u]==status){
                if(k*2<=co && co%k==0 && max<co){max=co;}
            }
            else{break;}
            if(co2==k){status=status==1?2:1;co2=0;}
        }
    }
    printf("%d\n",max);
}

int main(){
    char tmp[51];
    int a,k;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%s",tmp);
        scanf("%d",&k);
        sol(tmp,k);
    }
    
}