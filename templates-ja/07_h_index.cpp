/**
 * 【テンプレート 07】h-index（h 指数）
 *
 * 【用途 / 適用場面】
 *   各論文の被引用数が与えられたとき、少なくとも h 本の論文の被引用数が
 *   h 以上であるような最大の h を求める。
 *   典型的な問題：Citation、学術評価、「少なくとも k 個の要素が k 以上」型の
 *   閾値問題。
 *
 * 【時間・空間計算量】
 *   時間 O(n log n)（ソート）、追加空間 O(1)（その場でソート）。
 *   被引用数の範囲が小さい場合はカウントソートで O(n) にできる。
 *
 * 【注意事項 / 境界条件】
 *   - 被引用数は非負整数を想定する。負の値があってもソート後のロジックは
 *     動作するが、h は n を超えない。
 *   - h の範囲は 0..n。空配列の場合は 0 を返す。
 *   - 降順に走査し、citations[i] >= i+1 なら h は少なくとも i+1。
 *   - 定義が「高々 h 本が h 以上」「ちょうど h 本」である場合は判定を変更する。
 *
 * 【出典】ABC409 B - Citation
 */

#include <bits/stdc++.h>
using namespace std;

int h_index(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    int h = 0;
    for (int i = 0; i < (int)citations.size(); ++i) {
        if (citations[i] >= i + 1) {
            h = i + 1;
        } else {
            break;  // 以降の被引用数はさらに小さくなる
        }
    }
    return h;
}
