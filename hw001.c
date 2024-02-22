#include <stdio.h>

int main(){
    float a,b;
    scanf("%f %f",&a,&b);
    printf("%.1f",(a/(b*b*0.0001)));
    return 0;
}