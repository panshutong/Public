#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct node{
    int number;
    node *next;
}node;
int main(){
    node *list=NULL;
    for(int i=0;i<3;i++){
        node *n=(node*)malloc(sizeof(node));
        if(n==NULL){
            return 1;
        }
        cout<<"Number: ";
        cin>>n->number;
        n->next=NULL;
        if(list==NULL){
            list=n;
        }
        else{
            for(node *ptr=list;ptr!=NULL;ptr=ptr->next){
                if(ptr->next==NULL){
                    
                    ptr->next=n;
                    break;
                }
            }
        }
    }
    for(node *ptr=list;ptr!=NULL;ptr=ptr->next){
        cout<<ptr->number<<'\n';
        
        
    }
    node *ptr=list;
    while(ptr!=NULL){
        node *next=ptr->next;
        free(ptr);
        ptr=next;
    }
    return 0;
}