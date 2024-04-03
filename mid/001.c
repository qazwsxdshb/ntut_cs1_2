#include <stdio.h>

int main(){
    int sel,b;
    scanf("%d",&sel);
    scanf("%d",&b);
    if(sel==1){
        for(int i=1;i<b+1;i++){
            for(int u=0;u<b-i;u++){printf("#");}
            for(int u=i;u>0;u--){printf("%d",u);}
            for(int u=2;u<i+1;u++){printf("%d",u);}
            for(int u=0;u<b-i;u++){printf("#");}
            printf("\n");
        }
        for(int i=b-1;i>0;i--){
            for(int u=0;u<b-i;u++){printf("#");}
            for(int u=i;u>0;u--){printf("%d",u);}
            for(int u=2;u<i+1;u++){printf("%d",u);}
            for(int u=0;u<b-i;u++){printf("#");}
            printf("\n");
        }
    }
    else if(sel==2){
        for(int i=1;i<b+1;i++){
            for(int u=1;u<i+1;u++){printf("%d",u);}
            for(int u=0;u<b-i;u++){printf("#");}
            printf("\n");
        }
        for(int i=b;i>0;i--){
            for(int u=i;u>0;u--){printf("%d",u);}
            for(int u=0;u<b-i;u++){printf("#");}
            printf("\n");
        }
    }
    else if(sel==3){
        for(int i=1;i<b+1;i++){
            for(int u=0;u<(b-i)*2;u++){printf("#");}
            for(int u=1;u<i+1;u++){printf("%d",u);}
            for(int u=i-1;u>0;u--){printf("%d",u);}
            printf("\n");
        }
    }
    else if(sel==4){
        for(int i=1;i<b+1;i++){
            for(int u=0;u<b-i;u++){printf("#");}
            if(i%2==1){for(int u=1;u<b+1;u++){printf("%d",u);}}
            else{for(int u=b;u>0;u--){printf("%d",u);}}
            for(int u=i-1;u>0;u--){printf("#");}
            printf("\n");
        }
    }
}