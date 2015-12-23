#include <iostream>
#include <cmath>
using namespace std;

long long calc(int w, int h, int v, int t, int x, int y, int p, int q) {
  long long tx, ty, c = 0, d = v * t;
  for (int i = -d / w - 2; i < d / w + 2; ++i) {
    tx = i * w + (i % 2 ? w - p : p);
    if (abs(tx - x) > d) continue;
    double dy = sqrt(d * d - (tx - x) * (tx - x));
    if (abs(q - y) > dy) continue;

    int r[] = { (dy + y) / h, -(dy - y) / h - 1 };
    if (y > dy) r[1]--;
    if (r[0] == r[1]) {
      if ((tx - x) * (tx - x) + (q - y) * (q - y) <= d * d) c++;
    } else {
      c += r[0] - r[1] - 1;
      for (int k = 0; k < 2; ++k) {
        ty = r[k] * h + (r[k] % 2 ? h - q : q);
        if ((tx - x) * (tx - x) + (ty - y) * (ty - y) <= d * d) c++;
      }
    }
  }
  return c;
}

int main() {
  int w, h, v, t, x, y, p, q;
  cin >> w >> h >> v >> t >> x >> y >> p >> q;
  cout << calc(w, h, v, t, x, y, p, q) << endl;
}
