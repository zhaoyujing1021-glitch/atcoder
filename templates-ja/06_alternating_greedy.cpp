/**
 * 【テンプレート 06】交互取得の最適解（ソート後に大きい順で交互に取る）
 *
 * 【用途 / 適用場面】
 *   2 人が山から交互に数を取る。毎回、残っている任意の要素を取ることができ、
 *   双方が自分の合計を最大にしようとする。先手の合計、後手の合計、
 *   またはその差を求める。
 *   典型的な問題：Card Game for Two、交互に石／カードを取る、
 *   双方が貪欲に最大値を取る、など。
 *
 * 【時間・空間計算量】
 *   時間 O(n log n)、追加空間 O(1)（引数の配列を変更してよい場合）。
 *   元の配列を変更したくない場合は O(n) のコピーが必要。
 *
 * 【注意事項 / 境界条件】
 *   - 要素は負でもよい。ソート後に奇数番目と偶数番目を交互に足し引きする
 *     方法は負の値でも成立する。
 *   - 「毎回、両端からしか取れない」ルールの場合は本テンプレートを使えない。
 *     区間 DP が必要。
 *   - 「毎回固定個数しか取れない」「取得数に上限がある」場合もこのモデルではない。
 *   - 返す差は負になることがあるため long long を使う。
 *
 * 【出典】ABC088 B - Card Game for Two
 */

#include <bits/stdc++.h>
using namespace std;

// {先手の合計, 後手の合計} を返す
pair<long long, long long> alternating_pick_scores(vector<long long> a) {
    sort(a.begin(), a.end(), greater<long long>());

    long long first = 0, second = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (i % 2 == 0) {
            first += a[i];
        } else {
            second += a[i];
        }
    }
    return {first, second};
}

long long alternating_pick_difference(vector<long long> a) {
    auto [first, second] = alternating_pick_scores(std::move(a));
    return first - second;
}
