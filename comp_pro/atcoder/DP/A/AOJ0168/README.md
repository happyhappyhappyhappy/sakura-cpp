# \[AOJ0168\]\<観音堂\>

## [問題のURL](https://onlinejudge.u-aizu.ac.jp/problems/0168)

## [この問題の結果](https://judge.u-aizu.ac.jp/onlinejudge/solution.jsp?pid=0168)

* 特にC++の拡張に依存している訳でもないので上記リンクは「C++」をセット。

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 
 ---->

-----

### ヒント

* 2段が3段になった類題

* `0`を最終行とする点はちょっと回答を参照する。

```c++
while(true){
    long long input_data;
    cin >> input_data;
    if(input_data == 0)
        break; // これで処理終了
    (以下略)
}

```

という感じだ。
