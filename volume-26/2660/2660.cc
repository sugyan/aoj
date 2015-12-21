#include <iostream>
#include <limits>
using namespace std;

const int MAX_SIZE = 300;

int cost(int x, int y) {
  int sum = 0, c = 0;
  while (x || y) {
    sum += (x % 10) * (y % 10) + c;
    c = x % 10 + y % 10 + c < 10 ? 0 : 1;
    x /= 10;
    y /= 10;
  }
  return sum + c;
}

int calc(int a[], int b[][MAX_SIZE], int s[][MAX_SIZE], int N) {
  for (int i = 0; i < N; ++i) {
    s[i][i] = a[i];
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < N - i; ++j) {
      s[j][j + i] = s[j][j + i - 1] + a[j + i];
      b[j][j + i] = numeric_limits<int>::max();
      for (int k = 0; k < i; ++k) {
        b[j][j + i] = min(b[j][j + i],
                          b[j][j + k] + b[j + k + 1][j + i] + cost(s[j][j + k], s[j + k + 1][j + i]));
      }
    }
  }
  return b[0][N - 1];
}

int main() {
  int N;
  int a[MAX_SIZE];
  int s[MAX_SIZE][MAX_SIZE] = {};
  int b[MAX_SIZE][MAX_SIZE] = {};
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  cout << calc(a, b, s, N) << endl;
}
