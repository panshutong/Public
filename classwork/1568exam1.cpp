#include<iostream>
using namespace std;
int sepnum(int a, int arr[]){
    int tmp=a;
    int k=0;
    while(tmp!=0){
        arr[k]=tmp%10;
        tmp/=10;
        k++;
    }
    return k;
}
void turnnum(int nnum[],int arr[],int o_arr[],int k){
    for(int i=0;i<k;i++){
        for(int j=0;j<5;j++){
            if(nnum[i]==arr[j]){
                nnum[i]=o_arr[j];
                break;
            }
        }
    }
}
int newnum(int nnum[],int k){
    int ans=0;
    for(int i=0;i<k;i++){
        ans*=10;
        ans+=nnum[i];
    }
    return ans;
}
int a[100000]={0};
int main(){
    
    int n;
    cin>>n;
    int arr[]={0,1,6,8,9};
    int o_arr[]={0,1,9,8,6};
    int y=0;
    for(int i=2;i<n;i++){
        int mid=i;
        int flag=0;
        while(mid!=0){
            flag=0;
            int num=mid%10;           
            for(int m=0;m<5;m++){
                if(num==arr[m]){
                    flag=1;
                    break;
                    
                }
            }
            if(flag==0){
                break;
            }
            mid/=10;
        }
        if(flag==1){
        a[y]=i;
        y++;
        }
    }
    int times=0;
    for(int i=0;i<y-1;i++){
        for(int j=i;j<y-1;j++){
            for(int z=j+1;z<y;z++){
                int n[3]={0};
                n[0]=a[i];
                n[1]=a[j];
                n[2]=a[z];
                if(n[0]+n[1]!=n[2]){
                    continue;
                }
                int nnum[3][10]={0};
                int t_n[3]={0};
                int k=sepnum(n[0],nnum[0]);
                turnnum(nnum[0],arr,o_arr,k);
                t_n[0]=newnum(nnum[0],k);

                k=sepnum(n[1],nnum[1]);
                turnnum(nnum[1],arr,o_arr,k);
                t_n[1]=newnum(nnum[1],k);

                k=sepnum(n[2],nnum[2]);
                turnnum(nnum[2],arr,o_arr,k);
                t_n[2]=newnum(nnum[2],k);
                if(t_n[0]+t_n[1]!=t_n[2]){
                    continue;
                }
                times++;
                
            }
        }
    }
    cout<<times;

    return 0;
}