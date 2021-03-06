# \[JOI2011-4\]\<一年生\>

* [ここの類題](https://qiita.com/drken/items/dc53c683d6de8aeacf5a#d-%E5%95%8F%E9%A1%8C---knapsack-1)

## [問題のURL](https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_d)

## [解説のURL(公式)](https://www.ioi-jp.org/joi/2010/2011-yo-prob_and_sol/2011-yo-t4/review/2011-yo-t4-review.html)

* こちらではDPを使っていない

## [この問題の結果](https://atcoder.jp/contests/joi2011yo/submissions?f.Task=joi2011yo_d&f.LanguageName=C%2B%2B&f.Status=AC&f.User=)

## その他の方のリンク

* [その1](https://kakedashi-engineer.appspot.com/2020/06/08/joi2011yod/)

* [その2](https://neguse-atama.hatenablog.com/entry/2021/10/23/084206)

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 
 ---->

-----

## ヒント

* その1の情報からすると$DP[j番目の列を取る][値がkになる]$として移行していき最後の最終配列を取る。
* 初期値は$DP[0][1番目の数]=1$

<!----
X
---->

## 結果

* [その1失敗](https://atcoder.jp/contests/joi2011yo/submissions/28308636)
    * [その2リンク](https://neguse-atama.hatenablog.com/entry/2021/10/23/084206)と比べるとDPの回し方が違うような気がする
        * 貰う系DPだったので、実験のため渡す系DPにしたつもりだけど。
        * 小データでやってみると違う探索法でありつつ正しく取れるので、渡す系のDPで試みる
    * 「**20**を超える数を扱えない」という説明が「20を含むか含まないか」ピンとこないので最初は20を含む想定で始める。
        * もしこれでテストケースに引っかかったら含めないようにする。
* [その2成功](https://atcoder.jp/contests/joi2011yo/submissions/28450269)
    * 「計算できる数に**20**」を含む、というのを試してみたら元のソースの改良でも上手く働いた。万歳。
