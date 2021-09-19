# \[ABC099C\]\<STRANGE BANK\>

## [問題のURL](https://atcoder.jp/contests/abc099/tasks/abc099_c)

## [解説のURL](https://blog.hamayanhamayan.com/entry/2018/06/15/003759)

## [この問題の結果](https://atcoder.jp/contests/abc099/submissions?f.Task=abc099_c&f.LanguageName=C%2B%2B&f.Status=AC&f.User=)

## [自分の答え:失敗例](https://atcoder.jp/contests/abc099/submissions/25917492)

## [自分の答え:成功例](https://atcoder.jp/contests/abc099/submissions/25975738)

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 
 ---->

-----
ヒント

* 階乗については、当初9の倍数だと思ってやめてしまったが、累乗も結局は解説を見る限り与えられた数値を超えたらwhile処理が終了している。だからこれも同じで良い。
* Segmantation Faultが発生した。どうもテストの取り得る値が最大値になると起こる。
  * [デバッガの使い方1](https://qiita.com/Aqua_ix/items/2e9d4fd2eb0fc4db22cb)
  * [↑の元ネタ](https://qiita.com/arene-calix/items/a08363db88f21c81d351)
  * 対策はDP箱の個数が足りない→DPをアクセスするところでデフォルトの100010を超えてしまったため。
    * 箱を100010の所を500000としたところでREは発生しなくなった。
    * しかし解説(再帰化)では100010しか無かったような。
    * 少しいじってみる
