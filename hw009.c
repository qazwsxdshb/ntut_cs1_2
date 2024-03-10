#include <stdio.h>
#include <math.h>

int bin_to_int(char N[10]){
    int co=1,ans=0;
    for(int i=0;i<10;i++){
        ans+=((int)N[i]-'0')*pow(2,10-co);
        co++;
    }
    return ans;
}
void int_to_bin(int tmp){
    char ans[15]={0};
    for(int i=13;i>=0;i--){
        ans[i]=(char)(tmp%2+'0');
        tmp/=2;
    }
    printf("%s\n",ans);
}

int R(int N,int ans){
    if(N==0 || N==1){return ans;}
    else if(N%2==0){R(N/2,1+ans);}
    else{R((N+1)/2,1+ans);}
}

int T(char N[10]){
    int ans=0;
    for(int i=0;i<=bin_to_int(N);i++)
        ans+=R(i,0);
    return ans;
}

int main(){
    int req;
    char N[10];
    while(1){
        scanf("%s",N);
        int_to_bin(T(N));
        scanf("%d",&req);
        if(req==-1){break;}
    }   
}