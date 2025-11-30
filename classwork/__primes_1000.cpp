#include <iostream>
#include <cmath>
using namespace std;

// 判断一个数是否为素数
bool isPrime(int n) {
    if (n <= 1) return false;
    // 只需要检查到 sqrt(n) 即可
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    cout << "1000以内的素数有：" << endl;
    int count = 0;
    for (int i = 2; i <= 1000; i++) {
        if (isPrime(i)) {
            cout << i << "\t"; // 使用制表符分隔
            count++;
            // 每输出10个换行，方便查看
            if (count % 10 == 0) {
                cout << endl;
            }
        }
    }
    cout << endl;
    return 0;
}
