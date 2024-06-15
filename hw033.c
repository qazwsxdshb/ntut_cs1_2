#include <stdio.h>

typedef struct node_s{
    int name;
    int size;
    struct node_s * go[15];
} node_t;
node_t city[100]={0,0};

void in(int value1,int value2){
    city[value1].name=value1;
    city[value2].name=value2;
    city[value1].go[city[value1].size++]=&city[value2];
    city[value2].go[city[value2].size++]=&city[value1];
}

int find(int path[100],int value){
    for(int i=0;i<100;i++){
        if(path[i]==value){return -1;}
    }
    return 1;
}

void print(int path[100],int co){
    while(path[co]!=0){printf("%d ",path[co++]);}
}

void search(int start,int arr,int deep,int path[100],int ans[100],int *ansdeep,int xxx){
    if(xxx==-1 && start==arr){
        if(deep<*ansdeep || *ansdeep<0){
            *ansdeep=deep;
            for(int i=0;i<100;i++){ans[i]=path[i];}
        }
    }
    if(start==xxx){xxx=-1;}
    int pathtmp[15]={0},coo=0;
    for(int u=0;u<city[start].size;u++){
        if(find(path,(city[start].go[u]->name))==1){
            pathtmp[coo++]=city[start].go[u]->name;
        }
    }
    for(int i=0;i<coo;i++){
        path[deep]=pathtmp[i];
        search(pathtmp[i],arr,1+deep,path,ans,ansdeep,xxx);
        path[deep]=0;
    }
}

int main(){
    int co,start,arr,a,b,path[100]={0},ans[100]={0},ansdeep=-1,xxx=-1;
    scanf("%d %d %d",&co,&start,&arr);
    if(getchar()==' '){scanf("%d",&xxx);}
    for(int i=0;i<co;i++){
        scanf("%d %d",&a,&b);
        in(a,b);
    }
    path[0]=start;
    search(start,arr,1,path,ans,&ansdeep,xxx);
    if(ansdeep<0){printf("NO");}
    else{
        printf("%d\n",ansdeep-1);
        print(ans,0);
    }
}