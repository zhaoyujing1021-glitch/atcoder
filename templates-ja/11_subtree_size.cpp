/**
 * 【テンプレート 11】木の部分木サイズ（反復 DFS で再帰スタック溢れを回避）
 *
 * 【用途 / 適用場面】
 *   root を根とする木（children 隣接リストで表現）について、各頂点の
 *   部分木サイズ（自身を含む）を求める。
 *   典型的な問題：組織の報告人数、木 DP の前処理、部分木クエリ、
 *   重心／直径計算の補助。
 *
 * 【時間・空間計算量】
 *   時間 O(n)、追加空間 O(n)（order スタック + 結果配列）。
 *
 * 【注意事項 / 境界条件】
 *   - children は「有向」の親 -> 子関係でなければならない。親を含む
 *     無向隣接リストをそのまま渡してはいけない。無向グラフの場合は、
 *     まず根を決めて DFS で親子関係を作る。
 *   - すべての頂点が root から到達可能である必要がある。到達できない
 *     頂点のサイズは 0 のままになる。
 *   - root は [0, n) の範囲内でなければならない。
 *   - 再帰ではなく明示的なスタックを使うため、n が 2e5/1e6 でも
 *     スタックオーバーフローしない。
 *   - 特定の部分木だけが必要な場合は帰りがけ順の処理で早期に返せるが、
 *     本テンプレートは全頂点を一度に計算する。
 *
 * 【出典】APG4B EX20 - 2.05（組織の報告人数）
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> subtree_sizes(const vector<vector<int>>& children, int root) {
    int n = (int)children.size();
    vector<int> order;
    order.reserve(n);

    // まず行きがけ順の走査を行い、「親が子より前」になる順序を得る。
    vector<int> st;
    st.push_back(root);
    while (!st.empty()) {
        int v = st.back();
        st.pop_back();
        order.push_back(v);
        for (int c : children[v]) st.push_back(c);
    }

    // 逆順に加算する。v を処理する時点で子はすべて計算済みになる。
    vector<int> sz(n, 0);
    for (int i = (int)order.size() - 1; i >= 0; --i) {
        int v = order[i];
        sz[v] = 1;  // 自身
        for (int c : children[v]) sz[v] += sz[c];
    }
    return sz;
}
