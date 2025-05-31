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

ll MOD = 998244353;

void solve(){
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> list_turrets(M);
    for (ll i = 0; i < M; i++)
        cin >> list_turrets[i].first >> list_turrets[i].second;

    vector<ll> diff(N + 1, 0);
    for (pair<ll,ll> &turret : list_turrets){
        ll L = turret.first;
        ll R = turret.second;
        L--; R--;
        diff[L]++;
        diff[R+1]--;
    }
    vector<ll> list_walls(N, 0);
    list_walls[0] = diff[0];
    ll ans = list_walls[0];
    for (ll i = 1; i < N; i++){
        list_walls[i] = list_walls[i-1] + diff[i];
        ans = min(ans, list_walls[i]);
    }
    cout << ans << endl;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--)
        solve();
}