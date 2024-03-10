#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int gcd(int a,int b){
    if(a%b==0){return b;}
    return gcd(b,a%b);
}

int catch_int(char* tmp,int co){
    int fake=0,d=0;
    while('0'<=(int)*(tmp+co) && (int)*(tmp+co)<='9'){
        fake=fake*10+((int)*(tmp+co)-'0');
        co++;d++;
    }
    if(d==0){return -1;}
    return fake;
}

void sol(int ans[2]){
    if(ans[1]==0){printf("error\n");return;}
    int tmp=gcd(abs(ans[0])%abs(ans[1]),abs(ans[1]));
    if(ans[0]%ans[1]==0){printf("%d\n",ans[0]/ans[1]);}
    else if(abs(ans[0])>abs(ans[1])){
        if(ans[0]>0){printf("%d(%d/%d)\n",ans[0]/ans[1],(ans[0]%ans[1])/tmp,ans[1]/tmp);}
        else{printf("-%d(%d/%d)\n",abs(ans[0])/abs(ans[1]),(abs(ans[0])%abs(ans[1]))/tmp,abs(ans[1])/tmp);}
    }
    else{
        if(ans[0]==0){printf("0\n");}
        else if(ans[0]>0){printf("%d/%d\n",abs(ans[0])/tmp,abs(ans[1])/tmp);}
        else{printf("-%d/%d\n",abs(ans[0])/tmp,abs(ans[1])/tmp);}
    }
}

void start(char tmp[10],int a[3],char cal[1]){
    int i,co=0,neg=1;
    if(*tmp=='-'){co=1;neg=-1;}
    for(i=0;i<3;i++){
        a[i]=catch_int(tmp,co);
        if(a[i]==-1){--i;break;}
        if(a[i]==0){co+=2;}
        else{
            co+=log10(abs(a[i]))+2;
        }
    }
    if(i==3){
        a[0]=neg*(1.0*a[0]*a[2]+a[1]);
        if(a[2]==0){printf("error\n");cal[0]='e';}
        a[1]=a[2];
    }
    else{
        a[0]*=neg;
    }
}

int main(){
    char tmp[10],tmp1[10],cal[1],sqr[1];
    int ans[2],a[3],b[3];
    while(1){
        memset(tmp,0,10);
        memset(tmp1,0,10);
        memset(a,0,3);
        memset(b,0,3);

        scanf("%s",tmp);
        scanf("%s",cal);
        scanf("%s",tmp1);
        
        start(tmp,a,cal);
        start(tmp1,b,cal);

        if(cal[0]=='+'){
            // printf("%d %d %d %d \n\n",a[0],a[1],b[0],b[1]);
            ans[0]=b[1]*a[0]+a[1]*b[0];
            ans[1]=a[1]*b[1];
            sol(ans);
        }
        else if(cal[0]=='-'){
            ans[0]=b[1]*a[0]-a[1]*b[0];
            ans[1]=a[1]*b[1];
            sol(ans);
        }
        else if(cal[0]=='*'){
            ans[0]=b[0]*a[0];
            ans[1]=a[1]*b[1];
            sol(ans);
        }
        else if(cal[0]=='/'){
            if(b[0]>0){
                ans[0]=b[1]*a[0];
                ans[1]=a[1]*b[0];
                sol(ans);
            }
            else{
                ans[0]=b[1]*a[0]*-1;
                ans[1]=a[1]*b[0]*-1;
                sol(ans);
            }
        }
        scanf("%s",sqr);
        if(*sqr=='n'){break;}
    }
}