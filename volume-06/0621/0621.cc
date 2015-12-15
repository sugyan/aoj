#include <iostream>
#include <utility>
#include <set>
#include <vector>
using namespace std;

const int MAX_SIZE = 1000;
typedef pair<int, int> P;

int calc(char f[][MAX_SIZE], vector<P> v, int H, int W) {
  int c = 0;
  int di[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int dj[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  while(++c) {
    vector<P> b;
    set<P> s;
    for (vector<P>::iterator it = v.begin(); it != v.end(); ++it) {
      int i = it->first, j = it->second;
      int n = 0;
      for (int k = 0; k < 8; ++k) {
        if (i + di[k] >= 0 && i + di[k] < H &&
            j + dj[k] >= 0 && j + dj[k] < W &&
            f[i + di[k]][j + dj[k]] == '.') {
          n++;
        }
      }
      if (n >= f[i][j] - '0') {
        b.push_back(P(i, j));
        for (int k = 0; k < 8; ++k) {
          if (i + di[k] >= 0 && i + di[k] < H &&
              j + dj[k] >= 0 && j + dj[k] < W &&
              f[i + di[k]][j + dj[k]] != '.') {
              s.insert(P(i + di[k], j + dj[k]));
          }
        }
      }
    }
    if (!b.size()) {
      return c - 1;
    }
    for (vector<P>::iterator it = b.begin(); it != b.end(); ++it) {
      f[it->first][it->second] = '.';
      s.erase(P(it->first, it->second));
    }
    v = vector<P>(s.begin(), s.end());
  }
  return 0;
}

int main() {
  int H, W;
  char f[MAX_SIZE][MAX_SIZE];
  set<P> s;

  cin >> H >> W;
  for (int i = 0; i < H; ++i) {
    cin >> f[i];
    for (int j = 0; j < W; ++j) {
      if (f[i][j] != '.') {
        s.insert(P(i, j));
      }
    }
  }
  cout << calc(f, vector<P>(s.begin(), s.end()), H, W) << endl;
}
