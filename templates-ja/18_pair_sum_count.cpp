/**
 * 【テンプレート 18】2 配列の和が一定値になるペア（ハッシュ O(n + m)）
 *
 * 【用途 / 適用場面】
 *   2 つの配列 A、B が与えられたとき、x + y = target を満たす
 *   (x, y)（x は A、y は B）の個数を数える。重複要素は出現回数で数える。
 *   典型的な問題：2 数の和のカウント、ペアの個数、A+B 問題。
 *
 * 【時間・空間計算量】
 *   期待 O(n + m) 時間、O(m) 追加空間。
 *   最悪ケース（ハッシュ衝突）は O(n * m)。厳密な保証が必要な場合は
 *   ソート + 二点探索を使う。
 *
 * 【注意事項 / 境界条件】
 *   - 数えるのは「順序対」（先に A を選び、次に B を選ぶ）であり、
 *     同一配列内の無順序対ではない。
 *   - 重複要素は多重集合として数える。A に同じ値が 2 個あれば、
 *     B の各一致値とそれぞれペアになる。
 *   - 結果は n*m に達することがあるため long long を使う。
 *   - target - x が long long をオーバーフローする可能性がある。
 *     極端な値の範囲では __int128 かソート法を使う。
 *   - 同一配列内で i < j を数える場合、そのままでは使えない。
 *     走査しながら「先に検索してから挿入」し、target が偶数のときの
 *     二重カウントに注意する。
 *   - 存在判定だけが必要な場合は、最初のペアが見つかった時点で
 *     早期に返せる。
 *
 * 【出典】APG4B EX17 - 2.02
 *   元のコードは O(N^2) の全探索。本テンプレートは等価な汎用 O(N + M) 版。
 */

#include <bits/stdc++.h>
using namespace std;

long long count_pairs_with_sum(const vector<long long>& a,
                               const vector<long long>& b,
                               long long target) {
    unordered_map<long long, long long> freq;
    freq.reserve(b.size() * 2 + 1);
    for (long long y : b) ++freq[y];

    long long ans = 0;
    for (long long x : a) {
        auto it = freq.find(target - x);
        if (it != freq.end()) ans += it->second;
    }
    return ans;
}

// 同一配列内で i < j かつ a[i] + a[j] = target となる組の数。
long long count_pairs_in_one_array(const vector<long long>& a,
                                   long long target) {
    unordered_map<long long, long long> seen;
    seen.reserve(a.size() * 2 + 1);

    long long ans = 0;
    for (long long x : a) {
        auto it = seen.find(target - x);
        if (it != seen.end()) ans += it->second;
        ++seen[x];
    }
    return ans;
}
