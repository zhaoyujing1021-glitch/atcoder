/**
 * 【テンプレート 05】商と余りによる均等分配
 *   （total 個を groups 組にできるだけ均等に分ける）
 *
 * 【用途 / 適用場面】
 *   total 個の物品を groups 組に分け、どの 2 組の個数差も 1 以下にする。
 *   典型的な問題：ブドウの分配、行ごとの割り当て、負荷分散、ページ割り当てなど。
 *
 * 【時間・空間計算量】
 *   時間 O(groups)、追加空間 O(groups)（戻り値自体）。
 *
 * 【注意事項 / 境界条件】
 *   - groups は必ず > 0。total は負でもよい（床関数の意味で分配する）。
 *   - 最初の total % groups 組が 1 個多く受け取り、残りは 1 個少ない。
 *   - 「余りを後ろの組に回す」場合は、i < r を i >= groups - r に変更する。
 *   - 返すのは各組の個数だけ。具体的な分配内容が必要な場合は、
 *     同じループ内で生成する。
 *   - total が大きい場合は long long に注意。
 *
 * 【出典】ABC478 A - Grapes
 */

#include <bits/stdc++.h>
using namespace std;

vector<long long> distribute_evenly(long long total, int groups) {
    assert(groups > 0);

    // C++ の / と % は 0 方向に切り捨てられる。ここでは床関数に正規化する。
    long long q = total / groups;
    long long r = total % groups;
    if (r < 0) {
        r += groups;
        --q;
    }

    vector<long long> res(groups, q);
    for (int i = 0; i < (int)r; ++i) ++res[i];
    return res;
}

// 使用例：auto cnt = distribute_evenly(b, a);  // i 番目の組は cnt[i] 個
