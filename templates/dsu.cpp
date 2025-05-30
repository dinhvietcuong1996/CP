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

int main(){
    return 0;
}