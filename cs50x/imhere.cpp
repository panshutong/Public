#include<stdio.h>
int get_posi(void);
void meow(int n);
int main(void){
    int times=get_posi();
    meow(times);

}
int get_posi(void){
    int num;
    printf("please print a positive number:\n");
    do{
        
        scanf("d",&num);
        getchar();
    }
    while(num<1);
    return num;
}
void meow(int n){
    for(int i=0;i<n;i++){
        printf("meow");
    }
}