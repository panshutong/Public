#include<iostream>
#include<cstring>
using namespace std;
typedef struct{
    char num[21];
    long long rank=0;
}dna;
int main(){
    int n;
    cin>>n;
    char mode[5];
    cin>>mode;
    dna DNA[1000];
    for(int i=0;i<n;i++){
        cin>>DNA[i].num;
        int l=strlen(DNA[i].num);
        for(int j=0;j<l;j++){
            DNA[i].rank*=10;
            for(int k=0;k<4;k++){
                if(mode[k]==DNA[i].num[j]){
                    DNA[i].rank+=4-k;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(DNA[i].rank<DNA[j].rank){
                dna mid=DNA[i];
                DNA[i]=DNA[j];
                DNA[j]=mid;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<DNA[i].num<<'\n';
    }
    return 0;
}