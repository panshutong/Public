#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>
using namespace std;

int replaceStr(char A[ ], const char B[ ], const char C[ ])
{
    int n=0;
    int len_A=strlen(A);
    int len_B=strlen(B);
    int len_C=strlen(C);
    int op=0;
    for(int i=0;i<=len_A-len_B;i++){
        int right=0;
        for(int j=0;j<len_B;j++){
            
            if(A[i+j]==B[j]){
                right++;
            }
            else{
                break;
            }
        }
        if(right==len_B){
            n=i;
            op++;
            break;
            
        }
        
    }
    if(op==0){
        for(int i=0;i<len_C;i++){
            A[len_A+i]=C[i];
        }
        A[len_A+len_C]='\0';
        return 0;
    }
    if(op==1){
        if(len_C==len_B){
            for(int j=0;j<len_C;j++){
                A[n+j]=C[j];
            }
            return 1;       
        }
        else if(len_C<len_B){
            char last[100]={0};
            for(int j=0;j<len_C;j++){
                    A[n+j]=C[j];
            }
            int x=0;
            for(int i=len_B;i<len_A-n;i++){
                last[x]=A[n+i];
                x++;
            }
            for(int i=len_C;i<len_C+x;i++){
                A[i+n]=last[i-len_C];
            }
            A[n+len_C+x]='\0';
            return 1;
        }
        else if(len_C>len_B){
            
            char last[100]={0};
            for(int i=0;i<len_B;i++){
                A[n+i]=C[i];
            }
            int x=0;
            for(int i=len_B;i<len_A-n;i++){
                last[x]=A[i+n];
                x++;
            }
            for(int i=len_B;i<len_C;i++){
                
                A[n+i]=C[i];
            }
            for(int y=0;y<x;y++){
                A[n+len_C+y]=last[y];
            }
            return 1;
            
        }
        
    }
    
//补充代码，完成此函数
return 3;
}



int main()
{
    char str1[110], str2[110], str3[110];
    int nRes;

    cin.getline(str1, 100);
    cin.getline(str2, 100);
    cin.getline(str3, 100);

    nRes = replaceStr(str1, str2, str3);
    printf("%d\n", nRes);
    printf("%s", str1);
    return 0;

}

