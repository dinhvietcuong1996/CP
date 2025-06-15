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
    vector<pair<ll,ll>> edges(N - 1);
    for (ll i = 0; i < N - 1; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }
    vector<vector<ll>> tree(N);
    for (auto& edge : edges) {
        tree[edge.first].push_back(edge.second);
        tree[edge.second].push_back(edge.first);
    }

    // euler tour
    vector<ll> euler_start(N), euler_end(N);
    ll timer = 1;
    function<void(ll, ll)> dfs = [&](ll node, ll parent) {
        euler_start[node] = timer;
        ll cnt_child = 0;
        for (ll j = 0; j < tree[node].size(); j++) {
            ll child = tree[node][j];
            if (child != parent){
                cnt_child++;
                if (cnt_child > 1) timer++;
                dfs(child, node);
            }
        }
        euler_end[node] = timer;
    };
    dfs(0, -1);
    for (ll i = 0; i < N; i++) cout << euler_start[i] << " " << euler_end[i] << endl;
    // cout << "Euler Tour Start: ";
    // for (ll i = 0; i < N; i++)
    //     cout << euler_start[i] << " ";
    // cout << endl;
    // cout << "Euler Tour End: ";
    // for (ll i = 0; i < N; i++)
    //     cout << euler_end[i] << " ";
    // cout << endl;


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--)
        solve();
}