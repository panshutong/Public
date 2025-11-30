#include<iostream>
#include<math.h>
using namespace std;

int main(){
    char text[1000];
    fgets(text,1000,stdin);
    int i=0;
    int word=1;
    int sentence=0;
    int letter=0;
    while(text[i]!='\n'){
        if(text[i]==' '){
            word++;
        }
        else if(text[i]=='.'||text[i]=='!'||text[i]=='?'){
            sentence++;
        }
        else if((text[i]>='A'&&text[i]<='Z')||(text[i]>='a'&&text[i]<='z')){
            letter++;
        }
        i++;
    }
    float l=letter/(float)word*100.0;//每100个单词中有多少字母
    float s=sentence/(float)word*100.0;//每100个单词中有多少句子
    float index = 0.0588 * l - 0.296 *s  - 15.8;
    index=round(index);
    if(index<1){
        cout<<"Before Grade 1"<<endl;
    }
    else if(index>=1&&index<16){
        cout<<"Grade "<<index<<endl;
    }
    else {
        cout<<"Grade 16+"<<endl;
    }
    return 0;
}