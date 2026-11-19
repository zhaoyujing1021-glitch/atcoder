# AtCoder 解答とアルゴリズムテンプレート○

本リポジトリは、AtCoder の練習と復習を記録する個人用リポジトリである。
AC 済みの解答コードと、そこから抽出した再利用可能なアルゴリズムテンプレートを
保存している。

- 解答コードは **C / C++** が中心で、提出時の書き方をそのまま残している。
- テンプレートは **C++17** に統一し、問題固有の入出力や冗長な変数を除いている。
- テンプレートは **中国語** と **日本語** の 2 版を用意している。
  コードのロジックは完全に同一で、コメントの言語だけが異なる。

## 概要

| 項目 | 数 | 説明 |
|---|---:|---|
| 解答ファイル | 51 | `.cpp` 32 本、`.c` 19 本 |
| 解答ディレクトリ | 25 | ABC 22 個 + APG4B + ADT + JSC |
| アルゴリズムテンプレート | 18 | 21 本の解答から整理・統合 |
| テンプレート化しなかったコード | 30 | 基礎文法、A 問題の個別ケース判定、問題固有の全探索／シミュレーション |

## ディレクトリ構成

```text
atcoder/
├─ ABC010/ ... ABC483/       # AtCoder Beginner Contest の解答
├─ ADT_EASY_20261030_1/      # ADT 練習会の解答
├─ APG4B/                    # AtCoder Programming Guide for Beginners の練習
├─ JSC2026ADVANCE-FINAL/     # JSC 決勝の解答
├─ templates/                # 中国語版アルゴリズムテンプレート集
│  ├─ README.md              # テンプレート概要、用途索引、計算量一覧
│  ├─ NOT_TEMPLATES.md       # テンプレート化しなかったコードの分類
│  └─ 01_*.cpp ... 18_*.cpp  # 18 個のテンプレート
└─ templates-ja/             # 日本語版アルゴリズムテンプレート集（templates と同一コード）
   ├─ README.md
   ├─ NOT_TEMPLATES.md
   └─ 01_*.cpp ... 18_*.cpp
```

### 各ディレクトリの説明

| ディレクトリ | 内容 |
|---|---|
| `ABCxxx/` | コンテストごとに 1 ディレクトリ。その回の AC 済みコードを保存 |
| `ADT_EASY_20261030_1/` | ADT（AtCoder Daily Training）の練習問題 |
| `APG4B/` | APG4B の入門文法・基礎アルゴリズム練習。全 16 本 |
| `JSC2026ADVANCE-FINAL/` | JSC2026 決勝の解答 |
| `templates/` | 中国語コメントのテンプレート集。解答へそのまま貼り付けられる |
| `templates-ja/` | 日本語コメントのテンプレート集。`templates/` と一対一対応 |

## 解答一覧

### ABC の解答

| ディレクトリ | 問題 | 主な内容 |
|---|---|---|
| `ABC010` | A - ハンドルネーム | 文字列の追加 |
| `ABC015` | A - 高橋くんの研修 | 文字列長の比較 |
| `ABC029` | A - 複数形 | 文字列の追加 |
| `ABC048` | A - AtCoder Contest | 先頭文字の取得 |
| `ABC061` | B - Counting Roads | 無向グラフの次数カウント |
| `ABC062` | B - Picture Frame | グリッドに枠を追加 |
| `ABC079` | B - Lucas Number | 線形漸化式 |
| `ABC085` | B - Kagami Mochi | 重複除去カウント |
| `ABC088` | B - Card Game for Two | ソート + 交互貪欲法 |
| `ABC107` | B - Grid Compression | 空行・空列の削除 |
| `ABC128` | B - Guidebook | 複数キーソート |
| `ABC324` | A - Same | 全要素一致判定 |
| `ABC473` | A - Second Half Sum；B - Old Maid | 後半の総和；奇数回出現値の総和 |
| `ABC475` | A - mnclr | 文字間への挿入 |
| `ABC476` | A - Appender；B - Wild Card；C - Third Largest Number | 接尾辞規則；単一文字ワイルドカード；ストリームでの第 3 位 |
| `ABC477` | A - Traffic Light；B - Standing Outliers | 写像；ソート後の孤立点抽出 |
| `ABC478` | A - Grapes；B - Topping；C - Sort Subarray | 均等分配；三重ループ全探索；最小ソート区間 |
| `ABC479` | A - Odd Index Sum；B - Longest Rainy Streak | 奇数添字の総和；最長連続区間 |
| `ABC480` | A - ADjacent | 2×2 の隣接判定 |
| `ABC481` | A - Digits of A+B；B - Polyline | 桁数判定；折れ線の横断回数 |
| `ABC482` | A - Nigiri | 個数の偶奇 |
| `ABC483` | A - Double-Sided Printing；B - Flip Card Stack | 切り上げ；接頭辞の符号反転 + 反転のシミュレーション |

### APG4B

`APG4B/` には練習問題が 16 本あり、次の内容を扱っている。

- 出力、変数、四則演算
- 条件分岐、ループ、配列
- 関数、再帰、スコープ
- `pair`、`map`、ソート
- 隣接行列、木の部分木サイズなどの基礎データ構造

問題番号はファイル名の `EX` 番号を参照する。
例：`APG4b_ca_EX22. 3.02.cpp`

### ADT / JSC

| ディレクトリ | 問題 | 主な内容 |
|---|---|---|
| `ADT_EASY_20261030_1` | abc385 A - Equally；abc409 B - Citation | 3 数関係の判定；h-index |
| `JSC2026ADVANCE-FINAL` | abc474 A - Not X；abc474 B - Exit Order | 個別ケース判定；グループ区間判定 |

