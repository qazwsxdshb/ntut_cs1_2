#include <stdio.h>

int main(){
    int co,height;
    scanf("%d\n%d\n",&co,&height);
    if(co==1 && 2<=height && height<=9){
        for(int i=0;i<height;i++){
            for(int u=0;u<(height-1-i);u++)
                printf("#");
            for(int u=0;u<i;u++)
                printf("*%c",(char)((int)'A'+(i-1)%3));
            printf("*");
            for(int u=0;u<(height-1-i);u++)
                printf("#");
            printf("\n");
        }
    }
    else if(co==2 && 2<=height && height<=9){
        for(int i=0;i<height;i++){
            for(int u=1;u<i+2;u++)
                printf("%d",u);
            for(int u=0;u<(height-i)*2;u++)
                printf("*");
            for(int u=i+1;u>0;u--)
                printf("%d",u);
            printf("\n");
        }
    }
    else{
        printf("error");
    }
}