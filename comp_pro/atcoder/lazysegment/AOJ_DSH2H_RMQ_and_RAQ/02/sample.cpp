#include <iostream>

int main() {
    int externalVariable = 10;

    // [&] は外部の変数を参照する（参照キャプチャ）
    auto lambda = [&]() {
        std::cout << "External Variable: " << externalVariable << std::endl;
        externalVariable++;  // 外部変数を変更する
    };

    lambda();  // ラムダ式を呼び出す

    // ラムダ式によって外部変数が変更されていることを確認
    std::cout << "Modified External Variable: " << externalVariable << std::endl;

    return 0;
}
