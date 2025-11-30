#include<iostream>
using namespace std;
typedef struct{
    int n;
    char card[52][3]={0};
}CARD;
int main(){
    int t;
    cin>>t;
    CARD input[5];
    for(int i=0;i<t;i++){
        cin>>input[i].n;
        for(int j=0;j<input[i].n;j++){
            cin>>input[i].card[j];
        }
    }
    char whole[52][3]={"DA","D2","D3","D4","D5","D6","D7","D8","D9","DT","DJ","DQ","DK",
    "CA","C2","C3","C4","C5","C6","C7","C8","C9","CT","CJ","CQ","CK",
    "HA","H2","H3","H4","H5","H6","H7","H8","H9","HT","HJ","HQ","HK",
    "SA","S2","S3","S4","S5","S6","S7","S8","S9","ST","SJ","SQ","SK"};
    int ans[5]={0};
    for(int i=0;i<t;i++){
        int flag[52]={0};
        for(int j=0;j<input[i].n;j++){
            for(int k=0;k<52;k++){
                if(flag[k]==0){
                    int right=0;
                    for(int m=0;m<2;m++){
                    
                        if(input[i].card[j][m]==whole[k][m]){
                        right++;
                        }
                        else{
                            break;
                        }
                    }
                    if(right==2){
                        ans[i]++;
                        flag[k]=1;
                    }
                }
            }
        }
        ans[i]=52-ans[i];
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}