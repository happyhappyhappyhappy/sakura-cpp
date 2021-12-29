# \[1612A\]\<Distance\>

## [問題のURL](https://codeforces.com/problemset/problem/1612/A)

## [解説のURL](https://codeforces.com/blog/entry/97164)

## [この問題の結果](https://codeforces.com/contest/1612/status/A)

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 
 ---->

-----
ヒント

* 全検索でもいいらしい

* 念のため解説

```txt
O（1）には解決策がありますが、実際には、0から50までのx座標と0から50までのy座標を持つすべてのポイントをチェックする解決策で十分です。 d（A、C）+ d（B、C）= d（A、B）なので、他の点をチェックする必要はありません。ポイントCがAとBの間の最短経路の1つにあることを意味します。
```

## 1回目結果

* [NG](https://codeforces.com/contest/1612/submission/141011878)

* [OK](https://codeforces.com/contest/1612/submission/141012178)

    * NGの原因は存在しない場合にreturnを返してしまったため⇒continueで次の物に移動。

    * 特にサンプルと別回答でも正しければそれで良いそうだ
