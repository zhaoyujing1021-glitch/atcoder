/**
 * 【テンプレート 09】配列を整列させるために必要な最小の連続区間
 *
 * 【用途 / 適用場面】
 *   「連続する部分配列を 1 回だけソートする」ことで配列全体を昇順に
 *   できるか判定し、最小の区間長を求める。「長さ k 以下の部分配列を
 *   ソートして整列できるか」の判定にも使える。
 *   典型的な問題：Sort Subarray、最小ソート区間、ほぼ整列済み配列の判定。
 *
 * 【時間・空間計算量】
 *   時間 O(n log n)（ソート）、追加空間 O(n)（整列済みコピーを保存）。
 *
 * 【注意事項 / 境界条件】
 *   - 既に整列済みの場合は {-1, -1} を返し、長さは 0 とする。
 *   - 重複要素があっても結論は変わらない。値と整列済みコピーを比較する。
 *   - 結論が成り立つ理由：区間外では a[i] == sorted[i] なので、区間内の
 *     多重集合は整列後と一致する。したがってその区間をソートすればよい。
 *   - k は許されるソート区間の最大長。k >= 0。
 *     k = 0 のときは元の配列が整列済みの場合だけ true。
 *   - 「任意の 2 要素を交換する」問題とはモデルが異なる。
 *
 * 【出典】ABC478 C - Sort Subarray
 */

#include <bits/stdc++.h>
using namespace std;

// {l, r} を返す：ソートが必要な最小の閉区間。整列済みなら {-1, -1}。
pair<int, int> min_sort_interval(const vector<long long>& a) {
    int n = (int)a.size();
    vector<long long> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != sorted_a[i]) {
            if (l == -1) l = i;
            r = i;
        }
    }
    return {l, r};
}

bool can_sort_with_one_subarray(const vector<long long>& a, int k) {
    auto [l, r] = min_sort_interval(a);
    if (l == -1) return true;              // 既に整列済み
    return (r - l + 1) <= k;
}
