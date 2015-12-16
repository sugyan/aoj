#include <iostream>
#include <utility>
#include <queue>
using namespace std;

const int MAX_SIZE = 1000;
typedef pair<int, int> P;
typedef pair<int, P> Q;

int calc(int f[][MAX_SIZE], queue<Q> q, int H, int W) {
  P d[] = {P(-1, -1), P(-1, 0), P(-1, 1), P(0, -1), P(0, 1), P(1, -1), P(1, 0), P(1, 1)};
  int n = 0;
  while (q.size()) {
    int c = q.front().first;
    P p = q.front().second;
    q.pop();
    if (c > n) n++;
    for (int k = 0; k < 8; ++k) {
      int i = p.first  + d[k].first;
      int j = p.second + d[k].second;
      if (i >= 0 && i < H && j >= 0 && j < W && --f[i][j] == 0) {
        q.push(Q(c + 1, P(i, j)));
      };
    }
  }
  return n;
}

int main() {
  int H, W;
  int f[MAX_SIZE][MAX_SIZE];
  queue<Q> q;
  char c[MAX_SIZE];

  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> c;
    for (int j = 0; j < W; ++j) {
      if (c[j] == '.') {
        f[i][j] = 0;
        q.push(Q(0, P(i, j)));
      } else {
        f[i][j] = c[j] - '0';
      }
    }
  }
  cout << calc(f, q, H, W) << endl;
}
