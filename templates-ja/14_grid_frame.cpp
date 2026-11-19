/**
 * 【テンプレート 14】グリッドの周囲に枠を追加する
 *
 * 【用途 / 適用場面】
 *   H x W の文字グリッドの上下左右に指定文字を 1 行／1 列ずつ追加し、
 *   (H+2) x (W+2) の新しいグリッドを作る。
 *   典型的な問題：Picture Frame、枠付き図形の出力、盤面／迷路の外枠。
 *
 * 【時間・空間計算量】
 *   時間 O(H * W)、追加空間 O(H * W)（戻り値）。
 *
 * 【注意事項 / 境界条件】
 *   - グリッドは矩形でなければならない。空のグリッドは空を返す。
 *   - 枠は 1 文字の char。複数文字の枠にしたい場合は、string sep を
 *     繰り返し文字列に変更する。
 *   - 元のグリッドの幅が 0 でも、上下の枠と左右の枠は生成される。
 *   - 出力するだけで保存が不要な場合は、1 行ずつ表示すれば O(HW) の
 *     メモリを省略できる。
 *   - 枠文字が元の内容と衝突しないようにする（後で連結成分処理をする場合など）。
 *
 * 【出典】ABC062 B - Picture Frame
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> add_border(const vector<string>& grid, char border = '#') {
    int h = (int)grid.size();
    if (h == 0) return {};
    int w = (int)grid[0].size();

    string sep(w + 2, border);
    vector<string> res;
    res.reserve(h + 2);
    res.push_back(sep);
    for (const string& row : grid) {
        res.push_back(string(1, border) + row + string(1, border));
    }
    res.push_back(sep);
    return res;
}
