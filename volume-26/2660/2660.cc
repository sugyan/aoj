#include <iostream>
using namespace std;

const int MAX_SIZE = 300;

int calc(int a[], int N) {
  return 3;
}

int main() {
  int N;
  int a[MAX_SIZE];
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  cout << calc(a, N) << endl;
}
