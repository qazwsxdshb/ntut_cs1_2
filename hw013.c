#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a,int b){
    if(a%b==0){return b;}
    return gcd(b,a%b);
}
int if_int(int a,int b){
    return (float)abs(a)/(float)abs(b)-abs(a)/abs(b)==0? 1:0;
}

int int_in(char ans[],int a,int co){
    char tmp[100];
    int tmpco=0;
    while(a>0){
        tmp[tmpco]=(char)(a%10+'0');
        a/=10;tmpco++;
    }
    while (tmpco>0){
        ans[co++]=tmp[--tmpco];
    }
    return co;
}


int main(){
    int count,co;
    scanf("%d",&count);
    int x1,y1,x2,y2,mneg,bneg;
    for(int i=0;i<count;i++){
        char ans[100]="y = ";
        co=4;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        mneg=(y1-y2)*(x1-x2)>0? 1 : -1;
        int m1=abs(y1-y2);
        int m2=abs(x1-x2);

        bneg=(x2*y1-x1*y2)*(x2-x1)>0? 1 : -1;
        float b1=abs(x2*y1-x1*y2);
        float b2=abs(x2-x1);
        
        if(m1==0){NULL;}
        else if(if_int(m1,m2)){
            if(mneg==-1){ans[co++]='-';}
            if(m1/m2!=1){
                co=int_in(ans,m1/m2,co);
            }
            ans[co++]='x';

            if(b1!=0){
                ans[co++]=' ';
                if(bneg==-1){ans[co++]='-';}
                else{ans[co++]='+';}
                ans[co++]=' ';
            }
        }
        else{
            if(mneg==-1){ans[co++]='-';}
            int tmp=gcd(m1,m2);
            co=int_in(ans,m1/tmp,co);
            ans[co++]='/';
            co=int_in(ans,m2/tmp,co);
            ans[co++]='x';

            if(b1!=0){
                ans[co++]=' ';
                if(bneg==-1){ans[co++]='-';}
                else{ans[co++]='+';}
                ans[co++]=' ';
            }
        }
        
        if(b1==0){NULL;}
        else if(if_int(b1,b2)){
            if(m1==0 && bneg==-1){ans[co++]='-';}
            co=int_in(ans,b1/b2,co);
        }
        else{
            if(m1==0 && bneg==-1){ans[co++]='-';}
            int tmp=gcd(b1,b2);
            co=int_in(ans,b1/tmp,co);
            ans[co++]='/';
            co=int_in(ans,b2/tmp,co);
        }


        printf("%s\n",ans,co);
        memset(ans,0,100);
    }
}