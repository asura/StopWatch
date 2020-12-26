# 概要

開始時点から終了時点までの実所要時間を計ります。
CPU時間も取得できます。

# 環境

C++-11です。
macOS Catalina (v10.15.7) で動作確認。

# ビルド方法

```
$ mkdir -p build/deb
$ cd build/deb
$ cmake ../.. -DCMAKE_BUILD_TYPE=Debug
$ make
```
