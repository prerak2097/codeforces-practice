#include <bits/stdc++.h>
using namespace std;

int solve() {
  int c;
  cin >> c;
  cin.ignore();
  vector<int> chips;
  for (int i = 0; i < c; i++) {
    int x;
    cin >> x;
    chips.push_back(x);
  }
  cin.ignore();
  int first_one = 0;
  bool isOne = false;
  for (int i = 0; i < (int)chips.size(); i++) {
    if (chips[i] == 1) {
      isOne = true;
      first_one = i;
      break;
    }
  }
  if (!isOne) {
    return 0;
  }

  int ans = 0;
  int k = (int)chips.size() - 1;
  for (int i = (int)chips.size() - 1; i >= first_one; i--) {
    if (chips[k] != 1) {
      k--;
      continue;
    }
    if (chips[i] == 0 && chips[k] == 1) {
      chips[i] = 1;
      chips[k] = 0;
      k--;
      ans++;
    }
  }
  return ans;
}

int main() {
  int t;
  cin >> t;

  cin.ignore();
  while (t--) {
    cout << solve() << '\n';
  }
}
