# \[情報オリンピック2009B\]\<ピザ\>

## [問題のURL](https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_b)

## [解説のURL](https://drken1215.hatenablog.com/entry/2020/12/22/011600)

## [この問題の結果](https://atcoder.jp/contests/joi2009ho/submissions)

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 
 ---->

-----
ヒント
* C++には[lower_bound関数](https://cpprefjp.github.io/reference/algorithm/lower_bound.html)が存在し、それを用いればすぐ出来る。
    * 二部探索
    * [ここ](https://qiita.com/drken/items/97e37dd6143e33a64c8c)を見つつサンプル作成。
    * 検証は[ここ](https://github.com/happyhappyhappyhappy/sakura-cpp/tree/master/samples)で公開
    * 最終的には1回目はlower_bound関数を活用。

## [提出結果1回目OK](https://atcoder.jp/contests/joi2009ho/submissions/32469354)

[めぐる式1回目OK](https://atcoder.jp/contests/joi2009ho/submissions/32517868)

> 注意: 上記解答がOKになっているのは客の位置が「0」の時、「一つ前」の要素が「6417」になり、それも通じているため。
> このまま他の言語(Java等)に適用するとアクセス違反となりランタイムエラーになる。2回目以降は問題設定の見直しと共に0の時は本店と同じなのだから0が答えと別に扱う。