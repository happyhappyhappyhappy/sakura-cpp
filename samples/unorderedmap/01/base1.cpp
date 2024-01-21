#include <iostream>
#include <unordered_map>

int main() {
    // unordered_mapの宣言
    std::unordered_map<std::string, int> myMap;

    // 要素の追加
    myMap["Alice"] = 25;
    myMap["Bob"] = 30;
    myMap["Charlie"] = 22;

    // キーを使用して要素にアクセス
    std::cout << "Bob's age: " << myMap["Bob"] << std::endl;

    // キーが存在するか確認
    if (myMap.find("David") != myMap.end()) {
        std::cout << "David's age: " << myMap["David"] << std::endl;
    } else {
        std::cout << "David not found in the map." << std::endl;
    }

    // 要素の削除
    myMap.erase("Charlie");

    // 全ての要素にアクセス
    std::cout << "All elements:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
