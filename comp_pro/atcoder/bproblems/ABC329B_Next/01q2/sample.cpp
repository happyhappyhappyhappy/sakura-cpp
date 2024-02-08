#include <iostream>
#include <vector>

using namespace std;

// 配列内の要素を交換するヘルパー関数
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// パーティション関数
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // ピボットを最後の要素に設定
    int i = low - 1; // ピボットより小さい要素のインデックス

    for (int j = low; j < high; j++) {
        // もし現在の要素がピボット以下なら、それをiより後ろに移動する
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }

    // ピボットを適切な位置に配置する
    swap(arr, i + 1, high);
    return i + 1;
}

// クイックソート関数
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // パーティションを実行し、ピボットの位置を取得
        int pi = partition(arr, low, high);

        // 分割した配列をそれぞれ再帰的にソートする
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// クイックソートを呼び出すためのヘルパー関数
void sort(vector<int>& arr) {
    int n = arr.size();
    quickSort(arr, 0, n - 1);
}

// 配列の要素を表示する関数
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original array: ";
    printArray(arr);

    sort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
