#include <bits/stdc++.h>
#include <iterator>
#include <sstream>
using namespace std;

void solve() {}

int main() {
  int a, b;
  cin >> a >> b;
  cin.ignore();
  string s;
  getline(cin, s);
  istringstream iss(s);
  vector<int> nums(istream_iterator<int>{iss}, istream_iterator<int>{});
  int count = 0;
  for (int &n : nums) {
    n += b;
    if (n <= 5) {
      count++;
    }
  }
  cout << count / 3;
}
