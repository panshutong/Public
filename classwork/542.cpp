#include <stdio.h>
#include <stdlib.h>

void mySort(int *array, int left,int right)
{
    for(int i=left;i<right;i++){
        for(int j=i+1;j<=right;j++){
            if(*(array+j)<*(array+i)){
                int tmp=*(array+i);
                *(array+i)=*(array+j);
                *(array+j)=tmp;
            }
        }
    }
}

int main()  
{  
    int array[100], i, n;
    
    scanf("%d",&n);

    for ( i = 0; i < n; i ++ ){
        scanf("%d", &array[i]);
    }

    mySort(array, 0, n - 1);

    for ( i = 0; i < n; i ++ ){
        printf("%d ", array[i]);
    }
    printf("\n");  
    return 0;  
}  