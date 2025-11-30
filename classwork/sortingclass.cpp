#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    int na=0,nb=0,nc=0,nd=0;
    int i,j,m,n;
    cin>>a>>b>>c>>d;
    int num[]={120,40,85,50,100,140,70,100};
    int num_0[]={120,40,85,50,100,140,70,100};
    int right=0;
    for(i=0;i<8;i++){
        if(num_0[i]>=a){
            num_0[i]=0;
            na=i;
            for(j=0;j<8;j++){
                if(num_0[j]>=b){
                    num_0[j]=0;
                    nb=j;
                    for(m=0;m<8;m++){
                        if(num_0[m]>=c){
                            num_0[m]=0;
                            nc=m;
                            for(n=0;n<8;n++){
                                if(num_0[n]>=d){
                                    num_0[n]=0;
                                    nd=n;
                                    cout<<na+1<<" "<<nb+1<<" "<<nc+1<<" "<<nd+1<<endl;
                                    right++;
                                    
                                    num_0[nd]=num[nd];
                                    nd=0;
                                }
                            }
                            num_0[nc]=num[nc];
                            nc=0;
                        }
                        
                    }
                    num_0[nb]=num[nb];
                    nb=0;
                }
                

            }
            num_0[na]=num[na];
            na=0;
        
        }
    
    }
    if(right==0){
        cout<<-1<<endl;
    }
return 0;
}