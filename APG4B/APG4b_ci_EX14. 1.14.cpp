#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int maxt = max(max(a, b), c);
  int mint = min(min(a, b), c);

  cout << maxt - mint << endl;
}

