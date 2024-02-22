#include <stdio.h>
#include <math.h>

int binlen(int tmp){
    int ans=0;
    while(tmp>0)
    {
        tmp>>=1;
        if(tmp%2==1){ans+=1;}
    }
    return ans;
}

int main(){
    int tmp1,tmp2=0,fu=0,ans=0;
    for(int i=0;i<5;i++){
        scanf("%d",&tmp1);
        if(tmp1>0){
            tmp2<<=tmp1;
            tmp2+=(int)pow(2,tmp1-1);
            if (tmp2>=8)
            {
                ans+=binlen(tmp2>>2);
                tmp2&=0x7;
            }
        }
        else{fu++;}
        if(fu==3){fu=0,tmp2=0;}
    }
    printf("%d\n%d %d %d",ans,tmp2&1,tmp2&2 ? 1:0,tmp2&4 ? 1:0);
}