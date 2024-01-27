#include <iostream>

int main() {
    int a = -5;  // aは0未満
    int b = 3;   // bは1以上

    int result = a / b;  // 割り算の結果を整数型で取得

    std::cout << "aをbで割った結果（小数点以下切り捨て）: " << result << std::endl;

    return 0;
}
