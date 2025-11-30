#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 定义牌的结构体
typedef struct {
    char suit;       // 花色
    int value;       // 数值（2-14，其中11=J，12=Q，13=K，14=A）
} Card;

// 数值映射表
int get_value(const char *val_str) {
    if (strcmp(val_str, "2") == 0) return 2;
    if (strcmp(val_str, "3") == 0) return 3;
    if (strcmp(val_str, "4") == 0) return 4;
    if (strcmp(val_str, "5") == 0) return 5;
    if (strcmp(val_str, "6") == 0) return 6;
    if (strcmp(val_str, "7") == 0) return 7;
    if (strcmp(val_str, "8") == 0) return 8;
    if (strcmp(val_str, "9") == 0) return 9;
    if (strcmp(val_str, "10") == 0) return 10;
    if (strcmp(val_str, "J") == 0) return 11;
    if (strcmp(val_str, "Q") == 0) return 12;
    if (strcmp(val_str, "K") == 0) return 13;
    if (strcmp(val_str, "A") == 0) return 14;
    return -1; // 无效值
}

// 解析一张牌
void parse_card(const char *str, Card *card) {
    card->suit = str[0];
    if (str[1] == '1' && str[2] == '0') { // 处理10的情况
        card->value = 10;
    } else {
        char val_str[3];
       // if (strlen(str) == 2) {
            val_str[0] = str[1];
            val_str[1] = '\0';
        /** } else { // 长度为3的情况只有10
            val_str[0] = '1';
            val_str[1] = '0';
            val_str[2] = '\0';
        }*/
        card->value = get_value(val_str);
    }
}

// 生成5张牌的组合并判断牌型
int check_combination(Card hole1, Card hole2, Card comm[5], int idx1, int idx2, int idx3) {
    Card combo[5];
    combo[0] = hole1;
    combo[1] = hole2;
    combo[2] = comm[idx1];
    combo[3] = comm[idx2];
    combo[4] = comm[idx3];
    
    // 检查同花
    bool is_flush = true;
    char first_suit = combo[0].suit;
    for (int i = 1; i < 5; i++) {
        if (combo[i].suit != first_suit) {
            is_flush = false;
            break;
        }
    }
    
    // 提取并排序数值
    int values[5];
    for (int i = 0; i < 5; i++) {
        values[i] = combo[i].value;
    }
    // 简单冒泡排序
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (values[j] > values[j + 1]) {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
    
    // 去重
    int unique[5], len = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 0 || values[i] != values[i - 1]) {
            unique[len++] = values[i];
        }
    }
    
    // 检查顺子
    bool is_straight = false;
    if (len == 5) {
        // 正常顺子
        if (unique[4] - unique[0] == 4) {
            is_straight = true;
        }
        // 特殊情况：A-2-3-4-5
        else if (unique[0] == 2 && unique[1] == 3 && unique[2] == 4 && unique[3] == 5 && unique[4] == 14) {
            is_straight = true;
        }
    }
    
    // 判断牌型等级（3:THS, 2:TH, 1:SZ, 0:GP）
    if (is_flush && is_straight) return 3;
    if (is_flush) return 2;
    if (is_straight) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // 吸收换行符
    
    for (int i = 0; i < n; i++) {
        char line[200];
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0'; // 去除换行符
        
        char *token = strtok(line, " ");
        Card hole1, hole2;
        Card community[5];
        
        // 解析前两张底牌
        parse_card(token, &hole1);
        token = strtok(NULL, " ");
        parse_card(token, &hole2);
        
        // 解析后五张公共牌
        for (int j = 0; j < 5; j++) {
            token = strtok(NULL, " ");
            parse_card(token, &community[j]);
        }
        
        // 生成所有可能的3张公共牌组合（C(5,3)=10种）
        int max_rank = 0;
        int combinations[10][3] = {
            {0,1,2}, {0,1,3}, {0,1,4}, {0,2,3}, {0,2,4},
            {0,3,4}, {1,2,3}, {1,2,4}, {1,3,4}, {2,3,4}
        };
        
        for (int j = 0; j < 10; j++) {
            int rank = check_combination(hole1, hole2, community, 
                                        combinations[j][0], combinations[j][1], combinations[j][2]);
            if (rank > max_rank) {
                max_rank = rank;
                if (max_rank == 3) break; // 已找到最高等级，提前退出
            }
        }
        
        // 输出结果
        switch (max_rank) {
            case 3: printf("THS\n"); break;
            case 2: printf("TH\n"); break;
            case 1: printf("SZ\n"); break;
            case 0: printf("GP\n"); break;
        }
    }
    
    return 0;
}
