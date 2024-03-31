#include <stdio.h>

int main(){
    int co,arr[100]={0},ans=0;
    scanf("%d",&co);
    for(int i=0;i<co;i++){scanf("%d",&arr[i]);}
    for(int i=0;i<co;i++){
        for(int u=i+1;u<co;u++){
            ans+=arr[i]>arr[u]?1:0;
        }
    }
    printf("%d",ans);
}