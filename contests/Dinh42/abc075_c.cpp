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

bool check_connected(vector<vector<bool>>& adj, ll N){
    vector<bool> visited(N, false);
    queue<ll> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()){
        ll node = q.front();
        q.pop();
        for (ll i = 0; i < N; i++){
            if (adj[node][i] && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }

    for (ll i = 0; i < N; i++)
        if (!visited[i]) return false;
    return true;
}


void solve(){
    ll N, M;
    cin >> N >> M;
    vector<vector<bool>> adj(N, vector<bool>(N, false));
    vector<pair<ll, ll>> edges;
    for (ll i = 0; i < M; i++){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u][v] = true;
        adj[v][u] = true;
        edges.push_back({u, v});
    }
    ll cnt = 0;
    for (ll i = 0; i < M; i++){
        ll u = edges[i].first;
        ll v = edges[i].second;
        adj[u][v] = false;
        adj[v][u] = false;
        if (!check_connected(adj, N))
            cnt++;
        adj[u][v] = true;
        adj[v][u] = true;
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
