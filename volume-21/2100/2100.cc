#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

pair<int, int> calc(int n, int h[]) {
  pair<int, int> a;
  for (int i = 0; i < n - 1; ++i) {
    int d = h[i + 1] - h[i];
    if (d > 0) {
      if (d > a.first) a.first = d;
    } else {
      if (-d > a.second) a.second = -d;
    }
  }
  return a;
}

int main() {
  int t, n, h[MAX_SIZE];
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    for (int j = 0; j < n; ++j) {
      cin >> h[j];
    }
    pair<int, int> a = calc(n, h);
    cout << a.first << ' ' << a.second << endl;
  }
}
