#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define shapeText(TYPE) char name[10]; \
int (*perimeter)(struct TYPE*); \
int (*area)(struct TYPE*);

typedef struct triangle_s{
    shapeText(triangle_s);
    int s1, s2, s3;
} triangle_t;
int triangle_area(triangle_t *tri){
    double s=(tri->s1+tri->s2+tri->s3)/2;
    return sqrt(s*(s-tri->s1)*(s-tri->s2)*(s-tri->s3));
}
int triangle_perimeter(triangle_t *tri){return tri->s1+tri->s2+tri->s3;}

typedef struct circle_s{
    shapeText(circle_s);
    int radius;
} circle_t;
int circle_area(circle_t *cir){return cir->radius*cir->radius*4;}
int circle_perimeter(circle_t *cir){return 2*cir->radius*4;}


typedef struct rectangle_s{
    shapeText(rectangle_s);
    int width, height;
} rectangle_t;
int rectangle_area(rectangle_t *rec){return rec->width*rec->height;}
int rectangle_perimeter(rectangle_t *rec){return 2*(rec->width+rec->height);}

typedef struct square_s{
    shapeText(square_s);
    int side;
} square_t;
int square_area(square_t *squ){return squ->side*squ->side;}
int square_perimeter(square_t *squ){return squ->side*4;}


int main(){
    int co,anss[100][2];
    char ans[100][100]={0};
    scanf("%d",&co);
    for(int i=0;i<co;i++){
        char xx[100]={0};
        scanf("%s",xx);getchar();
        strcpy(ans[i],xx);
        if(strcmp(xx,"triangle")==0){
            triangle_t tri;
            tri.area=triangle_area;
            tri.perimeter=triangle_perimeter;
            scanf("%d %d %d",&tri.s1,&tri.s2,&tri.s3);
            anss[i][0]=tri.perimeter(&tri);anss[i][1]=tri.area(&tri);
        }
        else if(strcmp(xx,"square")==0){
            square_t squ;
            squ.area=square_area;
            squ.perimeter=square_perimeter;
            scanf("%d",&squ.side);
            anss[i][0]=squ.perimeter(&squ);anss[i][1]=squ.area(&squ);
        }
        else if(strcmp(xx,"rectangle")==0){
            rectangle_t rec;
            rec.area=rectangle_area;
            rec.perimeter=rectangle_perimeter;
            scanf("%d %d",&rec.width,&rec.height);
            anss[i][0]=rec.perimeter(&rec);anss[i][1]=rec.area(&rec);
        }
        else if(strcmp(xx,"circle")==0){
            circle_t cir;
            cir.area=circle_area;
            cir.perimeter=circle_perimeter;
            scanf("%d",&cir.radius);
            anss[i][0]=cir.perimeter(&cir);anss[i][1]=cir.area(&cir);
        }
    }
    int fia=0,fip=0;
    for(int i=0;i<co;i++){
        int z=-1,pos=-1;
        for(int u=0;u<co;u++){
            if(z==-1 || anss[u][0]>z){z=anss[u][0];pos=u;}
            else if(anss[u][0]==z && anss[u][1]>anss[pos][1]){z=anss[u][0];pos=u;}
        }
        printf("%s %d %d\n",ans[pos],anss[pos][0],anss[pos][1]);
        fia+=anss[pos][0];
        fip+=anss[pos][1];
        anss[pos][0]=-1;
    }
    printf("%d %d\n",fia,fip);
}