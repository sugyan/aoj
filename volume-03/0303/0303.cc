#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

int calc(int N, int c[], int w[]) {
  bool g[MAX_SIZE][MAX_SIZE];
  int s[MAX_SIZE][MAX_SIZE], a[MAX_SIZE];
  for (int i = 0; i < N; ++i) {
    for (int j = i; j < N; ++j) {
      s[i][j] = (j > 0 ? s[i][j - 1] : 0) + w[j];
    }
  }
  for (int i = 0; i < N; ++i) g[i][i] = true;
  for (int k = 1; k < N; ++k) {
    for (int i = 0; i < N - k; ++i) {
      int j = i + k;
      g[i][j] = (g[i][j - 1] && s[i][j - 1] <= c[j]) || (g[i + 1][j] && s[i + 1][j] <= c[i]);
    }
  }
  a[0] = 1;
  for (int i = 1; i < N; ++i) {
    a[i] = g[0][i] ? 1 : a[i - 1] + 1;
    for (int j = 0; j < i; ++j) {
      if (g[j + 1][i] && a[j] + 1 < a[i]) a[i] = a[j] + 1;
    }
  }
  return a[N - 1];
}

int main() {
  int N, c[MAX_SIZE], w[MAX_SIZE];
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> c[i] >> w[i];
  }
  cout << calc(N, c, w) << endl;
}
