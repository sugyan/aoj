#include <cmath>
#include <iostream>
using namespace std;

pair<int, int> calc(double d) {
  int num, den = 0;
  while (++den) {
    num = M_PI * den;
    if (M_PI > (num + 0.5) / den) num++;
    if (abs(M_PI - 1.0 * num / den) < d) break;
  }
  return pair<int, int>(num, den);
}

int main() {
  double d;
  while (true) {
    cin >> d;
    if (d == 0.0) break;
    pair<int, int> a = calc(d);
    cout << a.first << '/' << a.second << endl;
  }
}
