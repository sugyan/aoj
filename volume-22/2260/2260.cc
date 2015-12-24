#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX_SIZE = 10;

int calc(char s[]) {
  int c = 0, l = strlen(s);
  if (l % 2) {
    if (s[l / 2] <= ')') c++;
  }
  for (int i = 0; i < l / 2; ++i) {
    if (s[i] <= ')') {
      if (abs(s[i] - s[l - i - 1]) != 1) c++;
    } else {
      if (s[i] != s[l - i - 1]) c++;
    }
  }
  return c;
}

int main() {
  char s[MAX_SIZE + 1];
  cin >> s;
  cout << calc(s) << endl;
}
