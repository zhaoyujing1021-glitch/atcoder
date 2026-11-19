/**
 * 【テンプレート 04】オンラインで第 k 位（重複除去）を維持する
 *
 * 【用途 / 適用場面】
 *   要素を一つずつ追加しながら、その時点の「k 番目に大きい異なる値」を
 *   いつでも取得する。
 *   典型的な問題：数を読むたびに現在の 3 番目に大きい値を出力する
 *   （存在しない場合は出力しない）など。
 *
 * 【時間・空間計算量】
 *   add 1 回：O(log k)、取得：O(1)、追加空間：O(k)。
 *   全体では O(n log k)。
 *
 * 【注意事項 / 境界条件】
 *   - 同じ値は 1 回だけ数える（重複除去）。「重複を除かない第 k 位」が
 *     必要な場合は multiset か頻度カウントを使う。
 *   - 異なる値が k 個未満のとき has_kth() は false を返す。
 *     その状態で kth_largest() を呼んではいけない。
 *   - k <= 0 のとき add は何もせず、has_kth() は常に false。
 *   - 大きい方から k 個だけ保持する。小さい値はすぐに捨てられるため、
 *     ストリームデータに向いている。
 *   - 第 k 小が必要な場合は、set の比較方向を逆にするか rbegin を使う。
 *
 * 【出典】ABC476 C - Third Largest Number
 */

#include <bits/stdc++.h>
using namespace std;

class TopKDistinct {
  public:
    explicit TopKDistinct(int k) : k_(k) {}

    void add(long long x) {
        if (k_ <= 0) return;
        if (values_.count(x)) return;  // 重複除去
        values_.insert(x);
        if ((int)values_.size() > k_) {
            values_.erase(values_.begin());  // 最小値を捨てる
        }
    }

    bool has_kth() const { return (int)values_.size() == k_; }

    // 事前条件：has_kth() が true
    long long kth_largest() const { return *values_.begin(); }

    // 現在保持している最大 k 個の値を降順で返す
    vector<long long> values_desc() const {
        return vector<long long>(values_.rbegin(), values_.rend());
    }

  private:
    int k_;
    set<long long> values_;
};

// 一括版：配列全体の第 k 位（重複除去）を求める。存在しない場合は false。
bool kth_largest_distinct(const vector<long long>& a, int k, long long& out) {
    TopKDistinct top(k);
    for (long long x : a) top.add(x);
    if (!top.has_kth()) return false;
    out = top.kth_largest();
    return true;
}
