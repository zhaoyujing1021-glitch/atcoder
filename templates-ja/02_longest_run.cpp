/**
 * 【テンプレート 02】最長連続同一文字区間（longest run）
 *
 * 【用途 / 適用場面】
 *   文字列や数列の中で、ある対象値が連続して現れる最大の長さを求める。
 *   典型的な問題：最長の連続 'R'、連続する晴れの日、連続する同じ数字など。
 *
 * 【時間・空間計算量】
 *   時間 O(n)、追加空間 O(1)。
 *
 * 【注意事項 / 境界条件】
 *   - 空文字列の場合は 0 を返す。
 *   - 大文字・小文字を区別する。区別しない場合は事前に統一する。
 *   - 「最長の連続部分配列で単調性などの条件を満たすもの」を求める場合は
 *     そのまま使えない。尺取り法や二点探索が必要。
 *   - 「最長区間の値と長さ」も必要な場合は、best_start や現在の文字を
 *     追加で記録する。
 *
 * 【出典】ABC479 B - Longest Rainy Streak
 */

#include <bits/stdc++.h>
using namespace std;

int longest_run(const string& s, char target) {
    int best = 0;
    int cur = 0;
    for (char c : s) {
        if (c == target) {
            ++cur;
            best = max(best, cur);
        } else {
            cur = 0;
        }
    }
    return best;
}

// 汎用版：任意の比較可能な型に対して使用する
template <class T>
int longest_run_generic(const vector<T>& a, const T& target) {
    int best = 0;
    int cur = 0;
    for (const T& x : a) {
        if (x == target) {
            ++cur;
            best = max(best, cur);
        } else {
            cur = 0;
        }
    }
    return best;
}
