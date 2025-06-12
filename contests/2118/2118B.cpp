#include <iostream>
#include <vector>
#include <limits>         // numeric_limits<type>::max(), numeric_limits<type>::min()
#include <string>
#include <algorithm>      // sort, max, min, reverse, swap
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>        // accumulate
#include <cmath>      // pow, floor, ceil, round, abs
#include <iomanip>    // setprecision
#include <functional> // for function
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;

const ll INF = numeric_limits<ll>::max();
const ll NEG_INF = numeric_limits<ll>::min();
ll MOD = 998244353;

void solve(){
    ll N;
    cin >> N;
    vector<vector<ll>> ans;
    for (ll i = 1; i <= N; i++){
        if (i > 1) ans.push_back({i, 1, i});
        if (i < N - 1) ans.push_back({i, i + 1, N});
    }
    cout << ans.size() << endl;
    for (auto &a : ans)
        cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while (T--)
        solve();
}