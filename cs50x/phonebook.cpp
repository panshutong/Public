#include<iostream>
#include<string>
using namespace std;
typedef struct{
    string name;
    string number;
}person;
int main(){
    person people[3];
    people[0].name="Me";
    people[0].number="+86-180-4602-7700";

    people[1].name="You";
    people[1].number="+86-136-0085-1986";

    people[2].name="Empty";
    people[2].number="+86-139-5910-0308";
    string n;
    cin>>n;
    for(int i=0;i<3;i++){
        if(people[i].name==n){
            cout<<people[i].number<<endl;
            return 0;
        }
    }

    cout<<"Not founded"<<endl;
    return 1;
}