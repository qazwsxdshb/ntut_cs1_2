#include <stdio.h>
#include <string.h>

void print(int a,int x){
    char ans[10];
    int co=0,d=0;
    int tmp=a;
    while(tmp>0){tmp/=10;d++;}
    for(int i=d;i<x;i++){printf("0 ");}
    while(a>0){
        ans[co++]=a%10+'0';
        a/=10;
    }
    for(int i=co-1;i>0;i--){
        printf("%c ",ans[i]);
    }
    printf("%c\n",ans[0]);
}

void sorted(int tmp[100],int co,int xxx){
    int x,y=0;
    for(int u=0;u<co;u++){
        x=0;
        for(int i=u;i<co;i++){
            if(tmp[i]>=x){
                x=tmp[i];
                y=i;
            }
        }
        int z=tmp[u];
        tmp[u]=tmp[y];
        tmp[y]=z;
    }
    x=0;
    printf("%d\n",co);
    for(int i=co-1;i>=0;i--){
        if(tmp[i]!=x){
            print(tmp[i],xxx);
        }
        x=tmp[i];
    }
}

int in(int tmp[10],int x){
    for(int i=0;i<10;i++){
        if(tmp[i]==x){return 1;}
    }
    return 0;
}

void sol(int b[100],int a,int co){
    int ans[100]={0},x=0,xx=0,stop,z[10],dd=0;
    for(int i=0;i<co-a+1;i++){
        xx=0;stop=0;
        memset(z,-1,40);
        // for(int i=0;i<10;i++){printf("%d ",z[i]);}
        // printf("\n");
        for(int u=i;u<i+a;u++){
            xx*=10;
            xx+=b[u];
            if(in(z,b[u])){stop=1;}
            z[u-i]=b[u];
        }
        if(stop==0){ans[dd]=xx;dd++;}
    }
    sorted(ans,dd,a);
}

int main(){
    int a,b[100],co=0,tmp;
    scanf("%d",&a);
    while(1){
        scanf("%d",&tmp);
        if(tmp==-1){break;}
        b[co++]=tmp;
    }
    sol(b,a,co);
}