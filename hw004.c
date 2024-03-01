#include <stdio.h>
#include <string.h>

int main(){
    int count=0,co;
    scanf("%d",&co);
    while(count!=co){
        char ans[50];
        scanf("%s",ans);

        if((*ans=='0' && strlen(ans)==1)){printf("integer\n");}
        
        else{
            int point=0,ii=0,var=0,str=0,zero=0;
            for(int u=0;u<strlen(ans);u++){
                if(u==0 && *ans=='-' && strlen(ans)>2){
                    ii++;
                }
                else if(u==0 && *ans=='0'){
                    ii++;
                    zero++;
                }
                else if((int)*(ans+u)>=(int)'0' && (int)*(ans+u)<=(int)'9'){
                    ii++;
                }
                else if(*(ans+u)=='.' && u+1!=strlen(ans)){
                    point++;
                }
                else if(((int)'A'<=(int)*(ans+u) && (int)*(ans+u)<=(int)'Z') || ((int)'a'<=(int)*(ans+u) && (int)*(ans+u)<=(int)'z') || (int)*(ans+u)==(int)'_'){
                    var++;
                }
                else{
                    str++;
                }
            }

            // printf("\n%d %d %d %d\n",point,ii,var,str);
            if(ii==strlen(ans) && point==0 && zero==0){
                printf("integer\n");
            }
            else if((ii+point==strlen(ans)) && point==1){
                printf("float\n");
            }
            else if(ii+var==strlen(ans) && strlen(ans)<=10 && ((*ans<=(int)'Z' && *ans>=(int)'A') || (*ans<=(int)'z' && *ans>=(int)'a') || *ans=='_')){
                printf("variable\n");
            }
            else{
                printf("string\n");
            }
        }

        count++;
    }
}