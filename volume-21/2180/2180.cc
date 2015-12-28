#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 86400;

bool ok(int N, int L, int s[], int t[], int u[], double m) {
  double w = L, e[2];
  for (int j = 0; j < 2; ++j) {
    for (int i = 0; i < N + 2; ++i) {
      w += (m - u[i]) * (t[i] - s[i]);
      if (w <= 0.0) {
        return false;
      }
      if (i < N + 1) {
        w += m * (s[i + 1] - t[i]);
      }
      if (w > L) w = L;
    }
    e[j] = w;
  }
  return e[1] >= e[0];
}

double calc(int N, int L, int s[], int t[], int u[]) {
  double l = 0.0, r = 1e6, m;
  while (true) {
    if (r - l < 1e-7) break;
    m = (l + r) / 2;
    if (ok(N, L, s, t, u, m)) {
      r = m;
    } else {
      l = m;
    }
  }
  return m;
}

int main() {
  int N, L, s[MAX_SIZE + 2], t[MAX_SIZE + 2], u[MAX_SIZE + 2];
  while (true) {
    cin >> N >> L;
    if (!N) break;
    for (int i = 0; i < N; ++i) {
      cin >> s[i + 1] >> t[i + 1] >> u[i + 1];
    }
    s[0] = 0; t[0] = s[1]; u[0] = 0;
    s[N + 1] = t[N]; t[N + 1] = 86400; u[N + 1] = 0;
    cout << fixed << setprecision(7) << calc(N, L, s, t, u) << endl;
  }
}
