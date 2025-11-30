#include<iostream>

using namespace std;
int stringlength(char str[]);
void toupper(char str[],int f);
int main(){
    char string[100]={0};
    cin.getline(string,100);
    int k=stringlength(string);
    toupper(string,k);
    
    
    return 0;
    
}

int stringlength(char str[]){
    int i=0;
    while( str[i]!='\0'){
        i++;
    }
    return i;
}
void toupper(char str[],int f){
    int j;
    for (j=0;j<=f;j++){
        if(str[j]<='z'&&str[j]>='a'){
            
            cout<<(char)(str[j]-32);
        }
        else{
            cout<<(char)str[j];
        }
        
    }
    
    
    
}


