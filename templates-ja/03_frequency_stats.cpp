/**
 * 【テンプレート 03】頻度統計の三種セット（重複除去カウント / 最頻値 / 奇数回出現値の総和）
 *
 * 【用途 / 適用場面】
 *   1) 異なる要素の個数を数える（重複除去）。
 *   2) 出現回数が最も多い要素（最頻値）を求める。同数の場合の規則も指定する。
 *   3) 出現回数が奇数回である要素の値の総和を求める。
 *   典型的な問題：鏡餅の種類数、Old Maid、最頻値など。
 *
 * 【時間・空間計算量】
 *   三つの関数はいずれも期待 O(n) 時間、O(n) 追加空間。
 *   （unordered_map / unordered_set の最悪ケースは O(n^2)。
 *     厳密な最悪計算量が必要な場合は map / set を使い、O(n log n) にする。）
 *
 * 【注意事項 / 境界条件】
 *   - 入力が空の場合：count_distinct は 0、mode は false を返し、
 *     sum_odd は 0 を返す。
 *   - 最頻値の同数規則：本実装は「最大頻度に最初に到達した値」を返す。
 *     つまり値の大小ではなく、最初に出現した順序で決まる。
 *   - 「値が最小／最大の最頻値」が必要な場合は、更新時に値を比較する。
 *   - sum_odd の結果は int を超える可能性があるため long long を使う。
 *   - key を long long / string にしたい場合はテンプレート引数を置き換える。
 *
 * 【出典】
 *   ABC085 B - Kagami Mochi（重複除去カウント）
 *   ABC473 B - Old Maid（奇数回出現値の総和）
 *   APG4B EX23 - 3.03（最頻値）
 */

#include <bits/stdc++.h>
using namespace std;

int count_distinct(const vector<long long>& a) {
    unordered_set<long long> seen;
    seen.reserve(a.size() * 2 + 1);
    for (long long x : a) seen.insert(x);
    return (int)seen.size();
}

// 入力が空の場合は false を返す。それ以外は mode_value / mode_count に結果を返す。
bool mode_first_occurrence(const vector<long long>& a,
                           long long& mode_value,
                           int& mode_count) {
    if (a.empty()) return false;

    unordered_map<long long, int> cnt;
    cnt.reserve(a.size() * 2 + 1);

    int best_cnt = 0;
    long long best_value = 0;
    for (long long x : a) {
        int c = ++cnt[x];
        // 厳密に大きい場合だけ更新するため、同数の場合は
        // その頻度に最初に到達した値が残る。
        if (c > best_cnt) {
            best_cnt = c;
            best_value = x;
        }
    }

    mode_value = best_value;
    mode_count = best_cnt;
    return true;
}

long long sum_values_with_odd_frequency(const vector<long long>& a) {
    unordered_map<long long, int> cnt;
    cnt.reserve(a.size() * 2 + 1);
    for (long long x : a) ++cnt[x];

    long long sum = 0;
    for (const auto& [value, c] : cnt) {
        if (c % 2 != 0) sum += value;
    }
    return sum;
}

// 使用例：
// int kinds = count_distinct(a);
// long long mode; int freq;
// if (mode_first_occurrence(a, mode, freq)) { ... }
// long long odd_sum = sum_values_with_odd_frequency(a);
