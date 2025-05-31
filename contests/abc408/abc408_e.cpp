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
#include <bitset>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;

ll MOD = 998244353;

class DSU {
public:
    vector<ll> parents, sizes;
    ll num_components;

    DSU(ll n){
        parents.assign(n, -1);
        sizes.assign(n, 1);
        for (ll i = 0; i < n; i++) parents[i] = i;
        num_components = n;
    }

    ll find(ll x){
        if (parents[x] == x) return x;
        parents[x] = find(parents[x]);
        return parents[x];
    }

    bool unite(ll x, ll y){
        ll x_root = find(x);
        ll y_root = find(y);
        if (x_root == y_root) return false;
        if (sizes[x_root] < sizes[y_root]) swap(x_root, y_root);
        parents[y_root] = x_root;
        sizes[x_root] += sizes[y_root];
        num_components--;
        return true;
    }

    bool is_connected(ll x, ll y){
        return find(x) == find(y);
    }

    ll get_component_size(ll x){
        return sizes[find(x)];
    }

    ll count_components() {
        return num_components;
    }
};

void solve(){
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> list_edges(M, vector<ll>(3, 0));
    for (ll i = 0; i < M; i++){
        cin >> list_edges[i][0] >> list_edges[i][1] >> list_edges[i][2];
        list_edges[i][0]--;
        list_edges[i][1]--;
    }
    ll mask = ((1 << 30) - 1);

    for (ll i = 30; i >= 0; i--){
        mask &= ~(1 << i);
        DSU dsu(N);
        for (vector<ll> &edge : list_edges){
            ll u = edge[0];
            ll v = edge[1];
            ll w = edge[2];
            if ((w & mask) == w) dsu.unite(u, v);
        }
        if (!dsu.is_connected(0, N - 1)){
            mask |= (1 << i);
        }
    }
    cout << mask << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--)
        solve();
}