#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

double calc(int n, int w, int v[]) {
  int mv = 0, mr = 0, r[MAX_SIZE] = {};
  double a = 0.0;
  for (int i = 0; i < n; ++i) {
    r[v[i] / w]++;
    if (v[i] > mv) mv = v[i];
  }
  for (int i = 0; i < mv / w + 1; ++i) {
    if (r[i] > mr) mr = r[i];
  }
  for (int i = 0; i < mv / w; ++i) {
    a += 1.0 * r[i] / mr * (mv / w - i) / (mv / w);
  }

  return a + 0.01;
}

int main() {
  int n, w, v[MAX_SIZE];
  while (true) {
    cin >> n >> w;
    if (!n) break;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    cout << calc(n, w, v) << endl;
  }
}
