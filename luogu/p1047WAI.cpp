#include<iostream>
using namespace std;

int main(){
    int l, m;
    cin >> l >> m;
    int intervals[100][2];
    
    // 读取所有区间
    for(int i = 0; i < m; i++){
        cin >> intervals[i][0] >> intervals[i][1];
    }
    
    // 如果没有区间，直接返回所有树的数量
    if(m == 0){
        cout << l + 1 << endl;
        return 0;
    }
    
    // 区间合并
    int merged[100][2];
    int count = 1;
    merged[0][0] = intervals[0][0];
    merged[0][1] = intervals[0][1];
    
    for(int i = 1; i < m; i++){
        int current_start = intervals[i][0];
        int current_end = intervals[i][1];
        bool merged_flag = false;
        
        // 尝试与已合并的区间合并
        for(int j = 0; j < count; j++){
            // 有重叠，进行合并
            if(current_start <= merged[j][1] && current_end >= merged[j][0]){
                merged[j][0] = min(current_start, merged[j][0]);
                merged[j][1] = max(current_end, merged[j][1]);
                merged_flag = true;
                // 合并后需要重新检查之前的区间是否有新的重叠
                for(int k = 0; k < j; k++){
                    if(merged[j][0] <= merged[k][1] && merged[j][1] >= merged[k][0]){
                        merged[k][0] = min(merged[k][0], merged[j][0]);
                        merged[k][1] = max(merged[k][1], merged[j][1]);
                        // 移除已合并的j区间
                        for(int x = j; x < count - 1; x++){
                            merged[x][0] = merged[x + 1][0];
                            merged[x][1] = merged[x + 1][1];
                        }
                        count--;
                        j--; // 因为删除了一个元素，需要调整索引
                        break;
                    }
                }
                break;
            }
        }
        
        // 如果没有与任何区间合并，则作为新区间添加
        if(!merged_flag){
            merged[count][0] = current_start;
            merged[count][1] = current_end;
            count++;
        }
    }
    
    // 计算被移走的树的总数
    int removed = 0;
    for(int i = 0; i < count; i++){
        removed += merged[i][1] - merged[i][0] + 1;
    }
    
    // 计算剩余的树
    cout << (l + 1 - removed) << endl;
    return 0;
}
//区间融合非常麻烦