## テンプレート集

### 2 つのテンプレート集の関係

| ディレクトリ | コメント言語 | ガイド |
|---|---|---|
| `templates/` | 中国語 | [`templates/README.md`](./templates/README.md) |
| `templates-ja/` | 日本語 | [`templates-ja/README.md`](./templates-ja/README.md) |

2 つのディレクトリにある 18 個の `.cpp` はコード部分が行単位で一致しており、
コメントとドキュメントの言語だけが異なる。
テンプレートは `main()` を持たず、入力を読まない。
関数／構造体をそのまま解答へ貼り付けて使える。

### テンプレート早見表

| 番号 | テンプレート | 用途 | 時間 | 空間 |
|---|---|---|---|---|
| 01 | `01_linear_recurrence.cpp` | 2 階線形漸化式（Fibonacci / Lucas 型） | O(n) | O(1) |
| 02 | `02_longest_run.cpp` | 最長の連続同一文字区間 | O(n) | O(1) |
| 03 | `03_frequency_stats.cpp` | 重複除去カウント / 最頻値 / 奇数回出現値の総和 | 期待 O(n) | O(n) |
| 04 | `04_top_k_distinct.cpp` | オンラインで第 k 位（重複除去）を維持 | 1 回 O(log k) | O(k) |
| 05 | `05_even_distribution.cpp` | 商と余りによる均等分配 | O(groups) | O(groups) |
| 06 | `06_alternating_greedy.cpp` | 交互取得の最適解 | O(n log n) | O(1) |
| 07 | `07_h_index.cpp` | h-index | O(n log n) | O(1) |
| 08 | `08_multikey_sort.cpp` | 複数キーソート、元の添字を保持 | O(n log n) | O(1) |
| 09 | `09_min_sort_interval.cpp` | ソートが必要な最小の連続区間 | O(n log n) | O(n) |
| 10 | `10_degree_count.cpp` | 無向グラフの次数カウント | O(n + m) | O(n) |
| 11 | `11_subtree_size.cpp` | 木の部分木サイズ（反復 DFS） | O(n) | O(n) |
| 12 | `12_adjacency_matrix.cpp` | 有向関係行列 | O(n² + m) | O(n²) |
| 13 | `13_grid_compress.cpp` | グリッドの空行・空列を削除 | O(HW) | O(H + W) |
| 14 | `14_grid_frame.cpp` | グリッドに枠を追加 | O(HW) | O(HW) |
| 15 | `15_single_wildcard_match.cpp` | 単一文字ワイルドカードの位置ごとの照合 | O(n) | O(1) |
| 16 | `16_isolated_points.cpp` | ソート後の孤立点抽出 | O(n log n) | O(n) |
| 17 | `17_level_crossing.cpp` | 折れ線が水平線を横切る回数 | O(n) | O(1) |
| 18 | `18_pair_sum_count.cpp` | 和が一定値になるペアのカウント | 期待 O(n + m) | O(m) |

> 各テンプレートの詳細（適用場面、境界条件、出典問題）は、対応する `.cpp` の
> 冒頭コメント、または `templates/README.md` を参照。

## コンパイルと実行

### C++ の解答

```powershell
g++ -std=c++17 -O2 "ABC061\abc061_b_B. Counting Roads.cpp" -o a.exe
.\a.exe
```

### C の解答

```powershell
gcc -std=c11 -O2 "ABC324\abc324_a_B. Same.c" -o a.exe
.\a.exe
```

Linux / macOS では出力ファイルを `./a.out` にすればよい。

```bash
g++ -std=c++17 -O2 "ABC061/abc061_b_B. Counting Roads.cpp" -o a.out
./a.out
```

### テンプレート

テンプレートは `main()` を持たないため、直接実行できない。
まず `-c` で構文チェックを行う。

```powershell
g++ -std=c++17 -Wall -Wextra -c templates\01_linear_recurrence.cpp -o "$env:TEMP\template_check.o"
```

## ファイル命名規則

解答ファイルは基本的に次の形式に従う。

```text
<contest>_<problem>_<letter>. <AtCoder の問題名>.<拡張子>
```

例：

- `ABC061/abc061_b_B. Counting Roads.cpp`
- `ABC128/abc128_b_B. Guidebook.cpp`
- `APG4B/APG4b_ca_EX22. 3.02.cpp`

`ABCxxx` はコンテスト番号、`b_B` は B 問題、最後は問題の原題を表す。
APG4B の `EX` 番号は教材内の練習番号である。

## メンテナンス方針

1. 新しい解答は対応するコンテストディレクトリへ置く。
   例：`ABC484/abc484_a_A. ...cpp`
2. 再利用可能な汎用パターンを含む解答を追加した場合は、次を同時に更新する。
   - `templates/` と `templates-ja/` のテンプレートファイル
   - 両ディレクトリの `README.md`
   - 本 README のテンプレート早見表
3. `.c` ファイルは C の書き方を保ち、C++ の機能を混ぜない。
   テンプレートは C++17 に統一する。
4. テンプレートには汎用ロジックだけを残し、問題固有の入出力、変数名、
   個別ケース判定を含めない。

## 関連ドキュメント

- 中国語版テンプレート概要：[`templates/README.md`](./templates/README.md)
- 中国語版・テンプレート化しなかったコード：[`templates/NOT_TEMPLATES.md`](./templates/NOT_TEMPLATES.md)
- 日本語版テンプレート概要：[`templates-ja/README.md`](./templates-ja/README.md)
- 日本語版・テンプレート化しなかったコード：[`templates-ja/NOT_TEMPLATES.md`](./templates-ja/NOT_TEMPLATES.md)
