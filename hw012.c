#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void cal_score(int time,int runer,int *score,int tmp[3],int plrun[9]){
    for(int i=0;i<time;i++){
        if(tmp[2]!=-1){(*score)++;plrun[tmp[2]]++;}
        if(tmp[1]!=-1){plrun[tmp[1]]++;}
        if(tmp[0]!=-1){plrun[tmp[0]]++;}
        tmp[2]=tmp[1];
        tmp[1]=tmp[0];
        tmp[0]=-1;
    }
    plrun[runer]+=time;
    if(time!=4){tmp[time-1]=runer;}
    else{(*score)++;}
}
void catch(int plrun[],int plbon[]){
    int x=0,y=0;
    for(int i=0;i<9;i++){
        if(x<plrun[i]){x=plrun[i];y=i;}
    }
    printf("%d %d %d\n",y+1,plbon[y],plrun[y]);
    plrun[y]=-1;
}

void cal(char player[9][100],int time){
    int plrun[9]={0},plbon[10]={0},tmp[3]={-1,-1,-1};
    int out=0,race=0,runer=0,score=0,tmp_out=0;

    while(out<time){
        if(tmp_out==3){tmp[0]=-1;tmp[1]=-1;tmp[2]=-1;tmp_out=0;}

        plbon[runer]++;
        if(player[runer][race]=='O'){out++;tmp_out++;plbon[runer]--;}

        else if(player[runer][race]!='H'){    
            cal_score(player[runer][race]-'0',runer,&score,tmp,plrun);
        }
        else{cal_score(4,runer,&score,tmp,plrun);}
        
        runer++;
        if(runer==9){runer=0;race++;}
    }

    printf("%d\n",score);
    catch(plrun,plbon);
    catch(plrun,plbon);
    catch(plrun,plbon);
}

int main(){
    int time;
    char tmp[2],player[9][100];
    for(int co=0;co<9;co++){
        scanf("%d",&time);
        for(int i=0;i<time;i++){
            scanf("%s",tmp);
            player[co][i]=tmp[0];
        }
    }
    scanf("%d",&time);
    cal(player,time);
}