#include<iostream>
using namespace std;
int main(){
    char c;
    cin>>c;
    char a[2000]={0};
    char b[2000]={0};
    cin>>a;
    cin>>b;
    int a_[2000]={0};
    int b_[2000]={0};
    int x=0,x_1=0;
    int nef_a=0;
    int nef_b=0;
    while(a[x_1]!='\0'){
        if(x==0&&a[x_1]=='-'){
            nef_a=1;
            x_1++;
            continue;
        }
        a_[x]=(int)(a[x_1]-'0');
        x++;
        x_1++;
    }
   
    int y=0,y_1=0;
    while(b[y_1]!='\0'){
        if(y==0&&b[y_1]=='-'){
            nef_b=1;
            y_1++;
            continue;
        }
        b_[y]=(int)(b[y_1]-'0');
        y++;
        y_1++;
    }
    
    int biga=0;
    if(x>y){
        biga=1;
    }
    if(x==y){
        for(int i=x;i>=0;i--){
            if(a_[i]>b_[i]){
                biga=1;
                break;
            }
        }
    }
    int step=0,stepm=0;
    if(c=='+'){
        if(nef_a==0&&nef_b==1){
            step=1;
            if(biga==0){
                stepm=1;
            }
        }
        if(nef_a==1&&nef_b==0){
            step=1;
            if(biga==1){
                stepm=1;
            }
        }
        if(nef_a==1&&nef_b==1){
            stepm=1;
        }
    }
    else{
        if(nef_a==0&&nef_b==0){
            step=1;
            if(biga==0){
                stepm=1;
            }
        }
        if(nef_a==1&&nef_b==0){
            stepm=1;
        }
        if(nef_a==1&&nef_b==1){
            step=1;
            if(biga==1){
                stepm=1;
            }
        }
    }
    int outcome[2007]={0};
    int r=0;
    if(step==0){
        
        int num=max(x,y);
        int num_=min(x,y);
        int flag=0;
        for(int i=0;i<num_;i++){
            outcome[r]=a_[x-i-1]+b_[y-i-1]+flag;
            if(outcome[r]>9){
                flag=1;
                outcome[r]%=10;
            }
            else{
                flag=0;
            }
            r++;
        }
        
        int k=num-num_;
        
        if(x>y){
            for(int j=k-1;j>=0;j--){
                outcome[r]=a_[j]+flag;
                if(outcome[r]>9){
                    outcome[r]%=10;
                    flag=1;
                }
                else{
                    flag=0;
                }
                r++;
            }
        }
        else if(x<y){
            for(int j=k-1;j>=0;j--){
                outcome[r]=b_[j]+flag;
                if(outcome[r]>9){
                    outcome[r]%=10;
                    flag=1;
                }
                else{
                    flag=0;
                }
                r++;
            }
        }
        else{
            if(x==y&&flag==1){
                outcome[r]=1;
                r++;
            }
        }
    }
    if(step==1){
        if(biga==1){
            int flag=0;
            for(int i=0;i<y;i++){
                outcome[r]=a_[x-i-1]-flag-b_[y-i-1];
                if(outcome[r]<0){
                    outcome[r]+=10;
                    flag=1;
                }
                else{
                    flag=0;
                }
                r++;
            }
            if(x>y){
                for(int j=x-y-1;j>=0;j--){
                    outcome[r]=a_[j]-flag;
                    if(outcome[r]<0){
                        outcome[r]+=10;
                        flag=1;
                    }
                    else{
                        flag=0;
                    }
                    r++;
                }
            }
        }
        if(biga==0){
            int flag=0;
            for(int i=0;i<x;i++){
                outcome[r]=b_[y-i-1]-flag-a_[x-i-1];
                if(outcome[r]<0){
                    outcome[r]+=10;
                    flag=1;
                }
                else{
                    flag=0;
                }
                r++;
            }
            if(y>x){
                for(int j=y-x-1;j>=0;j--){
                    outcome[r]=b_[j]-flag;
                    if(outcome[r]<0){
                        outcome[r]+=10;
                        flag=1;
                    }
                    else{
                        flag=0;
                    }
                    r++;
                }
            }
            
        }
        int mid=r;
        for(int i=mid-1;i>=0;i--){
            if(outcome[i]==0){
                r--;
            }
            else{
                break;
            }
        }
    }
    if(stepm==0){
        for(int i=r-1;i>=0;i--){
            cout<<outcome[i];
        }
        return 0;
    }
    if(stepm==1){
        cout<<'-';
        for(int i=r-1;i>=0;i--){
            cout<<outcome[i];

        }
        return 0;
    }
           
        
    
    
        return 0;
            
}
