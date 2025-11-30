#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char input[50][3]={0};
    int input_n[50][2]={0};
    int flag[100][3]={0};
    char c='A';
    int i=0;
    char sample[4]={'A','B','C','D'};
    while(c!='0'){
        cin>>c;
        if(c=='0'){
            break;
        }
        input[i][0]=c;
        int a[2]={0};
        for(int j=1;j<3;j++){
            cin>>input[i][j];
            for(int d=0;d<4;d++){
                if(input[i][j]==sample[d]){
                    a[j-1]=d;
                    break;
                }
            }
            
        }
        input_n[i][0]=a[0];
        input_n[i][1]=a[1]-1;
        
        
        
        i++;
    }
    
    int x=0;
    for(int j=0;j<i;j++){
        int w=input_n[j][0];
        int e=input_n[j][1];
        if(x>n){
            cout<<0;
            return 0;
        }
        if(input[j][0]=='1'){
            int p=0;
            for(int k=0;k<x;k++){
                if(flag[k][w]==0&&flag[k][e]==0){
                    
                    
                    if(e-w==2&&flag[k][w+1]==1){
                        break;

                    }
                    flag[k][w]=1;
                    flag[k][e]=1;
                    for(int q=input_n[j][0]+1;q<input_n[j][1];q++){
                        flag[k][q]=1;
                    }
                    p=1;
                    break;
                }
            }
            if(p==0){
                flag[x][w]=1;
                flag[x][e]=1;
                for(int q=input_n[j][0]+1;q<input_n[j][1];q++){
                    flag[x][q]=1;
                }
                x++;
            }
        }
        else if(input[j][0]=='2'){
            
            for(int k=0;k<x;k++){
                if(flag[k][e]==1&&flag[k][w]==1){
                    if(e-w==2&&flag[k][e+1]==0){
                        continue;

                    }
                    flag[k][input_n[j][0]]=0;
                    flag[k][input_n[j][1]]=0;
                    for(int q=input_n[j][0]+1;q<input_n[j][1];q++){
                        flag[k][q]=0;
                    }
                    
                    break;
                }
            }
            
        }
    }
    int ans=0;
    for(int j=0;j<n;j++){
        if(flag[j][0]==0&&flag[j][1]==0&&flag[j][2]==0){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}