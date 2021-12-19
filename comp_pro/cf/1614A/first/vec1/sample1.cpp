#include<iostream>
#include<vector>
#include<algorithm>
// https://cpprefjp.github.io/reference/algorithm/sort.html
// そのまま
using namespace std;

int main(void){
    vector<int> v={3,1,4,2,5};
    // 表示 for_eachだけ一文になっていることに注意
    cout << "=== 初期データ ===\n" << flush;
    for_each(v.begin(),v.end(),
    [](int x){
        cout << x << " ";
    });
    cout << "\n" << flush;  
    // 昇順ならべ
    sort(v.begin(),v.end());
    cout << "=== 昇順ソート後 ===\n" << flush;
    for_each(v.begin(),v.end(),
    [](int x){
        cout << x << " ";
    });
    cout << "\n" << flush;
    // 降順ならべ
    sort(v.begin(),v.end(),greater<int>{});
    cout << "=== 降順ソート後 ===\n" << flush;
    for_each(v.begin(),v.end(),
    [](int x){
        cout << x << " ";
    });
    cout << "\n" << flush;
    return 0;
}
