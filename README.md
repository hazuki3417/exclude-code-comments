# 概要

ソースコードの行数を維持しつつ、ソースコードに存在するコメントを除外するコマンドです。

# 開発環境

規格:c++17

# 対応言語

 - PHP
 - JavaScript

※上記以外の言語については検証していないため、期待どおりの挙動とならない可能性があります。 

# ビルド・インストール・アンインストール

```sh
cd build

cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local 

# ビルド
cmake --build .

# インストール
cmake --install .

# アンインストール
xargs rm -rfv < install_manifest.txt
```

# 使い方

```sh
exclude-code-comments filePath1 filePath2 ...
```

[サンプルスクリプト](examples/sample.sh)の実行結果

```sh
$ cd examples

$ ./sample.sh 
# TODO:
```
