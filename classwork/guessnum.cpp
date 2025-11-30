#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    
    int times=0;
    cin>>times;
    char num[100];
    for(int i=0;i<9*times;i++){
        scanf("%c",&num[i]);
    }
    char m_num[100];
    for(int i=0;i<9*times;i++){
        m_num[i]=num[i];
    }
    int k=1000;
    char k_num[4];
    int right=0;
    int r_num=0,r_place=0;
    int p_r_a[100]={0};
    int x=0,y=0;
    int n=0;
    for(int j=0;j<9000;j++){
        k+=j;
        for(int m=0;m<4;m++){
            k_num[m]=char(k%10)+'0';
            k/=10;
        }
        for(n=0;n<times;n++){
            int r=1+n*9;
            for(x=3;x>=0;x--){
                
                    if(int(num[r])==int(k_num[x])){
                        r_place++;
                    }
                    r++;
                }
            for(x=3;x>=0;x--){  
                for(r=1+n*9;r<5+n*9;r++){
                    if(int(m_num[r])==int(k_num[x])){
                    r_num++;
                    m_num[r]='\0';
                        
                    break;
                    }
                }
                
            }
            if((char)(r_num+'0')==num[6+n*9]&&(char)(r_place+'0')==num[8+n*9]){
                right++;
            }
            r_num=0;
            r_place=0;
            
        }
        
        if(right==times){
            p_r_a[y]=1000+j;
            y++;
        }
        k=1000;
        right=0;
        for(int m=0;m<4;m++){
            k_num[m]=0;
            
        }
        for(int i=0;i<9*times;i++){
            m_num[i]=num[i];
        }

    }
    if(y==1){
        cout<<p_r_a[0]<<endl;
    }
    else{
        cout<<"Not sure"<<endl;
    }
    

    return 0;

}
