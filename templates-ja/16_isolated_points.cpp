/**
 * 【テンプレート 16】ソート後に「孤立点」を抽出する（最近傍との距離 >= d）
 *
 * 【用途 / 適用場面】
 *   数直線上の n 個の点と元の番号が与えられたとき、左右に隣接する点との
 *   距離がともに d 以上である点をすべて求め、元の番号の昇順で出力する。
 *   典型的な問題：Standing Outliers、外れ値検出、疎な点の抽出。
 *
 * 【時間・空間計算量】
 *   時間 O(n log n)（ソート + 結果のソート）、追加空間 O(n)。
 *
 * 【注意事項 / 境界条件】
 *   - ソート後の直接の左右隣接点とのみ比較する。「任意の点との距離が d 以上」
 *     という条件でも、最近傍は隣接点なので等価になる。
 *   - 端点は隣接点が 1 つだけなので、存在する側だけを調べる。
 *   - 距離が厳密に d 未満の場合だけ「孤立していない」と判定する。
 *     距離がちょうど d なら孤立とみなす。
 *   - 重複点の距離は 0 なので、d > 0 なら互いに除外される。
 *     d = 0 の場合はすべての点が条件を満たす。
 *   - 返すのは 0-based の元の添字。問題が 1-based なら +1 する。
 *   - 個数だけが必要な場合は、最後のソートを省略できる。
 *
 * 【出典】ABC477 B - Standing Outliers
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> isolated_point_ids(const vector<long long>& x, long long d) {
    int n = (int)x.size();
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        if (x[i] != x[j]) return x[i] < x[j];
        return i < j;  // 同じ値の場合は元の添字順にして結果を確定させる
    });

    vector<int> res;
    for (int k = 0; k < n; ++k) {
        int i = ord[k];
        bool ok = true;
        if (k > 0 && x[i] - x[ord[k - 1]] < d) ok = false;
        if (k + 1 < n && x[ord[k + 1]] - x[i] < d) ok = false;
        if (ok) res.push_back(i);
    }

    sort(res.begin(), res.end());  // 元の番号順に出力
    return res;
}
