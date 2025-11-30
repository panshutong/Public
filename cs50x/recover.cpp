#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    if(argc!=2){
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    FILE *input=fopen(argv[1],"r");
    if(input==NULL){
        printf("Could not open file.\n");
        return 1;
    }
    int f_t[3]={0xff,0xd8,0xff};
    int four[]={0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef};
    BYTE buffer[512];
    int times=0;
    int rank=0;
    char name[8];
    FILE *output=NULL;
    while(fread(&buffer,sizeof(buffer),1,input)){

        int check_1=0;
        for(int i=0;i<3;i++){
            check_1=0;
            if(buffer[i]==f_t[i]){
                check_1++;
            }
        }
        if(check_1==3){
            for(int j=0;j<16;j++){
                if(buffer[4]==four[j]){
                    check_1++;
                    break;
                }
            }
        }
        if(check_1==4&&times==0){
            times++;

            sprintf(name,"%03d.jpg",rank);

            output=fopen(name,"w");
            fwrite(&buffer,sizeof(buffer),1,output);

        }
        else if(check_1==4&&times==1){
            fclose(output);
            rank++;
            sprintf(name,"%03d.jpg",rank);

            output=fopen(name,"w");
            fwrite(&buffer,sizeof(buffer),1,output);

            times=0;
        }
        else if(check_1!=4&&times==1){
            fwrite(&buffer,sizeof(buffer),1,output);
            
        }


    }
    fclose(input);
    fclose(output);

}