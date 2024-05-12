#include <stdio.h>
#define GATEVALUE(Gate) int(*GateValue)()

typedef struct _Gate {
    int input1;
    int input2;
    GATEVALUE(Gate);
}Gate;

int GateORValue(Gate *gate){return gate->input1 || gate->input2;}
int GateANDValue(Gate *gate){return gate->input1 && gate->input2;}
int GateNOTValue(Gate *gate){return gate->input2==1? 0:1;}
int GateBUFFERValue(Gate *gate){return gate->input2;}

int main(){
    int x[3],val=0;
    char tmp;
    Gate ga[3];
    for(int i=0;i<3;i++){scanf("%d",&x[i]);}
    for(int i=0;i<3;i++){
        getchar();
        scanf("%c",&tmp);
        ga[i].input2=x[i];
        ga[i].input1=val;
        if(tmp=='O'){ga[i].GateValue=GateORValue;}
        else if(tmp=='A'){ga[i].GateValue=GateANDValue;}
        else if(tmp=='N'){ga[i].GateValue=GateNOTValue;}
        else if(tmp=='B'){ga[i].GateValue=GateBUFFERValue;}
        val=ga[i].GateValue(&ga[i]);
        printf("%d ",val);
    }
}