/**
 * 【テンプレート 13】グリッドの空行・空列の削除（grid compression）
 *
 * 【用途 / 適用場面】
 *   グリッドの中で「対象マークが 1 つもない行と列」を削除し、残りの行と列の
 *   相対順序を保つ。
 *   典型的な問題：Grid Compression、疎行列の圧縮、内容のある行と列だけを残す。
 *
 * 【時間・空間計算量】
 *   時間 O(H * W)、追加空間 O(H + W)（出力を除く）。
 *
 * 【注意事項 / 境界条件】
 *   - グリッドは矩形でなければならない。行ごとの長さが違う場合は、
 *     先に揃えるか別の構造を使う。
 *   - 空のグリッドは空を返す。すべての行／列に対象マークがない場合も空を返す。
 *   - 対象マークの既定値は '#'。問題に応じて 'o'、'1' などに変更する。
 *   - 列圧縮後は各行の長さが同じになる。元の幅が 0 の場合は空を返す。
 *   - その場で圧縮する場合は列 -> 行の順に削除できるが、string の削除は
 *     O(W) なので全体は O(HW) のまま。
 *
 * 【出典】ABC107 B - Grid Compression
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> remove_empty_rows_cols(const vector<string>& grid,
                                     char mark = '#') {
    int h = (int)grid.size();
    if (h == 0) return {};
    int w = (int)grid[0].size();
    if (w == 0) return {};

    vector<char> row_has(h, 0), col_has(w, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == mark) {
                row_has[i] = 1;
                col_has[j] = 1;
            }
        }
    }

    vector<string> res;
    for (int i = 0; i < h; ++i) {
        if (!row_has[i]) continue;
        string line;
        line.reserve(w);
        for (int j = 0; j < w; ++j) {
            if (col_has[j]) line.push_back(grid[i][j]);
        }
        res.push_back(std::move(line));
    }
    return res;
}
