#include <stdio.h>
#include <string.h>
typedef enum scoreType_s{G,GPA,S}scoreType_t;
typedef enum G_s{Aplus,A,Aduce,Bplus,B,Bduce,Cplus,C,Cduce,F,X}G_t;
typedef enum GPA_s{b4dot3,b4dot0,b3dot7,b3dot3,b3dot0,b2dot7,b2dot3,b2dot0,b1dot7,b1,b0}GPA_t;
typedef enum S_s{b90to100,b85to89,b80to84, b77to79,b73to76,b70to72,b67to69,b63to66,b60to62,b1to59,b0to0}S_t;

typedef struct {
    const char *string;
    union {
        scoreType_t score_type;
        G_t g_type;
        GPA_t gpa_type;
        S_t s_type;
    };
} TypeMap;

TypeMap typeMaps[] = {
    {"G", .score_type = G},
    {"GPA", .score_type = GPA},
    {"S", .score_type = S},
    {"A+", .g_type = Aplus},
    {"A", .g_type = A},
    {"A-", .g_type = Aduce},
    {"B+", .g_type = Bplus},
    {"B", .g_type = B},
    {"B-", .g_type = Bduce},
    {"C+", .g_type = Cplus},
    {"C", .g_type = C},
    {"C-", .g_type = Cduce},
    {"F", .g_type = F},
    {"X", .g_type = X},
    {"4.3", .gpa_type = b4dot3},
    {"4.0", .gpa_type = b4dot0},
    {"3.7", .gpa_type = b3dot7},
    {"3.3", .gpa_type = b3dot3},
    {"3.0", .gpa_type = b3dot0},
    {"2.7", .gpa_type = b2dot7},
    {"2.3", .gpa_type = b2dot3},
    {"2.0", .gpa_type = b2dot0},
    {"1.7", .gpa_type = b1dot7},
    {"1", .gpa_type = b1},
    {"0", .gpa_type = b0},
    {"90-100", .s_type = b90to100},
    {"85-89", .s_type = b85to89},
    {"80-84", .s_type = b80to84},
    {"77-79", .s_type = b77to79},
    {"73-76", .s_type = b73to76},
    {"70-72", .s_type = b70to72},
    {"67-69", .s_type = b67to69},
    {"63-66", .s_type = b63to66},
    {"60-62", .s_type = b60to62},
    {"1-59", .s_type = b1to59},
    {"0", .s_type = b0to0}
};

int find(char tmp[10],int sel){
    for (int u=0;u<sizeof(typeMaps)/sizeof(typeMaps[0]);u++){
        if (strcmp(tmp,typeMaps[u].string)==0){
            if(sel==0){return typeMaps[u].score_type;}
            else if(sel==1){return typeMaps[u].g_type;}
            else if(sel==2){return typeMaps[u].gpa_type;}
            else if(sel==3){return typeMaps[u].s_type;}
        }
    }
}


typedef struct student_s{
    char name[10];
    int score;
}student_t;

int main(){
    int ans[11]={95,87,82,78,75,70,68,65,60,50,0};
    int type_co,co,type[10];
    char tmp[10];
    scanf("%d",&type_co);
    for(int i=0;i<type_co;i++){
        scanf("%s",tmp);
        type[i]=find(tmp,0);
    }
    
    scanf("%d",&co);
    student_t stu[10];
    for(int i=0;i<co;i++){
        scanf("%s",stu[i].name);
        for(int u=0;u<type_co;u++){
            scanf("%s",tmp);
            if(u==0){stu[i].score=ans[find(tmp,type[u]+1)];}
            else{stu[i].score+=ans[find(tmp,type[u]+1)];}
        }
    }

    for(int i=0;i<co;i++){
        int min=0;
        for(int u=0;u<co;u++){
            if(stu[min].score>stu[u].score){min=u;}
        }
        printf("%s %d\n",stu[min].name,stu[min].score/type_co);
        stu[min].score=100000;
    }
}