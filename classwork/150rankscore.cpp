#include<iostream>
using namespace std;
typedef struct{
    int rank;
    int num;
    int score;
}student;

int main(){
    int N;
    cin>>N;
    student stu[N];
    for(int i=0;i<N;i++){
        cin>>stu[i].num>>stu[i].score;
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(stu[j].score>stu[i].score){
                student mid=stu[i];
                stu[i]=stu[j];
                stu[j]=mid;
            }
            else if(stu[j].score==stu[i].score&&stu[j].num<stu[i].num){
                student mid_=stu[i];
                stu[i]=stu[j];
                stu[j]=mid_;
            }
        }
    }
    for(int i=0;i<N;i++){
        stu[i].rank=i+1;
        
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(stu[j].score==stu[i].score){
                stu[j].rank=stu[i].rank;
            }
            else{
                
                break;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<stu[i].rank<<" "<<stu[i].num<<" "<<stu[i].score<<endl;
    }
    return 0;
}