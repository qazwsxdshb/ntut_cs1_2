#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int catch_int(char* tmp,int co){
    int fake=0;
    while('0'<=(int)*(tmp+co) && (int)*(tmp+co)<='9'){
        fake=fake*10+((int)*(tmp+co)-'0');
        co++;
    }
    return fake;
}

int main(){
    char tmp[10],tmp1[10],cal[1];
    int co=0,neg=1,i;
    int a[3]={0},b[3]={0};

    scanf("%s",tmp);
    scanf("%s",cal);
    scanf("%s",tmp1);

    if(*tmp=='-'){co=1;neg=-1;}
    for(i=0;i<3;i++){
        a[i]=catch_int(tmp,co);
        if(a[i]==0){--i;break;}
        co+=log10(abs(a[i]))+2;
    }
    if(i==3){
        a[0]=neg*(1.0*a[0]*a[2]+a[1]);
        a[1]=a[2];
    }
    

    co=0,neg=1;
    if(*tmp1=='-'){*tmp1+=1;neg=-1;}
    for(i=0;i<3;i++){
        b[i]=catch_int(tmp1,co);
        if(b[i]==0){--i;break;}
        co+=log10(abs(b[i]))+2;
    }
    if(i==3){
        b[0]=neg*(1.0*b[0]*b[2]+b[1]);
        b[1]=b[2];
    }

    int ans[2];
    if(cal[0]=='+'){
        ans[0]=b[1]*a[0]+a[1]*b[0];
        ans[1]=a[1]*b[1];
    }
    else if(cal[0]=='-'){
        ans[0]=b[1]*a[0]-a[1]*b[0];
        ans[1]=a[1]*b[1];
    }
    printf("%d %d",ans[0],ans[1]);
}