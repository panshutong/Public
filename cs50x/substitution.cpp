#include<iostream>
#include<cctype>
using namespace std;
int main(){
    char string[26]={0};
    int i=0;
    int key=0;
    for(i=0;i<26;i++){
    scanf("%c",&string[i]);
    
    if(string[0]=='\n'){
        cout<<"./substitution key"<<endl;
        return 1;
    }
    if(string[i]=='\n'&&i!=0){
        break;
    }
    }
    for(int j=0;j<26;j++){
        if((string[j]>='A'&&string[j]<='Z')||(string[j]>='a'&&string[j]<='z')){
            if(string[25]=='\0'){
                cout<<"Key must contain 26 letters."<<endl;
                return 3;
            }
            
            cout<<"plaintext: ";
            char input[100]={0};
            char num[100]={0};
            cin>>input;
            cout<<"cirpheretext: ";
            for(int g=0;g<100;g++){
                
                if(input[g]>='A'&&input[g]<='Z'){
                    int m=(int)(input[g]-'A');
                    num[g]=toupper(string[m]);

                }
                else if(input[g]>='a'&&input[g]<='z'){
                    int m=(int)(input[g]-'a');
                    num[g]=tolower(string[m]);
                    
                }
                else{
                    num[g]=input[g];
                }
                cout<<num[g];
            }
            

            return 0;
            


        }
        else{
            cout<<"./substitution key"<<endl;
            return 2;
        }
    }
    
    
    
    
}