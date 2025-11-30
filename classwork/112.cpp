#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int bisearch( int ary[], int left, int right, int num )
{
    cout<<"search "<<num<<" from "<<left<<" to "<<right<<'\n';
    if(left>right){
        return -1;
    }
    
    
//____qcodep____
    int mid=(left+right)/2;
    if(num==ary[mid]){
        
        return mid;
        
    }
    else if(ary[mid]>num){
        return bisearch(ary,left,mid-1,num);
    }
    else{
        return bisearch(ary,mid+1,right,num);
    }
    
    
}

int main()
{
    int n, array[10000], i, num;
    scanf("%d", &n);
    scanf("%d", &num);
    for (i = 0; i < n; i ++ )
    {
        scanf("%d", &array[i]);
    }

    printf( "%d", bisearch(array, 0, n-1, num));
    cout << endl;
    return 0;
}    
