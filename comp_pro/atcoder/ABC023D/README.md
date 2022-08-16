# \[ABC023D\]\<射撃王\>

## [問題のURL](https://atcoder.jp/contests/abc023/tasks/abc023_d)

## [解説のURL](https://drken1215.hatenablog.com/entry/2021/06/12/113100)

 * 直接の解説はslideshareにありました

## [この問題の結果](https://atcoder.jp/contests/abc023/submissions?f.Task=abc023_d&f.LanguageName=C%2B%2B&f.Status=AC&f.User=)

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 
 ---->

-----
ヒント

ここで使っている```1LL<<60```はこんな値になる
動作 | 数値
------|------
32左移動|4294967296
50左移動|1125899906842624
60左移動|1152921504606846976

-----
## 解いた結果1回目

* [エラー](https://atcoder.jp/contests/abc023/submissions/33185062)
* [成功](https://atcoder.jp/contests/abc023/submissions/33203274)
* 原因は解答の出力内で```<< "\n" << flush```が抜けている。どうやら出力終了の合い言葉らしい。

-----
## 解いた履歴

-------
|回数|達成日|
|---|-----|
|1回目|2022-07-13|
|2回目||
|3回目||