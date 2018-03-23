# 概要

開始時点から終了時点までの実所要時間を計ります。
CPU時間も取得できます。

# 環境

C++-03です。
古めのLinux環境であれば動くのでは。
自分の環境は以下です。

* CentOS 6.9
* g++ v4.4.7
* cmake 3.10.2

# ビルド方法

```
$ mkdir -p build/deb
$ cd build/deb
$ cmake ../.. -DCMAKE_BUILD_TYPE=Debug
$ make
```
