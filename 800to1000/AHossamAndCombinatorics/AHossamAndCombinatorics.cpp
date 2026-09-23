#include <bits/stdc++.h>
#include <climits>
using namespace std;

vector<int> read_test_case() {
  int n;
  cin >> n;

  cin.ignore();

  vector<int> test_case;
  int num;

  for (int j = 0; j < n; j++) {
    cin >> num;
    test_case.push_back(num);
  }

  cin.ignore();

  return test_case;
}

int count(vector<int> input, int target) {
  int count = 0;
  for (int i = 0; i < (int)input.size(); i++) {
    if (input[i] == target) {
      count++;
    }
  }
  return count;
}

long long solve() {
  vector<int> input = read_test_case();
  int minimum = INT_MAX;
  int maximum = INT_MIN;

  for (int i = 0; i < (int)input.size(); i++) {
    if (input[i] > maximum) {
      maximum = input[i];
    }
    if (input[i] < minimum) {
      minimum = input[i];
    }
  }
  long long n = input.size();
  if (maximum == minimum) {
    // every ordered pair (i, j), i != j, ties at a difference of 0
    return n * (n - 1);
  }
  long long mincount = count(input, minimum);
  long long maxcount = count(input, maximum);
  return 2 * mincount * maxcount;
}

int main() {
  int t;
  cin >> t;
  cin.ignore();
  for (int i = 0; i < t; i++) {
    cout << solve() << "\n";
  }
}
