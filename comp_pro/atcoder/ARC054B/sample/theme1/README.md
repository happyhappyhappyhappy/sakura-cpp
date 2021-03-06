# ここで攻略する式

![これ](./CodeCogsEqn3.gif)

ソース

[3分探索](./sample1.cpp)

[黄金比探索](./sample2.cpp)

結果

3分探索
```
61 term: left : 2.9999999989 right : 3.0000000013
62 term: left : 2.9999999989 right : 3.0000000005
63 term: left : 2.9999999989 right : 2.9999999999
64 term: left : 2.9999999989 right : 2.9999999996
1.0000000000
```
黄金比探索
```
現在作成中
```
---

方針転換

他人のソースを使わず**比率＋内分点**で求める。

まずは黄金比の所を「2」として三分として出力する

内分点:internally dividing point

分母:denominator

**三分探索**
開始時点
```
LOOP : 299 LEFT: 0.0000000000 RIGHT: 66.6666666667
LOOP : 298 LEFT: 0.0000000000 RIGHT: 44.4444444444
LOOP : 297 LEFT: 0.0000000000 RIGHT: 29.6296296296
LOOP : 296 LEFT: 0.0000000000 RIGHT: 19.7530864198
```
終了時点
```
LOOP : 248 LEFT: 2.9999999678 RIGHT: 3.0000000375
LOOP : 247 LEFT: 2.9999999911 RIGHT: 3.0000000375
LOOP : 246 LEFT: 3.0000000065 RIGHT: 3.0000000375
LOOP : 245 LEFT: 3.0000000169 RIGHT: 3.0000000375
LOOP : 244 LEFT: 3.0000000238 RIGHT: 3.0000000375
LOOP : 243 LEFT: 3.0000000283 RIGHT: 3.0000000375
LAST -> 1.0000000000
```

** 黄金比探索 **
開始時点
```
LOOP : 299 LEFT: 0.0000000000 RIGHT: 61.8033988750
LOOP : 298 LEFT: 0.0000000000 RIGHT: 38.1966011250
LOOP : 297 LEFT: 0.0000000000 RIGHT: 23.6067977500
LOOP : 296 LEFT: 0.0000000000 RIGHT: 14.5898033750
LOOP : 295 LEFT: 0.0000000000 RIGHT: 9.0169943749
```
終了時点
```
LOOP : 256 LEFT: 2.9999999546 RIGHT: 3.0000000184
LOOP : 255 LEFT: 2.9999999790 RIGHT: 3.0000000184
LOOP : 254 LEFT: 2.9999999790 RIGHT: 3.0000000033
LOOP : 253 LEFT: 2.9999999790 RIGHT: 2.9999999940
LOOP : 252 LEFT: 2.9999999847 RIGHT: 2.9999999940
LAST -> 1.0000000000
```