#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h,w;
    cin >> h>>w;
    
    for (int i = 0; i < w+2; i++) {
      cout << '#';
    }
    cout<< endl;
    
    for (int i = 0; i < h; i++) {
      string str;
      cin >>str;
      
      cout << '#';
      for(int j=0;j<w;j++){
        cout<<str[j];
      }
      cout<<'#'<< endl;
    }
    for (int i = 0; i < w+2; i++) {
      cout << '#';
    }
    cout<< endl;
    return 0;
}