#include <bits/stdc++.h>
using namespace std;

tuple<vector<int>, vector<int>> read_test_case() {
  vector<int> test_case;
  vector<int> rounds;
  int num;

  // First line: always 4 numbers
  for (int j = 0; j < 4; j++) {
    cin >> num;
    test_case.push_back(num);
  }

  // Second line: a string of digits like "2211121"
  string s;
  cin >> s;
  for (char c : s) {
    rounds.push_back(c - '0'); // '2' -> 2, '1' -> 1
  }

  return {test_case, rounds};
}

int solve(vector<int> test_case, vector<int> rounds) {
  int r = test_case.at(0);
  int x = test_case.at(1);
  int d = test_case.at(2);

  int ans = 0;
  for (int i = 0; i < (int)rounds.size(); i++) {
    if (rounds[i] == 2 && r >= x) {
      continue;
    } else {
      r -= d;
      ans++;
    }
  }
  return ans;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    auto [test_case, rounds] = read_test_case();
    cout << solve(test_case, rounds) << "\n";
  }
}
