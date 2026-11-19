/**
 * 【テンプレート 17】折れ線が水平線を横切る回数
 *
 * 【用途 / 適用場面】
 *   数列 a[0..n-1] を折れ線の y 値とみなし、水平線 y = level との
 *   「接触回数」を数える。頂点がちょうど水平線上にある場合は 1 回、
 *   隣接する 2 点が水平線の両側にある（厳密に跨ぐ）場合も 1 回と数える。
 *   典型的な問題：Polyline、ある閾値を通過した回数、横断回数。
 *
 * 【時間・空間計算量】
 *   時間 O(n)、追加空間 O(1)。
 *
 * 【注意事項 / 境界条件】
 *   - これは「頂点／辺ごとの数え方」の規約に基づく。頂点が線上なら 1 回、
 *     厳密な横断なら 1 回。
 *   - 連続する複数の頂点が水平線上にある場合、各頂点を 1 回ずつ数える。
 *     問題が「1 つのプラトーを 1 回だけ」と要求する場合は、連続する
 *     等値区間を併合する必要がある。
 *   - 辺が水平線に沿う場合（a[i] == a[i+1] == level）、本テンプレートでは
 *     2 回（2 頂点分）と数える。これは幾何学的な「横断」ではない。
 *   - 空の数列は 0 を返す。要素が 1 つの場合は、その点が線上かだけを判定する。
 *   - level と a の要素型を一致させ、暗黙変換を避ける。
 *
 * 【出典】ABC481 B - Polyline
 */

#include <bits/stdc++.h>
using namespace std;

int count_level_crossings(const vector<long long>& a, long long level) {
    int cnt = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (a[i] == level) ++cnt;  // 頂点が水平線上にある

        if (i + 1 < (int)a.size()) {
            bool up_cross = (a[i] < level && a[i + 1] > level);
            bool down_cross = (a[i] > level && a[i + 1] < level);
            if (up_cross || down_cross) ++cnt;  // 厳密な横断
        }
    }
    return cnt;
}
