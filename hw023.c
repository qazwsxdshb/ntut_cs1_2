#include <stdio.h>
#include <string.h>
typedef enum scoreType_s{G,GPA,S}scoreType_t;
typedef enum G_s{Aplus,A,Aduce,Bplus,B,Bduce,Cplus,C,Cduce,F,X}G_t;
typedef enum GPA_s{b4dot3,b4dot0,b3dot7,b3dot3,b3dot0,b2dot7,b2dot3,b2dot0,b1dot7,b1,b0}GPA_t;
typedef enum S_s{b90to100,b85to89,b80to84, b77to79,b73to76,b70to72,b67to69,b63to66,b60to62,b1to59,b0to0}S_t;


typedef struct {
    const char *string;
    scoreType_t type;
} TypeMap;

TypeMap typeMap[] = {
    {"G", G},{"GPA", GPA},{"S", S},
    {"A+",Aplus},{"A",A},{"A-",Aduce},{"B+",Bplus},{"B",B},{"B-",Bduce},{"C+",Cplus},{"C",C},{"C-",Cduce},{"F",F},{"X",X}
};

typedef union student_s{
    int score;
    char *name;
    G_t G;
    GPA_t GPA;
    S_t S;
}student_t;

int find(char tmp[10],enum scoreType_s typ){
    for (int u=0;u<sizeof(typeMap)/sizeof(typeMap[0]);u++){
        if (strcmp(tmp,typeMap[u].string)==0){
            typ=typeMap[u].type;
            return typ;
        }
    }
}
int main(){
    int type_co,co,type[10];
    char tmp[10];
    student_t stu[10];
    enum scoreType_s typ;
    scanf("%d",&type_co);
    for(int i=0;i<type_co;i++){
        scanf("%s",tmp);
        type[i]=find(tmp,typ);
    }
    

    scanf("%d",&co);
    for(int i=0;i<co;i++){
        scanf("%s",stu[i].name);
        for(int u=0;u<type_co;u++){
            scanf("%s",tmp);
            if(type[i]==0){stu[i].score+=find(tmp,typ);}
            if(type[i]==1){stu[i].score+=find(tmp,typ);}
            if(type[i]==2){stu[i].score+=find(tmp,typ);}
        }
    }
    
    // for(int i=0;i<co;i++){
    //     scanf("%s",stu[i].id);
    //     for(int u=0;u<type_co;u++){
    //         scanf("%s",stu[i].type[u]);
    //     }
    // }

    // sol(stu,co,type_co);
}
// typedef struct hw023{
//     char id[10];
//     char type[10][10];
// } student;

// void sol(student stu[10],int co,int type_co){
    // char *finid[10];
    // int finans[10]={0};
    // char Grade[11][3]={"A+","A","A-","B+","B","B-","C+","C","C-","F","X"};
    // char GPA[11][4]={"4.3","4.0","3.7","3.3","3.0","2.7","2.3","2.0","1.7","1","0"};
    // char per[11][10]={"90-100","85-89","80-84","77-79","73-76","70-72","67-69","63-66","60-62","1-59","0"};
//     int ans[11]={95,87,82,78,75,70,68,65,60,50,0};
//     for(int sel=0;sel<co;sel++){
//         int fin=0;
//         for(int i=0;i<type_co;i++){
//             if('A'<=stu[sel].type[i][0] && stu[sel].type[i][0]<='X'){
//                 for(int u=0;u<11;u++){
//                     if(strcmp(Grade[u],stu[sel].type[i])==0){fin+=ans[u];}
//                 }
//             }

//             else if('.'==stu[sel].type[i][1]){
//                 for(int u=0;u<11;u++){
//                     if(strcmp(GPA[u],stu[sel].type[i])==0){fin+=ans[u];}
//                 }
//             }

//             else if('-'==stu[sel].type[i][2] || '-'==stu[sel].type[i][1]){
//                 for(int u=0;u<11;u++){
//                     if(strcmp(per[u],stu[sel].type[i])==0){fin+=ans[u];}
//                 }
//             }
//             else if('1'==stu[sel].type[i][0]){fin+=50;}
            
//         }
//         finid[sel]=stu[sel].id;
//         finans[sel]=fin/type_co;
//     }
//     for(int i=0;i<co;i++){
//         int min=0;
//         for(int u=1;u<co;u++){
//             if(finans[min]>finans[u]){min=u;}
//         }
//         printf("%s %d\n",finid[min],finans[min]);
//         finans[min]=1000;
//     }
    
// }