#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[31];
    int votes;
} Candidate;

// 比较函数：按得票数从高到低，相同则按字典序从小到大
int compare(const void *a, const void *b) {
    Candidate *ca = (Candidate *)a;
    Candidate *cb = (Candidate *)b;
    
    if (ca->votes != cb->votes) {
        return cb->votes - ca->votes;  // 票数从高到低
    }
    return strcmp(ca->name, cb->name);  // 字典序从小到大
}

int main() {
    int N, K, M;
    scanf("%d %d %d", &N, &K, &M);
    getchar();  // 读取换行符
    
    // 使用动态数组存储候选人信息
    // 由于可能出现超过N个学生的名字，我们分配更多空间
    int maxCandidates = N > 100 ? N : 100;
    Candidate *candidates = (Candidate *)malloc(sizeof(Candidate) * maxCandidates);
    int candidateCount = 0;
    
    // 初始化候选人列表
    // 注意：题目中没有给出N个学生的名单，所以我们需要从选票中动态收集候选人
    
    char line[1024];
    int totalVotes = 0;
    
    // 读取选票
    while (fgets(line, sizeof(line), stdin)) {
        // 去掉末尾的换行符
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        
        // 检查是否为END
        if (strcmp(line, "END") == 0) {
            break;
        }
        
        // 解析选票
        char *names[101];
        int nameCount = 0;
        
        // 使用strtok分割选票中的名字
        char lineCopy[1024];
        strcpy(lineCopy, line);
        
        char *token = strtok(lineCopy, " \t");
        while (token != NULL) {
            names[nameCount] = (char *)malloc(strlen(token) + 1);
            strcpy(names[nameCount], token);
            nameCount++;
            token = strtok(NULL, " \t");
        }
        
        // 检查选票合法性
        int isValid = 1;
        
        // 空选票也作废
        if (nameCount == 0) {
            isValid = 0;
        }
        
        // 检查候选人数是否超过K人
        if (nameCount > K) {
            isValid = 0;
        }
        
        // 检查是否有重复的候选人
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
        
        // 如果选票有效，统计票数
        if (isValid) {
            totalVotes++;
            
            for (int i = 0; i < nameCount; i++) {
                // 查找候选人是否已存在
                int found = 0;
                for (int j = 0; j < candidateCount; j++) {
                    if (strcmp(candidates[j].name, names[i]) == 0) {
                        candidates[j].votes++;
                        found = 1;
                        break;
                    }
                }
                
                // 如果不存在，添加新候选人
                if (!found && candidateCount < maxCandidates) {
                    strcpy(candidates[candidateCount].name, names[i]);
                    candidates[candidateCount].votes = 1;
                    candidateCount++;
                }
            }
        }
        
        // 释放本轮分配的内存
        for (int i = 0; i < nameCount; i++) {
            free(names[i]);
        }
    }
    
    // 排序候选人
    qsort(candidates, candidateCount, sizeof(Candidate), compare);
    
    // 计算半数 - 按年级人数N计算，而不是选票数
    int half = (N + 1) / 2;  // 向上取整
    
    // 检查是否有人超过半数
    int hasOverHalf = 0;
    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].votes >= half) {
            hasOverHalf = 1;
            break;
        }
    }
    
    if (hasOverHalf) {
        // 输出所有得票>=半数的候选人
        for (int i = 0; i < candidateCount; i++) {
            if (candidates[i].votes >= half) {
                printf("%s %d\n", candidates[i].name, candidates[i].votes);
            } else {
                break;  // 由于已排序，后续不会有符合条件的
            }
        }
    } else {
        // 输出前M位候选人，以及与第M位得票相同的候选人
        if (candidateCount <= M) {
            // 候选人少于M位，输出所有
            for (int i = 0; i < candidateCount; i++) {
                printf("%s %d\n", candidates[i].name, candidates[i].votes);
            }
        } else {
            // 输出前M位，以及与第M位得票相同的
            int mthVotes = candidates[M - 1].votes;
            for (int i = 0; i < candidateCount; i++) {
                if (candidates[i].votes >= mthVotes) {
                    printf("%s %d\n", candidates[i].name, candidates[i].votes);
                } else {
                    break;
                }
            }
        }
    }
    
    // 释放内存
    free(candidates);
    
    return 0;
}
