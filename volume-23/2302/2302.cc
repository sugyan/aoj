#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<P> V;
typedef map<PP, V> Cache;
const int MAX_SIZE = 50;
const int MAX_TASK_SIZE = 1000;

vector<P> dfs(char f[MAX_SIZE][MAX_SIZE], P src, P des, int R, int C) {
  vector<P> v;
  if (src == des) {
    v.push_back(des);
    return v;
  }
  f[src.first][src.second] = '@';
  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};
  for (int k = 0; k < 4; ++k) {
    int i = src.first  + dr[k];
    int j = src.second + dc[k];
    if (i + 1 && j + 1 && i < R && j < C && f[i][j] == '.') {
      v = dfs(f, P(i, j), des, R, C);
      if (v.size()) {
        v.insert(v.begin(), src);
        break;
      }
    }
  }
  f[src.first][src.second] = '.';
  return v;
}

int calc(int R, int C, int M, char f[][MAX_SIZE], int costs[][MAX_SIZE][MAX_SIZE], P tasks[]) {
  Cache cache;
  int p[MAX_SIZE][MAX_SIZE] = {};
  int t = 0;
  int i0 = tasks[0].first, j0 = tasks[0].second;
  int a = costs[1][i0][j0] + costs[2][i0][j0];
  p[i0][j0] = ++t;
  for (int i = 0; i < M - 1; ++i) {
    P src = tasks[i], des = tasks[i + 1];
    V v;
    Cache::iterator find = cache.find(PP(src, des));
    if (find != cache.end()) {
      v = find->second;
    } else {
      v = dfs(f, src, des, R, C);
      cache.insert(pair<PP, V>(PP(src, des), v));
    }
    for (V::iterator vit = ++v.begin(); vit != v.end(); ++vit) {
      ++t;
      int r = vit->first, c = vit->second;
      int prev = p[r][c];
      int cost = costs[1][r][c] + costs[2][r][c];
      a += cost;
      if (prev) {
        int d = (t - prev) * costs[0][r][c] - cost;
        if (d < 0) a += d;
      }
      p[r][c] = t;
    }
  }
  return a;
}

int main() {
  int n;
  int R, C, M;
  char f[MAX_SIZE][MAX_SIZE];
  int costs[3][MAX_SIZE][MAX_SIZE];
  P tasks[MAX_TASK_SIZE];
  char s[MAX_SIZE + 1];
  cin >> R >> C >> M;
  for (int i = 0; i < R; ++i) {
    cin >> s;
    for (int j = 0; j < C; ++j) {
      f[i][j] = s[j];
    }
  }
  for (int k = 0; k < 3; ++k) {
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        cin >> n;
        costs[k][i][j] = n;
      }
    }
  }
  for (int i = 0; i < M; ++i) {
    int r, c;
    cin >> r >> c;
    tasks[i] = P(r, c);
  }
  cout << calc(R, C, M, f, costs, tasks) << endl;
}
