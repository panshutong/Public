#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num[1000][2]={0};
    int flag=0;
    int m=0;
    if(n==2){
        cout<<"2:1";
        return 0;
    }
    if(n==4){
        cout<<"2:2";
        return 0;
    }
    while(flag==0){
        
        for(int i=2;i<n;i++){
            
            if(n%i==0){
                int x=0;
                for(int j=0;j<m;j++){
                    if(num[j][0]==i){
                        num[j][1]++;
                        x=1;
                        break;
                    }
                    
                }
                if(x==0){
                
                num[m][0]=i;
                num[m][1]=1;
                m++;
                }
                n/=i;
                flag=0;
                break;
            }
            flag++;
            
        }
        
        
    }
    int x=0;
    for(int y=0;y<m;y++){
        if(num[y][0]==n){
            num[y][1]++;
            x=1;
            break;
        }
    }
    if(x==0){
        num[m][0]=n;
        num[m][1]=1;
        m++;
    }
    for(int i=0;i<m;i++){
        cout<<num[i][0]<<':'<<num[i][1]<<'\n';
    }
    return 0;
}