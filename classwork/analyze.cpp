#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K, M;
    scanf("%d %d %d", &N, &K, &M);
    getchar();
    
    char line[1024];
    int lineNum = 2;
    int validTickets = 0;
    
    while (fgets(line, sizeof(line), stdin)) {
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        
        if (strcmp(line, "END") == 0) {
            break;
        }
        
        // 解析选票
        char lineCopy[1024];
        strcpy(lineCopy, line);
        
        char *names[101];
        int nameCount = 0;
        
        char *token = strtok(lineCopy, " \t");
        while (token != NULL) {
            names[nameCount] = (char *)malloc(strlen(token) + 1);
            strcpy(names[nameCount], token);
            nameCount++;
            token = strtok(NULL, " \t");
        }
        
        int isValid = 1;
        
        if (nameCount > K) {
            printf("Line %d: INVALID - %d names > K=%d\n", lineNum, nameCount, K);
            isValid = 0;
        }
        
        if (isValid) {
            for (int i = 0; i < nameCount && isValid; i++) {
                for (int j = i + 1; j < nameCount; j++) {
                    if (strcmp(names[i], names[j]) == 0) {
                        printf("Line %d: INVALID - duplicate '%s'\n", lineNum, names[i]);
                        isValid = 0;
                        break;
                    }
                }
            }
        }
        
        if (isValid) {
            printf("Line %d: VALID (%d names)\n", lineNum, nameCount);
            validTickets++;
        }
        
        for (int i = 0; i < nameCount; i++) {
            free(names[i]);
        }
        
        lineNum++;
    }
    
    printf("\nTotal valid tickets: %d\n", validTickets);
    
    return 0;
}
