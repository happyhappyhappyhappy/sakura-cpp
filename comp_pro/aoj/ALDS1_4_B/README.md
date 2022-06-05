# \[ALDS1_4_B\]\<二分探索\>

## [問題のURL](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_4_B)

## [解説のURL](https://judge.u-aizu.ac.jp/onlinejudge/commentary.jsp?id=ALDS1_4_B&pattern=post&type=general&filter=Algorithm)

## [この問題の結果](https://judge.u-aizu.ac.jp/onlinejudge/solution.jsp?pid=ALDS1_4_B)

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 
 ---->

-----
ヒント
* 基本螺旋本通りだが、検証した物をベースにこの問題にアレンジする
    * [テスト用乱数作成](https://www.delftstack.com/ja/howto/cpp/generate-random-number-in-range-cpp/)
* 1回目NG🧑 時間制限過ぎる
* [解説](https://onlinejudge.u-aizu.ac.jp/resources/commentaries/ALDS1_4_B/ja/post?general=Algorithm)を参考、もしくはmapでやるのが良いのかしら

* 何か違和感があると思ったら、「二分探索『木』」では無く「二分探索」(探索がテーマ)だった

* あと、与えられる数列Sは「小さい方から並んでいる」という前提にある。

* TLEで終わる→原因はVectorのコピーにあり[参考](https://teratail.com/questions/233413)
    * 値を入れるだけならば参照渡しが良いのかしら。それとも関数化をやめるか。
    * 今後は関数は参照渡しに切り替えてみる

