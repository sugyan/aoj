#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P;
const int MAX_SIZE = 50;
const int MAX_TASK_SIZE = 1000;

int R, C, M, a = 0;
int p[MAX_SIZE][MAX_SIZE] = {};
char f[MAX_SIZE][MAX_SIZE];
int costs[3][MAX_SIZE][MAX_SIZE];

int move(P src, P des, int t) {
  if (src == des) {
    return t;
  }
  f[src.first][src.second] = '@';
  int ret = 0;
  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};
  for (int k = 0; k < 4; ++k) {
    int i = src.first  + dr[k];
    int j = src.second + dc[k];
    if (i + 1 && j + 1 && i < R && j < C && f[i][j] == '.') {
      ret = move(P(i, j), des, t + 1);
      if (ret) {
        int cost = costs[1][i][j] + costs[2][i][j];
        a += cost;
        if (p[i][j]) {
          int d = (t - p[i][j]) * costs[0][i][j] - cost;
          if (d < 0) a += d;
        }
        p[i][j] = t;
        break;
      }
    }
  }
  f[src.first][src.second] = '.';
  return ret;
}

int calc(P tasks[]) {
  int t = 1;
  int i0 = tasks[0].first, j0 = tasks[0].second;
  a = costs[1][i0][j0] + costs[2][i0][j0];
  p[i0][j0] = t++;
  for (int i = 0; i < M - 1; ++i) {
    t = move(tasks[i], tasks[i + 1], t);
  }
  return a;
}

int main() {
  int n;
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
  cout << calc(tasks) << endl;
}
