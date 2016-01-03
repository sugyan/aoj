#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAX_SIZE = 30;
typedef pair<double, double> P;

double calc(int n, double a[], double b[], double c[], double d[]) {
  double m = 0.0;
  P p[MAX_SIZE + 2][MAX_SIZE + 2];
  p[0][0] = P(0.0, 0.0);
  p[0][n + 1] = P(0.0, 1.0);
  p[n + 1][0] = P(1.0, 0.0);
  p[n + 1][n + 1] = P(1.0, 1.0);
  for (int i = 0; i < n; ++i) {
    p[i + 1][0]     = P(a[i], 0.0);
    p[i + 1][n + 1] = P(b[i], 1.0);
    p[0][i + 1]     = P(0.0, c[i]);
    p[n + 1][i + 1] = P(1.0, d[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      double e = abs((0.0 - a[j]) - c[i] * (b[j] - a[j]));
      double f = abs((1.0 - a[j]) - d[i] * (b[j] - a[j]));
      double r = e / (e + f);
      p[j + 1][i + 1] = P(r, c[i] + r * (d[i] - c[i]));
    }
  }
  for (int i = 0; i < n + 1; ++i) {
    for (int j = 0; j < n + 1; ++j) {
      P p1 = p[i][j], p2 = p[i][j + 1], p3 = p[i + 1][j], p4 = p[i + 1][j + 1];
      double s = (abs((p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first)) +
                  abs((p2.first - p4.first) * (p3.second - p4.second) - (p2.second - p4.second) * (p3.first - p4.first))) / 2.0;
      if (s > m) m = s;
    }
  }
  return m;
}

int main() {
  int n;
  double a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE], d[MAX_SIZE];
  while (true) {
    cin >> n;
    if (!n) break;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i) cin >> d[i];
    cout << fixed << setprecision(7) << calc(n, a, b, c, d) << endl;
  }
}
