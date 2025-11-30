#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct {
    char name[31];
    int votes;
} Candidate;

// ✓ 正确的比较函数
bool compare(const Candidate &a, const Candidate &b) {
    if (a.votes != b.votes) {
        return a.votes > b.votes;  // 票数从高到低
    }
    return strcmp(a.name, b.name) < 0;  // 字典序从小到大
}

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    cin.ignore();  // 吃掉回车
    
    Candidate candidates[100];
    int candidateCount = 0;
    
    char line[1024];
    int totalVotes = 0;
    
    // ════════════════════════════════════════════════════════════════════════
    // 读取选票并统计
    // ════════════════════════════════════════════════════════════════════════
    
    while (cin.getline(line, sizeof(line))) {
        // 检查是否为 END
        if (strcmp(line, "END") == 0) {
            break;
        }
        
        // 解析这张选票中的候选人
        char *names[101];
        int nameCount = 0;
        
        char lineCopy[1024];
        strcpy(lineCopy, line);
        
        char *token = strtok(lineCopy, " \t");
        while (token != NULL) {
            names[nameCount] = new char[strlen(token) + 1];
            strcpy(names[nameCount], token);
            nameCount++;
            token = strtok(NULL, " \t");
        }
        
        // ════════════════════════════════════════════════════════════════════
        // ✓ 问题修复1：检查选票合法性
        // ════════════════════════════════════════════════════════════════════
        
        int isValid = 1;
        
        // 检查1：空选票作废
        if (nameCount == 0) {
            isValid = 0;
        }
        
        // 检查2：超过 K 人作废
        if (nameCount > K) {
            isValid = 0;
        }
        
        // 检查3：有重复候选人作废
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
        
        // ════════════════════════════════════════════════════════════════════
        // 如果选票有效，统计票数
        // ════════════════════════════════════════════════════════════════════
        
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
                if (!found && candidateCount < 100) {
                    strcpy(candidates[candidateCount].name, names[i]);
                    candidates[candidateCount].votes = 1;
                    candidateCount++;
                }
            }
        }
        
        // 释放本轮分配的内存
        for (int i = 0; i < nameCount; i++) {
            delete[] names[i];
        }
    }
    
    // ════════════════════════════════════════════════════════════════════════
    // ✓ 问题修复2：排序候选人
    // ════════════════════════════════════════════════════════════════════════
    
    sort(candidates, candidates + candidateCount, compare);
    
    // ════════════════════════════════════════════════════════════════════════
    // ✓ 问题修复3：计算半数和输出结果
    // ════════════════════════════════════════════════════════════════════════
    
    int half = (N + 1) / 2;
    
    // 检查是否有人超过半数
    int hasOverHalf = 0;
    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].votes >= half) {
            hasOverHalf = 1;
            break;
        }
    }
    
    if (hasOverHalf) {
        // 情况1：输出所有得票>=半数的候选人
        for (int i = 0; i < candidateCount; i++) {
            if (candidates[i].votes >= half) {
                cout << candidates[i].name << " " << candidates[i].votes << endl;
            } else {
                break;
            }
        }
    } else {
        // 情况2：输出前M位候选人，以及与第M位得票相同的候选人
        if (candidateCount <= M) {
            // 候选人少于M位，输出所有
            for (int i = 0; i < candidateCount; i++) {
                cout << candidates[i].name << " " << candidates[i].votes << endl;
            }
        } else {
            // 输出前M位，以及与第M位得票相同的
            int mthVotes = candidates[M - 1].votes;
            for (int i = 0; i < candidateCount; i++) {
                if (candidates[i].votes >= mthVotes) {
                    cout << candidates[i].name << " " << candidates[i].votes << endl;
                } else {
                    break;
                }
            }
        }
    }
    
    return 0;
}
