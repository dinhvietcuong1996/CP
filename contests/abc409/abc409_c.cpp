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
    ll N, L;
    cin >> N >> L;
    vector<ll> circle(L, 0);
    ll cur_pos = 0;
    circle[cur_pos]++;
    for (ll i = 0; i < N - 1; i++){
        ll d;
        cin >> d;
        cur_pos += d;
        cur_pos %= L;
        circle[cur_pos]++;
    }
    if (L % 3 != 0){
        cout << 0 << endl;
        return;
    }
    ll p = L / 3;
    ll cnt = 0;
    cout << endl;
    for (ll i = 0; i < p; i++)
        cnt += circle[i] * circle[(i + p) % L] * circle[(i + 2 * p) % L];
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