#include<iostream>
using namespace std;
typedef struct{
    int rank;
    long long name;
    double stren;
    long long power;
    int score;
    int de;
}person;
int main(){

    int n=0;
    cin>>n;
    person p[1000];
    for(int i=0;i<n;i++){
        cin>>p[i].name>>p[i].power;
        p[i].stren=1.0;
        p[i].de=0;
        p[i].rank=i+1;
    }
    int x=0,y=1;
    int Xconti=0;
    while(y<n){
        long long powerX=p[x].power*p[x].stren;
        long long powerY=p[y].power*p[y].stren;
        if(powerX>=powerY){
            p[x].score+=5;
            Xconti++;
            if(Xconti>1&&Xconti<6){
                p[x].score+=(Xconti-1);
            }
            else if(Xconti>=6){
                p[x].score+=5;
            }
            p[x].stren*=0.75;
            
            p[x].de=Xconti;
            y++;
        }
        else if(powerX<powerY){
            p[y].stren*=0.75;
            
            if(Xconti<=4){
                p[y].score+=5-Xconti;
            }
            else{
                p[y].score+=1;
            }
            p[x].de=Xconti;

            Xconti=1;
            p[y].de=Xconti;
            x=y;
            y++;
        }
        
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[j].score>p[i].score){
                person mid=p[i];
                p[i]=p[j];
                p[j]=mid;
            }
            else if(p[j].score==p[i].score&&p[j].de>p[i].de){
                person mid=p[i];
                p[i]=p[j];
                p[j]=mid;
            }
            else if(p[j].score==p[i].score&&p[j].de==p[i].de&&p[j].name<p[i].name){
                person mid=p[i];
                p[i]=p[j];
                p[j]=mid;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        p[i].rank=i+1;
        if(i!=0&&p[i].score==p[i-1].score){
            p[i].rank=p[i-1].rank;
        }
    }
    for(int i=0;i<n;i++){
        cout<<p[i].rank<<' '<<p[i].name<<' '<<p[i].score<<'\n';
    }
    return 0;
}