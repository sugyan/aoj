#include <iostream>
#include <queue>
using namespace std;

const int MAX_SIZE = 100;
const int SEATS = 17;

int* calc() {
  queue<int> q;
  int *a = new int[MAX_SIZE]();
  int g, n, s[SEATS] = {};
  for (int t = 0; ; ++t) {
    for (int i = 0; i < SEATS; ++i) {
      if (s[i]) s[i]--;
    }
    if (t % 5 == 0) q.push(t / 5);
    while (!q.empty()) {
      bool c = false;
      g = q.front();
      n = g % 5 == 1 ? 5 : 2;
      for (int i = 0; i < SEATS - n + 1; ++i) {
        if (n == 2 && !(s[i] || s[i + 1])) {
          s[i] = s[i + 1] = 17 * (g % 2) + 3 * (g % 3) + 19;
          c = true;
          break;
        }
        if (n == 5 && !(s[i] || s[i + 1] || s[i + 2] || s[i + 3] || s[i + 4])) {
          s[i] = s[i + 1] = s[i + 2] = s[i + 3] = s[i + 4] = 17 * (g % 2) + 3 * (g % 3) + 19;
          c = true;
          break;
        }
      }
      if (c) {
        a[g] = t - g * 5;
        if (g == MAX_SIZE - 1) return a;
        q.pop();
      } else {
        break;
      }
    }
  }
  return a;
}

int main() {
  int n;
  int *a = calc();
  while (true) {
    cin >> n;
    if (cin.eof()) break;
    cout << a[n] << endl;
  }
}
