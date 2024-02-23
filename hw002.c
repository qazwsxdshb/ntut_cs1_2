#include <stdio.h>
#include <math.h>

void sol(int a,int b,int c,float* ans1,float* ans2){
    *ans1=((b*b-4*a*c)>=0)? ((-b)+sqrt(b*b-4*a*c))/(2*a): sqrt(-1*(b*b-4*a*c))/(2*a);
    *ans2=((b*b-4*a*c)>=0)? ((-b)-sqrt(b*b-4*a*c))/(2*a): -sqrt(-1*(b*b-4*a*c))/(2*a);
}

int main(){
    int a,b,c;
    float ans1,ans2;
    scanf("%d %d %d",&a,&b,&c);
    sol(a,b,c,&ans1,&ans2);
    (b*b-4*a*c)>=0? printf("%.1f\n",ans1): printf((ans1>0)? "%.1f+%.1fi\n": "%.1f%.1fi\n",1.0*(-b)/(2*a),ans1);
    (b*b-4*a*c)>=0? printf("%.1f\n",ans2): printf((ans2>0)? "%.1f+%.1fi\n": "%.1f%.1fi\n",1.0*(-b)/(2*a),ans2);
    return 0;
}