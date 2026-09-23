#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> scores;
  for (int i = 0; i < 3; i++) {
    int n;
    cin >> n;
    scores.push_back(n);
  }

  sort(scores.begin(), scores.end());

  if (scores[2] - scores[0] >= 10) {
    cout << "check again";
  } else {
    cout << "final " << scores[1];
  }
}
