# \[1573A\]\<CountDown\>

## [問題のURL](https://codeforces.com/problemset/problem/1573/A)

## [解説のURL](https://codeforces.com/blog/entry/95086)

* 解説しかありません

## [この問題の結果](https://codeforces.com/contest/1573/status/A)

## [結果サンプル](https://codeforces.com/problemset/submission/1573/129590156)

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 
 ---->

## [自分の提出](https://codeforces.com/contest/1573/submission/132317576)

-----
ヒント
<pre>

sをすべての桁の合計とします。 1回の操作で、sを最大11減らすことができ、s = 0の場合に終了します。これにより、最下位桁が0を示している場合、少なくとも99回の操作が必要になるため、時計の数値を減らすことは常に最適ではないという結論に至ります。

この観察結果を使用すると、次の戦略が最適であることがわかります。

最下位桁が正の場合は、数値を1減らします。
最下位桁が0に等しい場合は、正の桁と交換します
Pを正であり、最下位桁ではない桁数とします。私たちの答えは(s + p)になります。これは、O（n）

</pre>

-----

### 考察

* 数字だが文字列にしてしまったほうがいろいろ良さそう

* 問題文に`swap two digits (you can choose which digits to swap, and they don't have to be adjacent).`とある。
  * すなわち、どこの桁でも交換できるのだ！→これを見落としていた
  