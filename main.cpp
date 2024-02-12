#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll h, w;
vs f;
vvl ans;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> h >> w;

  f = vs(h);
  for (auto&& x : f) {
    cin >> x;
  }

  ans = vvl(h, vl(w, -1));
  for (auto r = 0; r < h; ++r) {
    for (auto c = 0; c < w; ++c) {
      auto x = 0;
      for (auto t = 0; t < w; ++t) {
        if (c - t < 0) {
          break;
        }

        if ('c' == f[r][c - t]) {
          ans[r][c] = x;
          break;
        }

        ++x;
      }
    }
  }

  for (const auto& row : ans) {
    for (const auto& x : row) {
      cout << x << ' ';
    }
    cout << '\n';
  }

  return 0;
}