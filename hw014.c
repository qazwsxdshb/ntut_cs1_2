#include <stdio.h>
#include <string.h>
#include <math.h>

void reverse(char tmp[300],int size){
    char ans[300];
    for(int i=0;i<size;i++){
        ans[i]=tmp[size-i-1];
    }
    memcpy(tmp,ans,size);
}

void print(char ans[300]){
    char tmp='0';
    for(int i=1;i<strlen(ans);i++){
        if(ans[i]!=tmp){
            tmp='-';
            printf("%c",ans[i]);
        }
    }
    printf("\n");
}

void add(char a[101],char b[101],char ans[300],int neg){
    int size=strlen(a)>strlen(b)?strlen(a):strlen(b),tmp=0;
    for(int co=0;co<size;co++){
        int aa=(int)a[co]-'0';
        int bb=(int)b[co]-'0';
        if(0>=aa || aa>=10){aa=0;}
        if(0>=bb || bb>=10){bb=0;}
        ans[co]=((aa+bb+tmp)%10)+'0';
        tmp=(aa+bb+tmp)/10;
    }
    if(tmp==1){ans[size]=tmp+'0';}

    reverse(ans,strlen(ans));
    
    int xx=0,dd='0';
    for(int i=1;i<strlen(ans);i++){
        if(ans[i]!=dd){
            dd=ans[i];
            xx++;
        }
    }

    if(neg==1 && xx!=0){printf("-");}
    else if(xx==0){printf("0");}
    print(ans);

}

void mul(char a[310],int b,int x,char ans[310]){
    int tmp=0;
    for(int i=0;i<strlen(a);i++){
        tmp=((a[i]-'0')*b+(tmp/10));
        tmp=(ans[i+x]-'0')+(tmp);
        ans[i+x]=(tmp%10)+'0';
    }
    if(tmp/10>0){
        ans[strlen(a)+x]=tmp/10+'0';
    }
}

int cal(char a[101],char b[101]){
    char tmp[101]={0},tmp1[101]={0};
    if(strlen(b)>strlen(a)){
        memcpy(tmp,a,strlen(a));
        memcpy(tmp1,b,strlen(b));
        memset(a,0,99);
        memset(b,0,99);
        memcpy(b,tmp,strlen(tmp));
        memcpy(a,tmp1,strlen(tmp1));
        return 1;
    }
    else{
        for(int i=0;i<strlen(a);i++){
            if(b[i]>a[i]){
                memcpy(tmp,a,strlen(a));
                memcpy(tmp1,b,strlen(b));
                memset(a,0,99);
                memset(b,0,99);
                memcpy(b,tmp,strlen(tmp));
                memcpy(a,tmp1,strlen(tmp1));
                return 1;
            }
            else if(b[i]<a[i]){break;}
        }
    }
    return 0;
}

void sub(char a[101],char b[101],char ans[300],int neg,int nn){
    int size=strlen(a);
    // printf("%s\n%s\n\n",a,b);
    for(int i=0;i<size;i++){
        if(b[i]>'9' || b[i]<'0'){b[i]='0';}
        int x=a[i]-b[i];
        if(x>='0'-ans[i]){ans[i]+=x;}
        else{
            ans[i]+=x+10;
            ans[i+1]-=1;
        }
    }
    reverse(ans,strlen(ans));

    int xx=0,dd='0';
    for(int i=1;i<strlen(ans);i++){
        if(ans[i]!=dd){
            dd=ans[i];
            xx++;
        }
    }
    if((neg+nn)%2==1 && xx!=0){printf("-");}
    else if(xx==0){printf("0");}
    print(ans);
}


int main(){
    int a_neg=0,b_neg=0;
    char a[100]={0},b[100]={0},ans[300];
    scanf("%s",a);
    scanf("%s",b);
    reverse(a,strlen(a));
    reverse(b,strlen(b));
    if(a[strlen(a)-1]=='-'){a[strlen(a)-1]=0;a_neg++;}
    if(b[strlen(b)-1]=='-'){b[strlen(b)-1]=0;b_neg++;}
    reverse(a,strlen(a));
    reverse(b,strlen(b));

    int neg=cal(a,b);

    reverse(a,strlen(a));
    reverse(b,strlen(b));

    memset(ans,'0',299);
    ans[299]='\0';
    if(a_neg==0 && b_neg==0){
        add(a,b,ans,0);
        memset(ans,'0',299);
        ans[299]='\0';
        sub(a,b,ans,neg,0);
    }
    else if(b_neg==1 && a_neg==0){
        sub(a,b,ans,neg,0);
        memset(ans,'0',299);
        ans[299]='\0';
        add(a,b,ans,0);
    }
    else if(b_neg==0 && a_neg==1){
        sub(a,b,ans,neg,1);
        memset(ans,'0',299);
        ans[299]='\0';
        add(a,b,ans,1);
    }
    else{
        add(a,b,ans,1);
        memset(ans,'0',299);
        ans[299]='\0';
        sub(a,b,ans,neg,1);
    }

    if((a_neg+b_neg)%2==1){printf("-");}
    memset(ans,'0',299);
    ans[299]='\0';
    for(int i=0;i<strlen(b);i++){
        mul(a,b[i]-'0',i,ans);
    }
    reverse(ans,strlen(ans));
    print(ans);
}