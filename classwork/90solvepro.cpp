#include<iostream>
using namespace std;
typedef struct{
    long long sno;
    int p;
    int n_p[100]={0};
    int scor=0;
    int rank=0;
}stu;
int main(){
    int n;
    cin>>n;
    int pro_num[n]={0};
    for(int i=0;i<n;i++){
        cin>>pro_num[i];
    }
    int m,k;
    cin>>m>>k;
    stu stud[m];
    for(int i=0;i<m;i++){
        cin>>stud[i].sno>>stud[i].p;
        for(int j=0;j<stud[i].p;j++){
            cin>>stud[i].n_p[j];
            for(int s=0;s<n;s++){
                if(stud[i].n_p[j]==pro_num[s]){
                    stud[i].scor++;
                    break;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(stud[j].scor>stud[i].scor){
                stu mid=stud[i];
                stud[i]=stud[j];
                stud[j]=mid;
            }
            else if(stud[j].scor==stud[i].scor&&stud[j].sno<stud[i].sno){
                stu mid_=stud[i];
                stud[i]=stud[j];
                stud[j]=mid_;
            }
        }
    }
    stud[0].rank=1;
    cout<<stud[0].sno;
    for(int i=1;i<m;i++){
        if(stud[i].scor==stud[i-1].scor){
            stud[i].rank=stud[i-1].rank;
        }
        else{
            stud[i].rank=stud[i-1].rank+1;
        }
        if(stud[i].rank<=k){
            cout<<" "<<stud[i].sno;
        }
    }
    return 0;
}