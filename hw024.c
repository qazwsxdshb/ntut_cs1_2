#include <stdio.h>

typedef struct student_s{
char name[50];
int score;
}student;

void input(student stu[], int co){
    for(int i=0;i<co;i++){
        scanf("%s",stu[i].name);
        scanf("%d",&stu[i].score);
    }
}

void getHigh(student stu[],int co){
    int max=0,maxpointer;
    for(int i=0;i<co;i++){
        if(max<stu[i].score){max=stu[i].score;maxpointer=i;}
    }
    printf("%s\n",stu[maxpointer].name);
}

int getAverage(student stu[], int co){
    int sum=0;
    for(int i=0;i<co;i++){sum+=stu[i].score;}
    return sum/co;
}

int main(){
    int co;
    student stu[10];
    scanf("%d",&co);
    input(stu,co);
    getHigh(stu,co);
    printf("%d",getAverage(stu,co));
}