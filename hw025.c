#include <stdio.h>
#include <math.h>
#include <string.h>
#define abs(x) (x>0? x: -1*x)
#define ShapeText(TYPE) char name[10]; \
    double (*perimeter)(struct TYPE*); \
    double (*area)(struct TYPE*)

typedef struct circle_s {
    ShapeText(circle_s);
    double radius;
}circle_t;

double CirclePerimeter(circle_t *obj){return obj->radius*6.28;}
double CircleArea(circle_t *obj){return obj->radius*obj->radius*3.14;}

void CircleNew(circle_t *obj){
    strcpy(obj->name,"Circle");
    obj->perimeter=CirclePerimeter;
    obj->area=CircleArea;
}

typedef struct triangle_s {
    ShapeText(triangle_s);
    double a;
    double b;
    double c;
} triangle_t;

double trianglePerimeter(triangle_t *obj){return obj->a+obj->b+obj->c;}
double triangleArea(triangle_t *obj){
    double s=abs((obj->a+obj->b+obj->c)/2);
    return sqrt(s*abs(s-obj->a)*abs(s-obj->b)*abs(s-obj->c));
}

void triangleNew(triangle_t *obj){
    strcpy(obj->name,"triangle");
    obj->perimeter=trianglePerimeter;
    obj->area=triangleArea;
}

typedef struct rectangle_s {
    ShapeText(rectangle_s);
    double a;
    double b;
} rectangle_t;
double rectanglePerimeter(rectangle_t *obj){return (obj->a+obj->b)*2;}
double rectangleArea(rectangle_t *obj){return obj->a*obj->b;}

void rectangleNew(rectangle_t *obj){
    strcpy(obj->name,"rectangle");
    obj->perimeter=rectanglePerimeter;
    obj->area=rectangleArea;
}

typedef struct squ_s {
    ShapeText(squ_s);
    double a;
} squ_t;
double squPerimeter(squ_t *obj){return obj->a*4;}
double squArea(squ_t *obj){return obj->a*obj->a;}
void squNew(squ_t *obj){
    strcpy(obj->name,"squ");
    obj->perimeter=squPerimeter;
    obj->area=squArea;
}

int main(){
    char type[2];
    int co;
    float ap=0,ar=0;
    scanf("%d",&co);
    for(int i=0;i<co;i++){
        scanf("%s",type);
        if(type[0]=='C'){
            circle_t ans;
            CircleNew(&ans);
            scanf("%lf",&ans.radius);
            printf("%.2lf %.2lf\n",ans.perimeter(&ans),ans.area(&ans));
            ap+=ans.perimeter(&ans);ar+=ans.area(&ans);
        }
        else if(type[0]=='T'){
            triangle_t ans;
            triangleNew(&ans);
            scanf("%lf",&ans.b);
            scanf("%lf",&ans.a);
            scanf("%lf",&ans.c);
            printf("%.2lf %.2lf\n",ans.perimeter(&ans),ans.area(&ans));
            ap+=ans.perimeter(&ans);ar+=ans.area(&ans);
        }
        else if(type[0]=='R'){
            rectangle_t ans;
            rectangleNew(&ans);
            scanf("%lf %lf",&ans.a,&ans.b);
            printf("%.2lf %.2lf\n",ans.perimeter(&ans),ans.area(&ans));
            ap+=ans.perimeter(&ans);ar+=ans.area(&ans);
        }
        else if(type[0]=='S'){
            squ_t ans;
            squNew(&ans);
            scanf("%lf",&ans.a);
            printf("%.2lf %.2lf\n",ans.perimeter(&ans),ans.area(&ans));
            ap+=ans.perimeter(&ans);ar+=ans.area(&ans);
        }
    }
    printf("%.2lf %.2lf",ap,ar);
}