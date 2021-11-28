# \[A1604\]\<ERA\>

## [問題のURL](https://codeforces.com/problemset/problem/1604/A)

## [解説のURL](https://codeforces.com/blog/entry/96460)

## [この問題の結果](https://codeforces.com/contest/1604/status/A)

<!---- 「問題の結果の見方」
 PROBLEMS→問題番号一覧→回答者数→accepted＋言語をセレクトする 
 ---->

-----

## 問題内容の和訳

### 問題の意味が分からないのでまずは機械翻訳したものを掲載します

* 本文

````txt
Shohagは、整数配列a(1),a(2),...,a(n)なる[a(1),a(2),...,]を有する。
彼は次の操作を任意の回数実行できます (おそらく、0の可能性もあります)。

任意の正の整数kを選択します (異なる操作で異なる場合があります)。
シーケンス内の任意の位置 (シーケンスの開始または終了、または 2 つの要素の間) を選択し、この位置のシーケンスにkを挿入します。
このようにして、シーケンスaが変更され、この変更されたシーケンスに対して次の操作が実行されます。
たとえば、a=[3,3,4]の場、k=2を追加する場合、彼は次の数列の1つを得ることができます 
[2,3,3,4]
[3,2,3,4]
[3,3,2,4]
[3,3,4,2]

Shohagは、このシーケンスが次の条件を満たすことを望んでいます:
各1<=i<=a|
a(i)<=i
尚、|a|とは数列の要素数を示しています。

この目標を達成するために実行する必要がある操作の最小数、
これを見つけるのを助けます。
なお、この問題の制約の下で、限られた数の操作でこの目標を
達成することは常に可能であることが前提です。示すことができます。

````

* 解説

````txt
a(i)>i が何らかの位置に対してある場合、
この位置の前に少なくとも a(i)-i の新しい小さな要素を挿入する必要があります。m=max(0,max(a(i)-i))を使用します。
したがって、少なくともm回の操作が必要です。
しかし、m回の操作で十分であることを見るのは難しいことではありません。
たとえば、シーケンスの先頭に1を挿入できます。
このように、すべての要素はmは入ることによって位置がシフトされ、その結果、有効なiごとにa(i)≤iを満たすことができます。
````

* とどのつまり⇒1を片っ端から入れていく戦法をとるということか

-----

## ヒント

* テストデータの2つ目にコツがあります

## 自分の答え

* [1回目](https://codeforces.com/contest/1594/submission/133715924)