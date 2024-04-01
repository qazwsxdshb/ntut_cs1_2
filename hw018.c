#include <stdio.h>

int main(){
    int a[15]={0},b[15]={0},co,tmp,targe,sel_move=0,sel_com=0,insert_move=0,insert_com=0;
    scanf("%d",&co);
    for(int i=0;i<co;i++){scanf("%d",&a[i]);b[i]=a[i];}

    //sel
    for(int i=1;i<co;i++){
        int min=i-1;
        sel_com+=i;
        for(int u=i;u<co;u++){
            if(b[min]>b[u]){
                min=u;
            }
        }
        if(a[min]!=a[i-1]){
            targe=b[i-1];
            b[i-1]=b[min];
            b[min]=targe;sel_move+=3;
        }
    }
    printf("%d %d\n",sel_com,sel_move);

    //insert
    for(int i=1;i<co;i++){
        targe=a[i];insert_move+=2;
        int j=i;
        for(j;j>0;j--){insert_com+=1;
            if(a[j-1]>targe){
                tmp=a[j-1];insert_move++;
                a[j-1]=targe;
                a[j]=tmp;
            }
            else{break;}
        }insert_com+=i-j+1;
    }
    printf("%d %d",insert_com,insert_move);
}