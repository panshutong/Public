#include<iostream>
#include<cstring>
using namespace std;
typedef struct{
    char name[30]={0};
    int vo=0;
}vote;
int leeen(char arr[]){
    int le=0;
    while(arr[le]!='\n'){
            le++;
        }
        return le;
}

int main(){
    vote v[100];
    int n,k,m;
    cin>>n>>k>>m;
    char c=getchar();
    char input[100][180];
    int i=0;
    while(1==1){
        fgets(input[i],180,stdin);
        if(input[i][0]=='E'&&input[i][1]=='N'&&input[i][2]=='D'){
            break;
        }
        i++;
    }
    int peo=0;
    int y=0,x=0;
    for(int j=0;j<i;j++){
        int le=0;
        le=leeen(input[j]);
        char tmp[30]={0};
        for(int mm=0;mm<le;mm++){
            if(input[j][mm]==' ' ||input[j][mm]=='\n'){
                tmp[x]='\0';
                int flag=0;
                for(int k=0;k<peo;k++){
                    int a=strcmp(tmp,v[k].name);
                    if(a==0){
                        v[k].vo++;
                        x=0;
                        flag=1;
                        break;
                        
                    }
                }
                if(flag==0){
                strcpy(v[peo].name,tmp);
                
                v[peo].vo++;
                peo++;
                
                
                }
                for(int g=0;g<x;g++){
                    tmp[g]='\0';
                }
                x=0;
                
                continue;
            }
            tmp[x]=input[j][m];
            x++;
        }
    }
    return 0;
}