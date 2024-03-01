#include <stdio.h>

int main(){
    char classname[3][100],class[3][3][100];
    for(int i=0;i<3;i++){
        int co;
        scanf("%s\n%d",classname[i],&co);
        for(int u=0;u<3;u++){
            if(u<co){
                scanf("%s",class[i][u]);
            }
            else{
                *class[i][u]='0';
            }
        }
    }

    int co=0;
    for(int i=0;i<3;i++){
        for(int u=0;u<3;u++){
            if(*class[i][u]!='0'){
                for(int x=i+1;x<3;x++){
                    for(int y=0;y<3;y++){
                        if(atoi(class[i][u])==atoi(class[x][y])){
                            printf("%s,%s,%s\n",classname[i],classname[x],class[x][y]);
                            co++;
                        }

                    }
                }
            }

        }
    }
    if(co==0){printf("correct");}


}