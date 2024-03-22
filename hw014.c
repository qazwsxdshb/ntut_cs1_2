#include <stdio.h>
#include <string.h>

void reverse(char tmp[101],int size,char ans[101]){
    for(int i=0;i<=size;i++){
        ans[i-1]=tmp[size-i];
    }
}

void add(char a[101],char b[101],char ans[300]){
    int size=strlen(a)>strlen(b)?strlen(a):strlen(b),tmp=0;
    for(int co=0;co<size;co++){
        int tmp1=(int)a[co]-'0';
        int tmp2=(int)b[co]-'0';
        if(0>tmp1 || tmp1>10){tmp1=0;}
        if(0>tmp2 || tmp2>10){tmp2=0;}
        ans[co]=(char)((tmp1+tmp2+tmp)%10)+'0';
        tmp=(tmp1+tmp2+tmp)/10;
    }
    if(tmp==1){ans[size]=tmp;}
}

int main(){
    char a[101],b[101],ans[300],aa[101],bb[101],result[310];
    scanf("%s",a);
    scanf("%s",b);
    reverse(a,strlen(a),aa);
    reverse(b,strlen(b),bb);

    add(aa,bb,ans);
    reverse(ans,strlen(ans),result);
    printf("%s",result);

    
}