# hashing

[![CI](https://github.com/maphorie/hashing/actions/workflows/ci.yml/badge.svg)](https://github.com/maphorie/hashing/actions/workflows/ci.yml)
[![License](https://img.shields.io/github/license/maphorie/hashing)](https://github.com/maphorie/hashing/blob/main/LICENSE)

文字列を数字・大文字・小文字を使ってハッシュ化します．

## 必要なパッケージ

- [CMake](https://cmake.org/)
- [Boost C++ Libraries](https://www.boost.org/)

## ビルド

```console
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## 使い方

コマンド実行時のオプションは次の通りです．

- `--length`を省略したときのデフォルトは`3`です．
- `--digit`，`--lower`，`--upper`を1つ以上組み合わせます．
- `--prefix`，`--suffix`は省略可能です．

| オプション     | 説明               |
|----------------|--------------------|
| `--length` arg | 出力文字列の文字数 |
| `--digit`      | 数字を使う         |
| `--upper`      | 大文字を使う       |
| `--lower`      | 小文字を使う       |
| `--prefix` arg | 出力文字列の接頭辞 |
| `--suffix` arg | 出力文字列の接尾辞 |

ハッシュ化したい文字列を標準入力から入力します．

## 例

```console
$ echo 'example.net' | hashing --length 8 --lower --upper
oMZrUlNz

$ echo 'example.com' | hashing --length 3 --lower --prefix 'foo@' --suffix '.example.org'
foo@ajt.example.org
```

## 注釈

- `std::hash`でハッシュ値を求めたあと剰余演算をしていますので一様になっている保証はありません．
