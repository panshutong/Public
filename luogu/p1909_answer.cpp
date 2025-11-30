#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, a1, b1, a2, b2, a3, b3;
    cin >> n >> a1 >> b1 >> a2 >> b2 >> a3 >> b3; //cin会自动检测输入，没必要那么复杂
    int a = ceil(1.0 * n / a1) * b1; //ceil向上取整，能够满足需求；乘上1.0改变int数据形式，进行小数运算
    int b = ceil(1.0 * n / a2) * b2;
    int c = ceil(1.0 * n / a3) * b3;//ceil在cmath中
    cout << min({a, b, c});//比较两个或多个值的时候，min在algorithm库中
    return 0;
}
