#include<iostream>
using namespace std;
typedef struct{
    char col[7]={0};
    char num[14]={0};
    int number[7]={0};
    char ans[3]={0};
}card;
void choosecard(int mans[],int len,int flag[]){
    
    int m=len-5;
    if(m==1){
        for(int i=2;i<len;i++){
            flag[i]=1;
        }
    
        
    }
    else if(m==2){
        for(int i=2;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                flag[i]=1;
                flag[j]=1;
            }
        }
    }

}
int main(){
    int n;
    cin>>n;
    card c[1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<7;j++){
            cin>>c[i].col[j];
            
        }
        for(int m=0;m<14;m+=2){
            cin>>c[i].num[m];
            char std[13]={'2','3','4','5','6','7','8','9','1','J','Q','K'};
            for(int l=0;l<13;l++){
                if(c[i].num[m]==std[l]){
                    c[i].number[m]=l+1;
                    break;
                }
            }
        }
        int mans[7]={0};
        int flag[7]={0};
        mans[0]=c[i].number[0];
        masn[1]=c[i].number[1];
        if(c[i].col[0]==c[i].col[1]){
            
            int right=2;
            
            for(int j=2;j<7;j++){
                if(c[i].col[j]==c[i].col[0]){
                    right++;
                    mans[right-1]=c[i].nunber[j];
                }
            }
            if(right>=5){
                int b=0;
                for(int k=0;k<right-1;k++){
                    for(int j=k+1;j<right;j++){
                        
                    }
                }

            }
        }
    }
    return 0;
}