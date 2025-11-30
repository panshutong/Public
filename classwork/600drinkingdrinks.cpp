#include<iostream>
using namespace std;
int number=0;
int bottle,cap;
void drinking(int b,int c){
    if(bottle/b==0&&cap/c==0){
        return;
    }
    else{
        int x=bottle/b;
        bottle-=x*b;
        int y=cap/c;
        cap-=y*c;
        bottle+=x+y;
        cap+=x+y;
        number+=x+y;
        drinking(b,c);
    }
}
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    number=d/a;
    bottle=number;
    cap=number;
    drinking( b, c);
    cout<<number;
    return 0;
}