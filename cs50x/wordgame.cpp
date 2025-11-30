#include<iostream>
#include<stdio.h>
using namespace std;
void get_input(char a[],char b[]);
int compare_Qusetion(char x[]);
int output_score(char word[]);
int get_length(char h[]);
void to_lower(char f[]);
int main(){
    char a_1[100]={0},b_1[100]={0};
    get_input(a_1,b_1);
    int x=compare_Qusetion(a_1);
    int y=compare_Qusetion(b_1);
    if(x==0&&y==0){
        cout<<"Tie!"<<endl;
        return 0;
    }
    to_lower(a_1);
    to_lower(b_1);
    int a__1=output_score(a_1);
    int b__1=output_score(b_1);
    if(a__1>b__1){
        cout<<"Player 1 wins!"<<endl;
    }
    else if(a__1<b__1){
        cout<<"Player 2 wins!"<<endl;
    }
    else{
        cout<<"DRAW"<<endl;
    }
    return 0;
    
}

    
void get_input(char a[],char b[]){
    cout<<"Player 1:";
    cin>>a;
    cout<<"Player 2:";
    cin>>b;
}
int compare_Qusetion(char x[]){
    char q[10]="Question";
    int j=0;
    
    for(int i=0;i<8;i++){
        if(x[i]!=q[i]){
        j++;}
    }
    if(j==0&&x[8]=='?'){
        return 0;
    }
    else if(j==0&&x[8]=='!'){
        return 0;
    }
    else{
        return 1;
    }
}
int get_length(char h[]){
    int j=0;
    while(h[j]!='\0'){
        j++;
    }
    return j;
}
int output_score(char word[]){
    int j=get_length(word);
    int score=0;
    for(int i=0;i<j;i++){
        if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='l'||word[i]=='n'||word[i]=='o'||word[i]=='r'||word[i]=='s'||word[i]=='t'||word[i]=='u'){
            score+=1;
        }
        else if(word[i]=='d'||word[i]=='g'){
            score+=2;
        }
        else if(word[i]=='b'||word[i]=='c'||word[i]=='m'||word[i]=='p'){
            score+=3;
        }
        else if(word[i]=='f'||word[i]=='h'||word[i]=='v'||word[i]=='w'||word[i]=='y'){
            score+=4;
        }
        else if(word[i]=='k'){
            score+=5;
        }
        else if(word[i]=='j'||word[i]=='x'){
            score+=8;
        }
        else{
            score+=10;
        }
    }
    return score;
}
void to_lower(char f[]){
    int m=get_length(f);
    for(int i=0;i<m;i++){
        if(f[i]>='A'&&f[i]<='Z'){
            f[i]+=32;
        }
    }
}