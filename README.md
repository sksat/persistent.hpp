# persistent.hpp
Implementation of persistent variable for C++

# これはなに？
C++で永続変数を扱うためのライブラリ．
永続変数というのは，「普通の変数のように使えるけれど，値を外部のファイルに保存しておくことで，プログラムが終了しても値が保存されている」というようなもののこと．
PythonのPickleのようなものというと分かりやすいかもしれない．


オブジェクトを永続化することを，「シリアライズする」ともいう．


これの元ネタは[このGist](https://gist.github.com/sk2sat/185880ec3521454fccdc85a1ea7eb2c0)です．
ここに出てくる[KHPC](http://khfdpl.osask.jp/wiki/?KHPC)というのは[persistent-C](http://khfdpl.osask.jp/wiki/?persistent_C)のKさんによる実装です．


このリポジトリはさっきのGistのやつの発展なので，最初のうちは内部でKHPCを使用します．

# 注意点
KHPCとは違い，mksrcのようなツールを用いません．
これによるメリットは，コンパイルに使うツールの数を減らせることです．
というか，C++コンパイラがあれば十分です．

一方でこれによるデメリットは，KHPCにある「persistent命令」がないことです．
最初から永続的な変数は存在せず，普通に変数を宣言してからその変数を永続化する，という作業が必要になります．

# 使い方
今はKHPCに依存しているので，まずはKHPCをダウンロードします．
```
$ make khpc
```
とやると，自動的にKHPCがダウンロードされます(wgetが必要です)．
