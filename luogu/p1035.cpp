#include<iostream>
using namespace std;
int main(){
    int k;
    cin>>k;
    int n=0;
    double s=0.0;
    do{
        n++;
        s+=1/(double)n;
    }

    while(s<=k);
    cout<<n<<endl;
    return 0;
}

//answer可以直接在for循环里面写(n=1;s<=k;n++)
//但最后输出的时候要n-1，因为for又加过了