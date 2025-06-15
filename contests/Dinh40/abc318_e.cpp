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
    vector<ll> list_A(N);
    for (ll i = 0; i < N; i++)
        cin >> list_A[i];

    vector<vector<ll>> list_values(N + 1);
    for (ll i = 0 ; i < N; i++) list_values[list_A[i]].push_back(i);

    ll cnt = 0;
    for (ll v = 0; v <= N; v++){
        for (ll i = 1; i < list_values[v].size(); i++){
            ll diff = list_values[v][i] - list_values[v][i - 1] - 1;
            cnt += diff * i * (list_values[v].size() - i);
        }
    }
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--)
        solve();
}