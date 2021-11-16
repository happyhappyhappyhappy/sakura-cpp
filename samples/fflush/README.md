# \[flush関数\]

1. 使わない場合→sample1.cppの様にすると数字が一つづつではなくまとめて一気に出力される
    * CoreDumpをする場合に何も出力無くいきなり出すケースがある
1. 使う場合→sample2.cppの様にすると一つづつになる
    * この関数を使った直後にコンソールに出力される
    * ただし、その分遅くなるのでデバッグで利用する際は最終的にコメントアウトしておくと良い

## 参考リンク

* [時間情報のクラス](https://cpprefjp.github.io/reference/chrono.html)
* [待ち時間を設定するためのクラス](https://cpprefjp.github.io/reference/thread/this_thread/sleep_for.html)
