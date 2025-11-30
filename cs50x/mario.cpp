#include<iostream>
using namespace std;
int get_number(void);


int main(){
    int num=get_number();
    int i=0;
    for(i=0;i<num;i++){
        int blank;
        for(blank=0;blank<(num-i);blank++){
            cout<<" ";
        }
        int l;
        for(l=0;l<(i+1);l++){
            cout<<"#";
        }
        cout<<"  ";
        for(l=0;l<(i+1);l++){
            cout<<"#";
        }
        
        cout<<endl;
    

}
return 0;}







int get_number(void){
    int n=0;
    do{
        cout<<"Height:";
        cin>>n;
    }while(n<1||n>8);
    return n;
}