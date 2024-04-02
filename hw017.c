#include <stdio.h>
#include <string.h>

void sol(char a[100],int size,int *i,int x,int y,int ans[10][10]){
    int co=0;
    while(*i<strlen(a)){
        if(a[(*i)++]=='2'){sol(a,size/2,i,x,y,ans);}
        else if(a[(*i)-1]=='1'){
            for(int xx=0;xx<size*size;xx++){
                ans[(xx%size)+y][(xx/size)+x]=1;
            }
        }
        if((++co)==1){x+=size;}
        else if(co==2){x-=size;y+=size;}
        else if(co==3){x+=size;}
        if(4<=co){return;}
    }
}

int main(){
    char a[100]={0};
    int size,i=0,ans[10][10]={0},d=0;
    scanf("%s",a);
    scanf("%d",&size);
    sol(a,size,&i,0,0,ans);
    for(int x=0;x<10;x++){
       for(int y=0;y<10;y++){
            if(ans[x][y]==1){printf("%d,%d\n",x,y);d=1;}
        }
    }
    if(d==0){printf("all white");}
}