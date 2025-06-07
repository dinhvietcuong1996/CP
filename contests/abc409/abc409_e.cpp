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
    vector<ll> list_vertices(N, 0);
    for (ll i = 0; i < N; i++) cin >> list_vertices[i];
    vector<vector<pair<ll,ll>>> graph(N);
    for (ll i = 0; i < N - 1; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    ll energy_cost = 0;
    vector<bool> visited(N, false);
    function<ll(ll)> dfs = [&](ll u){
        ll total_charge = 0;
        for (auto& [v, w] : graph[u]){
            if (visited[v]) continue;
            visited[v] = true;
            ll charge = dfs(v);
            total_charge += charge;
            energy_cost += w * abs(charge);
        }
        return total_charge + list_vertices[u];
    };
    dfs(0);
    cout << energy_cost << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--)
        solve();
}