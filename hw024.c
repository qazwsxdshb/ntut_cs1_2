#include <stdio.h>

typedef struct student_s{
char name[50];
int score;
}student;

int main(){
    int co,max=0,maxpointer,sum=0;
    student stu[10];
    scanf("%d",&co);
    for(int i=0;i<co;i++){
        scanf("%s",stu[i].name);
        scanf("%d",&stu[i].score);
    }
    for(int i=0;i<co;i++){
        if(max<stu[i].score){max=stu[i].score;maxpointer=i;}
        sum+=stu[i].score;
    }
    printf("%s\n",stu[maxpointer].name);
    printf("%d",sum/co);
}