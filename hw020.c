#include <stdio.h>
#include <string.h>
#define min(i,j) ((i<j) ? i:j)

void sol(char a[200],char b[21],char c[21]){
    char *token;
    token=strtok(a," ");
    
    if(strcmp(token,b)==0){printf("%s",c);}
    else{printf("%s",token);}
    token=strtok(NULL," ");

    while(token != NULL){
        if(strcmp(token,b)==0){printf(" %s",c);}
        else{printf(" %s",token);}
        token=strtok(NULL," ");
    }printf("\n");
}

void sol2(char a[200],char b[21],char c[21]){
    char *token;
    token=strtok(a," ");
    
    if(strcmp(token,b)==0){printf("%s %s",c,b);}
    else{printf("%s",token);}
    token=strtok(NULL," ");

    while(token != NULL){
        if(strcmp(token,b)==0){printf(" %s",c);printf(" %s",b);}
        else{printf(" %s",token);}
        token=strtok(NULL," ");
    }printf("\n");
}

void sort(char ans[20][100],int ans2[20],int co){
    for(int u=0;u<co;u++){
        int tmp=0;
        for(int i=0;i<co;i++){
            if(ans2[i]>ans2[tmp]){tmp=i;}
            else if(ans2[i]!=-1 && ans2[tmp]!=-1 && ans2[i]==ans2[tmp]){
                int x=0;
                for(x;x<min(strlen(ans[i]),strlen(ans[tmp]));x++){
                    if(ans[i][x]<ans[tmp][x]){tmp=i;break;}
                    else if(ans[i][x]>ans[tmp][x]){break;}
                }
                if(x==min(strlen(ans[i]),strlen(ans[tmp])) && ans[i][0]==ans[tmp][0] && strlen(ans[i])<strlen(ans[tmp])){
                    tmp=i;
                }
            }
        }
        printf("\n%s %d",ans[tmp],ans2[tmp]);
        ans2[tmp]=-1;
    }
}


void sol3(char a[200],char b[21],char c[21]){
    char *token;
    token=strtok(a," ");

    if(strcmp(token,b)){printf("%s",token);}
    token=strtok(NULL," ");

    while(token != NULL){
        if(strcmp(token,b)){printf(" %s",token);}
        token=strtok(NULL," ");
    }
}

void sol4(char a[200],char b[21],char c[21]){
    char *token,ans[20][100];
    int ans2[20]={0},co=1;
    token=strtok(a," ");

    for(int u=0;u<strlen(token);u++){ans[0][u]=token[u];}
    ans[0][strlen(token)]='\0';
    ans2[0]+=1;

    token=strtok(NULL," ");

    while(token != NULL){

        int i=0;
        for(i;i<co;i++){if(strcmp(ans[i],token)==0){ans2[i]+=1;break;}}
        if(i==co){
            for(int u=0;u<strlen(token);u++){ans[co][u]=token[u];}
            ans[co][strlen(token)]='\0';
            ans2[co++]+=1;
        }
        token=strtok(NULL," ");
    }
    sort(ans,ans2,co);
}

int main(){
    char a[200]={0},aa[200]={0},aaa[200]={0},aaaa[200]={0},b[21]={0},c[21]={0},tmp;
    int co=0;

    while(1){
        scanf("%c",&tmp);
        if(tmp=='\n'){break;}
        a[co++]=tmp;
    }
    a[co++]='\0';
    scanf("%s",b);
    scanf("%s",c);

    memccpy(aa,a,'\0',strlen(a));
    memccpy(aaa,a,'\0',strlen(a));
    memccpy(aaaa,a,'\0',strlen(a));
    sol(a,b,c);
    sol2(aa,b,c);
    sol3(aaa,b,c);
    sol4(aaaa,b,c);

}