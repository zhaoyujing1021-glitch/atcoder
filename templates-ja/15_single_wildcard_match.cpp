/**
 * 【テンプレート 15】単一文字ワイルドカード照合（'*' はちょうど 1 文字に一致）
 *
 * 【用途 / 適用場面】
 *   同じ長さの 2 つの文字列が各位置で一致するか判定する。パターン側の
 *   '*' は任意の 1 文字に一致し、それ以外の位置は完全一致でなければならない。
 *   典型的な問題：Wild Card、簡単なパスワード照合、マスク照合。
 *
 * 【時間・空間計算量】
 *   時間 O(n)、追加空間 O(1)。
 *
 * 【注意事項 / 境界条件】
 *   - 長さが等しくなければ false を返す。
 *   - '*' は 1 文字だけに一致し、0 文字や複数文字には一致しない。
 *     glob や正規表現ではない。
 *   - パターン自体にエスケープ文字が含まれる場合は、追加の規則が必要。
 *   - 大文字・小文字を区別する。区別しない場合は先に両方を同じ大小文字に揃える。
 *   - '*' が任意長（空文字を含む）に一致する必要がある場合は、
 *     二点探索の貪欲法か DP を使う。
 *
 * 【出典】ABC476 B - Wild Card
 */

#include <bits/stdc++.h>
using namespace std;

bool match_single_wildcard(const string& s, const string& pattern,
                           char wildcard = '*') {
    if (s.size() != pattern.size()) return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (pattern[i] != wildcard && pattern[i] != s[i]) return false;
    }
    return true;
}
