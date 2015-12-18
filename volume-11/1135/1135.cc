#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100;

int calc(int a, int y, int n, int soc[], double air[], int aoc[]) {
  int r = 0;
  for (int i = 0; i < n; ++i) {
    int A = a;
    if (soc[i] == 0) {
      int interest = 0;
      for (int j = 0; j < y; ++j) {
        interest += A * air[i];
        A -= aoc[i];
      }
      A += interest;
    } else {
      for (int j = 0; j < y; ++j) {
        A += A * air[i] - aoc[i];
      }
    }
    r = max(r, A);
  }
  return r;
}

int main() {
  int a, n, m, y;
  int soc[MAX_SIZE], aoc[MAX_SIZE];
  double air[MAX_SIZE];
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> y >> n;
    for (int j = 0; j < n; ++j) {
      cin >> soc[j] >> air[j] >> aoc[j];
    }
    cout << calc(a, y, n, soc, air, aoc) << endl;
  }
}
