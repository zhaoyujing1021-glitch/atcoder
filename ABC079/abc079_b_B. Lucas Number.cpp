#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin>>n;
  long long last0=2;
  long long last1=1;
  if(n == 0){
      cout <<last0<< endl;
      return 0;
    }else if(n == 1){
      cout << last1 << endl;
      return 0;
    }
  long long current = 0;
    for (int i = 2; i <= n; i++) {
        current = last0 + last1;
        last0 = last1;
        last1 = current;
    }
      cout <<last1<< endl;

  return 0;
}
