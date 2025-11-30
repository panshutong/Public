#include<iostream>
#include<cstring>
using namespace std;
typedef struct{
    char name[8][3];
    char ans[4];
    int used[8];
}card;
int ifmianzi(const char a[3],const char b[3],const char c[3]){
    if(strcmp(a,b)==0&&strcmp(b,c)==0){
        return 1;
    }
    else if(a[0]==b[0]&&b[0]==c[0]){
        int numa=a[1]-'0';
        int numb=b[1]-'0';
        int numc=c[1]-'0';
        if(numa+1==numb&&numb+1==numc){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    card c[1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<8;j++){
            cin>>c[i].name[j];
            c[i].used[j]=0;
        }
        int duizi=0,flag=0;
        int possibleduizi[28][2]={0};
        for(int k=0;k<8;k++){
            for(int l=k+1;l<8;l++){
                if(strcmp(c[i].name[k],c[i].name[l])==0){
                    possibleduizi[duizi][0]=k;
                    possibleduizi[duizi][1]=l;
                    duizi++;
                }
            }
        }
        if(duizi==0){
            strcpy(c[i].ans,"NO");
            continue;
        }
        else{
            for(int f=0;f<duizi;f++){
                if(flag==1){
                        break;
                    }
                c[i].used[possibleduizi[f][0]]=1;
                c[i].used[possibleduizi[f][1]]=1;
                for(int j=0;j<8;j++){
                    if(c[i].used[j]==1){
                        continue;
                    }
                    if(flag==1){
                        break;
                    }
                    for(int l=j+1;l<8&&c[i].used[l]!=1;l++){
                        if(c[i].used[l]==1){
                        continue;
                    }
                    if(flag==1){
                        break;
                    }
                        for(int m=l+1;m<8&&c[i].used[m]!=1;m++){
                            if(c[i].used[m]==1){
                            continue;
                            }
                            if(flag==1){
                                break;
                            }
                            if(ifmianzi(c[i].name[j],c[i].name[l],c[i].name[m])==1){
                                int temnum[3]={0};
                                
                                int tem=0;
                                for(int t=0;t<8;t++){
                                    if(c[i].used[t]==0&&t!=j&&t!=l&&t!=m){
                                        temnum[tem]=t;
                                        tem++;
                                    }
                                }
                                if(ifmianzi(c[i].name[temnum[0]],c[i].name[temnum[1]],c[i].name[temnum[2]])==1){
                                    strcpy(c[i].ans,"YES");
                                    flag=1;
                                    break;
                                }
                            }
                        }
                    }
                }
                c[i].used[possibleduizi[f][0]]=0;
                c[i].used[possibleduizi[f][1]]=0;
            }
        }
        if(flag==0){
            strcpy(c[i].ans,"NO");
        }
    }
    for(int i=0;i<n;i++){
        cout<<c[i].ans<<'\n';
    }
    return 0;
}