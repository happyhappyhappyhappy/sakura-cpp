# 配列型とvector型の動作比較

-----

* 単に配列として使う場合→2452

* c++ ver 11 から利用できるarray型の場合→2667

* array型に初期値を与えてから行う場合→3485

* vectorで配列として使う場合→1991

* vectorでpush backして追加する場合→7848

従って、「vectorを配列として使う」→「cからあった配列を使う」→ 「arrayを使う場合」で速く処理をする

-----

[参考](https://can.hatenadiary.com/entry/2016/07/08/230801)

-----

## 単純に二次元配列を作って見る

* [これ](https://qiita.com/ysuzuki19/items/df872d91c9c89cc31aee)を参考にして作って見た
