#include <stdio.h>

int main(){
    int count=0,input;
    char arr[3]={'A','B','C'};
    int win[3]={0},score[3]={0};

    scanf("%d\n",&input);
    while (count!=input)
    {
        char play1,play2;
        int a=0,b=0;
        scanf("%c %c\n",&play1,&play2);
        for(int i=0;i<4;i++){
            int tmp1,tmp2;
            scanf("%d %d\n",&tmp1,&tmp2);
            a+=tmp1;
            b+=tmp2;
        }
        for(int i=0;i<3;i++){
            if(arr[i]==play1){
                score[i]+=a;
                if(a>b){
                    win[i]++;
                }
            }
            if(arr[i]==play2){
                score[i]+=b;
                if(a<b){
                    win[i]++;
                }
            }
        }
        count++;
    }

    int a=0,b=0;
    for(int i=0;i<3;i++){
        if(win[i]>b){
            b=win[i];
            a=i;
        }
    }
    printf("%c\n%d",arr[a],score[a]);
    
}