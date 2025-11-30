#include<stdio.h>
#include<string.h>

char parseCmd(char *s, char *str1, char *str2)
{
    char *k=s+2;
    if(*s=='C'){
        while(*k!='\0'){
            *str1=*k;
            k++;
            str1++;
        }
        *str1='\0';
        str1++;
        return 'C';
    }
    else if(*s=='D'){
       while(*k!='\0'){
            *str1=*k;
            k++;
            str1++;
        }
        *str1='\0';
        str1++;
        return 'D'; 
    }
    else if(*s=='I'){
        while(*k!=' '){
            *str1=*k;
            k++;
            str1++;
        }
        *str1='\0';
        str1++;
        k++;
        while(*k!='\0'){
            *str2=*k;
            k++;
            str2++;
        }
        *str2='\0';
        str2++;
        return 'I';
    }
    else if(*s=='R'){
        while(*k!=' '){
            *str1=*k;
            k++;
            str1++;
        }
        *str1='\0';
        str1++;
        k++;
        while(*k!='\0'){
            *str2=*k;
            k++;
            str2++;
        }
        *str2='\0';
        str2++;
        return 'R';
    }   
}

int countStr(char *s,char *pStr1){
    int len_s=strlen(s);
    int len_Str1=strlen(pStr1);
    if(len_Str1==0 || len_Str1>len_s){
        return 0;
    }
    int times=0;
    char *place=s;
    while((place=strstr(place,pStr1))!=NULL){
        times++;
        place+=len_Str1;
    }
    return times;
}

void deleteStr(char *s,char *pStr1){
    char *place=strstr(s,pStr1);
    if(place==NULL){
        return;
    }
    char tmp[500]={0};
    int size1=place-s;
    strncpy(tmp,s,size1);
    place+=strlen(pStr1);
    int size2=strlen(s)-strlen(pStr1)-size1;
    strncat(tmp,place,size2);
    strcpy(s,tmp);
}

void insertStr(char *s, char *pStr1, char *pStr2){
    int len_Str1=strlen(pStr1);
    if(len_Str1==0){
        return;
    }
    char *final_place=NULL;
    char *place=s;
    
    while((place=strstr(place,pStr1))!=NULL){
        final_place=place;
        place+=len_Str1;
    }
    
    if(final_place==NULL){
        return;
    }
    
    char tmp[500]={0};
    int size1=final_place-s;
    strncpy(tmp,s,size1);
    strcat(tmp,pStr2);
    strcat(tmp,final_place);
    strcpy(s,tmp);
}

char *replaceStr(char *s, char *pStr1, char *pStr2){
    int len_Str1=strlen(pStr1);
    if(len_Str1==0){
        return s;
    }
    
    char tmp[500]={0};
    char *place=s;
    char *pre_place=s;
    char *write_pos=tmp;
    
    while((place=strstr(pre_place,pStr1))!=NULL){
        int copy_len=place-pre_place;
        strncpy(write_pos,pre_place,copy_len);
        write_pos+=copy_len;
        strcpy(write_pos,pStr2);
        write_pos+=strlen(pStr2);
        pre_place=place+len_Str1;
    }
    strcpy(write_pos,pre_place);
    strcpy(s,tmp);
    return s;
}

int main()
{
	char s[500], cmdStr[500], str1[500], str2[500], cmd;
	char *pStr1, *pStr2;

    gets(s);
	gets(cmdStr);
    pStr1 = str1;
    pStr2 = str2;

    cmd = parseCmd(cmdStr, pStr1, pStr2);

    switch ( cmd )
    {
    case 'C':
        printf("%d\n", countStr(s, pStr1));
        break;
    case 'D':
        deleteStr(s, pStr1);
        printf("%s\n", s);
        break;
    case 'I':
        insertStr(s, pStr1, pStr2);
        printf("%s\n", s);
        break;
    case 'R':
        printf("%s\n", replaceStr(s, pStr1, pStr2));
        break;
    }
    return 0;
}
