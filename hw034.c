#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s{
    char data;
    struct node_s *right,*left;
}node_t;
node_t *root=NULL;

void search(char font[22],char mid[22],char ans[22]){
    int co=0;
    for(int u=0;u<strlen(font);u++){
        for(int i=0;i<strlen(mid);i++){
            if(font[u]==mid[i]){ans[co++]=mid[i];break;}
        }
    }
}

void curve(char value,char tmp[22],char left[22],char right[22]){
    int co=0,x=0,l=0,r=0;
    while(1){
        if(value==tmp[co]){x++;}
        else if(x==0){left[l++]=tmp[co];}
        else{right[r++]=tmp[co];}
        if(co==22 || tmp[co]==0 || tmp[co]=='\0'){return;}
        co+=1;
    }
}

void font_back_curve(char font[22],char back[22],char right[22],char left[22],char newleft[22],char newright[22]){
    right[0]=back[strlen(back)-2];
    int x=0,co=1,cc=0;
    for(int i=1;i<strlen(font);i++){
        if(font[i]==right[0]){x++;}
        else if(x==0){left[cc++]=font[i];}
        else if(x==1){right[co++]=font[i];}
    }
    int a=0,b=0;
    for(int u=0;u<strlen(back)-1;u++){
        int xx=0;
        for(int i=0;i<strlen(right);i++){
            if(right[i]==back[u]){newright[a++]=right[i];xx=1;break;}
        }
        if(xx==0){newleft[b++]=back[u];}
    }
}

void font_back(char font[22],char back[22],node_t *pointer,int deep){
    if(strlen(back)==0){return;}
    char right[22]={0},left[22]={0},ans[22]={0},new_left[22]={0},new_right[22]={0};
    node_t *node=malloc(sizeof(node_t));
    node->data=font[0];
    node->left=NULL;
    node->right=NULL;
    if(deep==0){root=node;}
    else if(deep==1){pointer->left=node;}
    else if(deep==2){pointer->right=node;}
    font_back_curve(font,back,right,left,new_left,new_right);
    font_back(right,new_right,node,2);
    font_back(left,new_left,node,1);
}

void font_mid(char font[22],char mid[22],node_t *pointer,int deep){
    if(strlen(mid)==0){return;}
    char right[22]={0},left[22]={0},ans[22]={0};
    node_t *node=malloc(sizeof(node_t));
    search(font,mid,ans);
    node->data=ans[0];
    node->left=NULL;
    node->right=NULL;
    if(deep==0){root=node;}
    else if(deep==1){pointer->left=node;}
    else if(deep==2){pointer->right=node;}
    curve(ans[0],mid,left,right);
    font_mid(ans,left,node,1);
    font_mid(ans,right,node,2);
}


void mid_back_curve(char mid[22],char back[22],char right[22],char left[22],char newleft[22],char newright[22]){
    right[0]=back[strlen(back)-2];
    int x=0,co=1,cc=0;
    for(int i=0;i<strlen(mid);i++){
        if(mid[i]==right[0]){x++;}
        else if(x==0 && back[strlen(back)-1]!=mid[i]){left[cc++]=mid[i];}
        else if(x==1){right[co++]=mid[i];}
    }
    int a=0,b=0;
    for(int u=0;u<strlen(back)-1;u++){
        int xx=0;
        for(int i=0;i<strlen(right);i++){
            if(right[i]==back[u]){newright[a++]=right[i];xx=1;break;}
        }
        if(xx==0){newleft[b++]=back[u];}
    }
}

void mid_back(char mid[22],char back[22],node_t *pointer,int deep){
    if(strlen(back)==0 || strlen(mid)==0){return;}
    char right[22]={0},left[22]={0},ans_l[22]={0},ans_r[22]={0},value=back[strlen(back)-1];
    node_t *node=malloc(sizeof(node_t));
    node->data=value;
    node->left=NULL;
    node->right=NULL;
    if(deep==0){root=node;}
    else if(deep==1){pointer->left=node;}
    else if(deep==2){pointer->right=node;}
    curve(value,mid,left,right);
    search(back,left,ans_l);
    mid_back(left,ans_l,node,1);
    search(back,right,ans_r);
    mid_back(right,ans_r,node,2);
}

void print(node_t *arr[100],int co){
    for(int i=0;i<=co;i++){
        if(arr[i]->left!=NULL){arr[++co]=arr[i]->left;}
        if(arr[i]->right!=NULL){arr[++co]=arr[i]->right;}
        printf("%c",arr[i]->data);
    }
}

int main(){
    node_t *tm,*arr[100];
    char tmp_a,tmp_b,data_a[22]={0},data_b[22]={0};
    scanf("%c %s",&tmp_a,data_a);getchar();
    scanf("%c %s",&tmp_b,data_b);getchar();
    if(tmp_a=='P' && tmp_b=='I'){font_mid(data_a,data_b,tm,0);}
    if(tmp_a=='I' && tmp_b=='P'){font_mid(data_b,data_a,tm,0);}
    if(tmp_a=='P' && tmp_b=='O'){font_back(data_a,data_b,tm,0);}
    if(tmp_a=='O' && tmp_b=='P'){font_back(data_b,data_a,tm,0);}
    if(tmp_a=='I' && tmp_b=='O'){mid_back(data_a,data_b,tm,0);}
    if(tmp_a=='O' && tmp_b=='I'){mid_back(data_b,data_a,tm,0);}
    arr[0]=root;
    print(arr,0);

}