#include <stdio.h>
#define max(a,b)(a>b?a:b);

typedef struct work_t{
    int pointer;
    int process;
    int machine[10];
    int hour[10];
}work;

int main(){
    int N,M,co=0,fin=0;
    int ww[10][100]={0},machine_hour[10]={0},work_hour[10]={0},ans[10]={0};
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
                if(min==-1){min=i;}
                int tmp=max(machine_hour[wor[min].machine[wor[min].pointer]],work_hour[min]);
                int tmp1=max(machine_hour[wor[i].machine[wor[i].pointer]],work_hour[i]);
                if(wor[min].hour[wor[min].pointer]+tmp>wor[i].hour[wor[i].pointer]+tmp1){min=i;}
            }
        }
        int tmp=max(machine_hour[wor[min].machine[wor[min].pointer]],work_hour[min]);
        for(int i=0;i<wor[min].hour[wor[min].pointer];i++){
            ww[wor[min].machine[wor[min].pointer]][i+tmp]=min+1;
            machine_hour[wor[min].machine[wor[min].pointer]]=i+tmp+1;
        }
        work_hour[min]=tmp+wor[min].hour[wor[min].pointer];
        ans[min]=work_hour[min];
        wor[min].pointer++;
    }
    for(int i=0;i<M;i++){fin+=ans[i];}
    printf("%d",fin);

}