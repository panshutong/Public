#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[31];
    int votes;
} Candidate;

int compare(const void *a, const void *b) {
    Candidate *ca = (Candidate *)a;
    Candidate *cb = (Candidate *)b;
    
    if (ca->votes != cb->votes) {
        return cb->votes - ca->votes;
    }
    return strcmp(ca->name, cb->name);
}

int main() {
    int N, K, M;
    scanf("%d %d %d", &N, &K, &M);
    getchar();
    
    Candidate *candidates = (Candidate *)malloc(sizeof(Candidate) * 1000);
    int candidateCount = 0;
    
    char line[1024];
    int validTickets = 0;
    
    while (fgets(line, sizeof(line), stdin)) {
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        
        if (strcmp(line, "END") == 0) {
            break;
        }
        
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
            isValid = 0;
        }
        
        if (isValid) {
            for (int i = 0; i < nameCount && isValid; i++) {
                for (int j = i + 1; j < nameCount; j++) {
                    if (strcmp(names[i], names[j]) == 0) {
                        isValid = 0;
                        break;
                    }
                }
            }
        }
        
        if (isValid) {
            validTickets++;
            
            for (int i = 0; i < nameCount; i++) {
                int found = 0;
                for (int j = 0; j < candidateCount; j++) {
                    if (strcmp(candidates[j].name, names[i]) == 0) {
                        candidates[j].votes++;
                        found = 1;
                        break;
                    }
                }
                
                if (!found) {
                    strcpy(candidates[candidateCount].name, names[i]);
                    candidates[candidateCount].votes = 1;
                    candidateCount++;
                }
            }
        }
        
        for (int i = 0; i < nameCount; i++) {
            free(names[i]);
        }
    }
    
    qsort(candidates, candidateCount, sizeof(Candidate), compare);
    
    printf("Valid tickets: %d\n", validTickets);
    printf("Half: %d\n", (validTickets + 1) / 2);
    printf("\nAll candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    
    free(candidates);
    return 0;
}
