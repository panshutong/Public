#include<iostream>
using namespace std;
typedef struct{
    long long sno;
    int score[10]={0};
    int sum=0;
}stu;
int main(){
    int m,n;
    cin>>n>>m;
    int scor_c[m];
    for(int i=0;i<m;i++){
        cin>>scor_c[i];
    }
    stu stud[n];
    for(int i=0;i<n;i++){
        cin>>stud[i].sno;
        for(int j=0;j<m;j++){
            cin>>stud[i].score[j];
            if(stud[i].score[j]>=60){
                stud[i].sum+=scor_c[j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(stud[j].sum>stud[i].sum){
                stu mid=stud[i];
                stud[i]=stud[j];
                stud[j]=mid;
            }
            else if(stud[j].sum==stud[i].sum&&stud[j].sno<stud[i].sno){
                stu mid_=stud[i];
                stud[i]=stud[j];
                stud[j]=mid_;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<stud[i].sno<<" "<<stud[i].sum<<endl;
    }
    return 0;

}