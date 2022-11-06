# 検証内容

upper_bounder色々

* C++そのまま
* めぐる式改

___
==C++そのまま参考文献==

[API仕様](https://qiita.com/ganyariya/items/33f1326154b85db465c3)

```text
15 9
3 4 5 9 24 31 37 39 49 61 71 76 87 90 91
↓
ポインタ表現: 24
```
ポインタ表現は**指定した数の大きい次の要素の値を返す**
位置を知りたいので追加
```c++
cout << "位置表現: " << Iter - X.begin() << "\n" << flush;
```
実行
```text
ポインタ表現: 24
位置表現: 4
```
24のある要素を返す

ではいくつか調べる

**CASE1:間に入っている場合**

```text
15 10
3 4 5 9 24 31 37 39 49 61 71 76 87 90 91
```

9と24の間

```text
ポインタ表現: 24
位置表現: 4
```
上に位置する位置を返す

**CASE2:最後の値を超える**

```text
15 92
3 4 5 9 24 31 37 39 49 61 71 76 87 90 91
↓
ポインタ表現: 0
位置表現: 15
```

中身は無く、位置は配列の長さと同じ

**CASE3:二つ(以上)同じ値と同じだった**

```text
15 39
3 4 5 9 24 31 39 39 49 61 71 76 87 90 91
↓
ポインタ表現: 49
位置表現: 8
```

同じ値(39)を塊とし、すぐ上のものを返す。

**CASE4:最大値を超えるとbegin()と同じになるか**

模範解答的には位置表現が0なら分かるが、最大値を超えても「ポインタ表現」が0なので。

```text
15 96
4 23 39 49 49 51 53 55 57 69 72 83 84 89 95
↓
ポインタ表現: 0
位置表現: 15
位置表現はX.begin()と異なります
```

これは使っても良さそうだ。ちなみに最小未満の場合

```text
15 3
4 23 39 49 49 51 53 55 57 69 72 83 84 89 95
↓
ポインタ表現: 4
位置表現: 0
位置表現はX.begin()と同じです
```

で、最小値の場合

```text
15 4
4 23 39 49 49 51 53 55 57 69 72 83 84 89 95
↓
ポインタ表現: 23
位置表現: 1
位置表現はX.begin()と異なります
```

___

==めぐる式==

[参考ruby版](https://akhtikd.com/posts/2019-12-11/)

**CASE0:デフォルト**

```text
15 9
3 4 5 9 24 31 37 39 49 61 71 76 87 90 91
↓
ポインタ表現: 24
位置表現: 4
位置表現はX.begin()と異なります
```

**CASE1**

```text
15 10
3 4 5 9 24 31 37 39 49 61 71 76 87 90 91
↓
ポインタ表現: 24
位置表現: 4
位置表現はX.begin()と異なります
```

**CASE2**

```text
15 92
3 4 5 9 24 31 37 39 49 61 71 76 87 90 91
↓
位置表現: 15
位置表現はX.begin()と異なります
```

これは先ほどの例を見るとX[15]は配列外になるので、これは見ないようにしていた。

**CASE3**

```text
ポインタ表現: 49
位置表現: 8
位置表現はX.begin()と異なります
```

**CASE4**

一番下未満の値

```text
ポインタ表現: 4
位置表現: 0
位置表現はX.begin()と同じです
```

一番下と同じ

```text
ポインタ表現: 23
位置表現: 1
位置表現はX.begin()と異なります
```
