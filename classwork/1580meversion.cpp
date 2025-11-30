#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
typedef struct{
    char name[31];
    int votenum=0;
}candidate;
int compare(const void*a,const void *b){
    candidate *ca=(candidate *)a;
    candidate *cb=(candidate *)b;

    if(ca->votenum!=cb->votenum){
        return cb->votenum - ca->votenum;
    }
    return strcmp(ca->name,cb->name);
}
int main(){
    int N=0,K=0,M=0;
    cin>>N>>K>>M;
    getchar();
    
    candidate *candidates=(candidate *)malloc(sizeof(candidate)*N);
    int candidateCount=0;

    char line[1024];
    

    while(fgets(line,sizeof(line),stdin)){
        int len=strlen(line);
        if(len>0&&line[len-1]=='\n'){
            line[len-1]='\0';
        }
        if(strcmp(line,"END")==0){
            break;
        }

        char *names[101];
        int nameCount=0;

        char lineCopy[1024];
        strcpy(lineCopy,line);

        char *token = strtok(lineCopy, " \t");
        while(token!=NULL){
            names[nameCount]=(char *)malloc(strlen(token)+1);
            strcpy(names[nameCount],token);
            nameCount++;
            token=strtok(NULL, "\t");
        }

        int isValid=1;

        if(nameCount==0){
            isValid=0;
        }

        if(nameCount>K){
            isValid=0;
        }

        if(isValid){
            for(int i=0;i<nameCount&&isValid;i++){
                for(int j=i+1;j<nameCount;j++){
                    if(strcmp(names[i],names[j])==0){
                        isValid=0;
                        break;
                    }
                }
            }
        }

        if(isValid){

            for(int i=0;i<nameCount;i++){
                int found=0;
                for(int j=0;j<candidateCount;j++){
                    if(strcmp(candidates[j].name,names[i])==0){
                        candidates[j].votenum++;
                        found=1;
                        break;
                    }
                }
                if(!found){
                    strcpy(candidates[candidateCount].name,names[i]);
                    candidates[candidateCount].votenum=1;
                    candidateCount++;
                }
            }
        }
        for(int i=0;i<nameCount;i++){
            free(names[i]);
        }


    }

    qsort(candidates,candidateCount,sizeof(candidate),compare);

    int half=(N+1)/2;

    int hasoverhalf=0;
    for(int i=0;i<candidateCount;i++){
        if(candidates[i].votenum>=half){
            hasoverhalf=1;
            break;
        }

    }

    if(hasoverhalf){
        for(int i=0;i<candidateCount;i++){
            if(candidates[i].votenum>=half){
                printf("%s %d\n",candidates[i].name,candidates[i].votenum);
            }
            else{
                break;
            }
        }
    }

    else{
        if(candidateCount<=M){
            for(int i=0;i<candidateCount;i++){
                printf("%s %d\n",candidates[i].name,candidates[i].votenum);
            }
        }

        else{
            int min=candidates[M-1].votenum;
            for(int i=0;i<candidateCount;i++){
                if(candidates[i].votenum>=min){
                    printf("%s %d\n",candidates[i].name,candidates[i].votenum);
                }
                else{
                    break;
                }
            }
        }
    }

    free(candidates);


    return 0;
}