/**
 * 【テンプレート 08】複数キーによるソート（元の添字を保持 / 安定した出力）
 *
 * 【用途 / 適用場面】
 *   複数のフィールドでソートし、元の番号を出力する。または
 *   「第 2 キー、第 1 キー」の優先順でソートする。
 *   典型的な問題：Guidebook（都市名昇順、点数降順、元の番号を出力）、
 *   ランキング、成績表、複数属性によるレコードのソート。
 *
 * 【時間・空間計算量】
 *   時間 O(n log n)、追加空間 O(1)（std::sort のスタックは O(log n)）。
 *
 * 【注意事項 / 境界条件】
 *   - 比較関数は厳密弱順序を満たす必要がある。a<b と b<a が同時に true に
 *     なってはいけない。等しい場合は false を返す。
 *   - 複数キーのソートでは tie-break（例：id 昇順）を必ず書く。
 *     そうしないと等しい要素の相対順序は未定義になる。
 *   - string の < はバイト列／辞書順で比較する。自然数順（"2" < "10"）が
 *     必要な場合は比較関数を自作する。
 *   - 元の番号を出力するときは、問題が 1-based か 0-based かを確認する。
 *   - ソート後に重複除去する場合は sort してから unique を使う。
 *     set を使うと元の添字が壊れるので避ける。
 *
 * 【出典】
 *   ABC128 B - Guidebook
 *   APG4B EX22 - 3.02（pair の第 2 キーによるソート）
 */

#include <bits/stdc++.h>
using namespace std;

struct Record {
    string key1;  // 第 1 キー：昇順
    int key2;     // 第 2 キー：降順
    int id;       // 元の添字（0-based）
};

void sort_records(vector<Record>& records) {
    sort(records.begin(), records.end(),
         [](const Record& a, const Record& b) {
             if (a.key1 != b.key1) return a.key1 < b.key1;   // 第 1：昇順
             if (a.key2 != b.key2) return a.key2 > b.key2;   // 第 2：降順
             return a.id < b.id;                             // tie-break
         });
}

// 使用例：
// vector<Record> r(n);
// for (int i = 0; i < n; ++i) { cin >> r[i].key1 >> r[i].key2; r[i].id = i; }
// sort_records(r);
// for (auto& e : r) cout << e.id + 1 << '\n';  // 問題が 1-based なら +1
