#include <stdio.h>
#define min(a,b)(a>b?b:a);

typedef struct work_t{
    int pointer;
    int process;
    int machine[10];
    int hour[10];
}work;

int main(){
    int N,M,co=0;
    int ww[10][100]={0},www[10]={0},ans=0;
    scanf("%d %d",&N,&M);
    work wor[M];
    for(int i=0;i<M;i++){
        scanf("%d",&wor[i].process);wor[i].pointer=0;
        for(int u=0;u<wor[i].process;u++){
            scanf("%d %d",&wor[i].machine[u],&wor[i].hour[u]);co++;
        }
    }

    for(int u=0;u<co;u++){
        int min=-1;
        for(int i=0;i<M;i++){
            if(wor[i].pointer<wor[i].process){
                int zz=0;
                for(int z=0;z<M;z++){if(i+1==(ww[z][www[z]])){zz=1;break;}}
                if(zz==1){NULL;}
                else if(min==-1){min=i;}
                else if(wor[min].hour[wor[min].pointer]+www[wor[min].machine[wor[min].pointer]]>wor[i].hour[wor[i].pointer]+www[wor[i].machine[wor[i].pointer]]){min=i;}
            }
        }
        printf("%d",www[wor[min].machine[wor[min].pointer]]);
        for(int i=0;i<wor[min].hour[wor[min].pointer];i++){
            ww[wor[min].machine[wor[min].pointer]][i+www[wor[min].machine[wor[min].pointer]]]=min+1;
        }
        www[wor[min].machine[wor[min].pointer]]+=wor[min].hour[wor[min].pointer];
        wor[min].pointer++;
        for(int i=0;i<3;i++){printf("\n");for(int u=0;u<30;u++){printf("%d ",ww[i][u]);}}printf("\n");
        for(int i=0;i<3;i++){printf("%d ",www[i]);}
        printf("\n\n\n");
    }

}