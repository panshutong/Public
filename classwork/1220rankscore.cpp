#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct{
    int pre=0;
    int num;
    float tscore[10];
    int score[10];
    int total=0;
    int rank=0;
}stu;
int main(){
    //freopen("error (2).in","r",stdin);
    int n,m;
    cin>>n>>m;
    int scorec[10]={0};
    for(int i=0;i<m;i++){
        cin>>scorec[i];
    }
    stu s[1000];
    for(int i=0;i<n;i++){
        s[i].pre=i;
        cin>>s[i].num;
        for(int j=0;j<m;j++){
            cin>>s[i].tscore[j];
            if(s[i].tscore[j]<60){
                s[i].score[j]=0;
            }
            else if(s[i].tscore[j]>=60&&s[i].tscore[j]<=62){
                s[i].score[j]=10;
            }
            else if(s[i].tscore[j]>=63&&s[i].tscore[j]<=65){
                s[i].score[j]=13;
            }
            else if(s[i].tscore[j]>=66&&s[i].tscore[j]<=69){
                s[i].score[j]=17;
            }
            else if(s[i].tscore[j]>=70&&s[i].tscore[j]<=72){
                s[i].score[j]=20;
            }
            else if(s[i].tscore[j]>=73&&s[i].tscore[j]<=75){
                s[i].score[j]=23;
            }
            else if(s[i].tscore[j]>=76&&s[i].tscore[j]<=79){
                s[i].score[j]=27;
            }
            else if(s[i].tscore[j]>=80&&s[i].tscore[j]<=82){
                s[i].score[j]=30;
            }
            else if(s[i].tscore[j]>=83&&s[i].tscore[j]<=85){
                s[i].score[j]=33;
            }
            else if(s[i].tscore[j]>=86&&s[i].tscore[j]<=89){
                s[i].score[j]=37;
            }
            else{
                s[i].score[j]=40;
            }
            s[i].score[j]=s[i].score[j]*scorec[j];
            s[i].total+=s[i].score[j];
            
        }
        
        
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(s[j].total>s[i].total){
                stu mid=s[i];
                s[i]=s[j];
                s[j]=mid;
            }
        }
    }
    for(int i=0;i<n;i++){
        int y=0;
       while(s[y].total>s[i].total){
        s[i].rank++;
        y++;
       }
       s[i].rank++;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(s[j].pre<s[i].pre){
                stu mid=s[i];
                s[i]=s[j];
                s[j]=mid;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<s[i].num<<' ';
        printf("%.1f ",(float)s[i].total/10.0);
        cout<<s[i].rank<<'\n';
    }
    return 0;
}