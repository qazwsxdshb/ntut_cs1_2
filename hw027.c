#include <stdio.h>
#define min(a,b)(a>b?b:a);

typedef struct work_t{
    int pointer;
    int size;
    int machine[10];
    int hour[10];
}work;



int main(){
    int N,M,co=0;
    scanf("%d %d",&N,&M);
    work wor[M];
    for(int i=0;i<M;i++){
        scanf("%d",&wor[M].size);wor[M].pointer=0;
        for(int u=0;u<wor[M].size;u++){
            scanf("%d %d",&wor[M].machine[u],&wor[M].hour[u]);co++;
        }
    }

    for(int i=0;i<co;i++){
        if(wor[i].pointer<wor[i].size){
            
        }
        printf();
    }

}