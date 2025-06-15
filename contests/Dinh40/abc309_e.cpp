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
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> list_children(N);
    for (ll i = 1; i < N; i++){
        ll parent;
        cin >> parent;
        parent--;
        list_children[parent].push_back(i);
    }
    map<ll, ll> list_insurance;
    for (ll i = 0; i < M; i++){
        ll x, y;
        cin >> x >> y;
        x--;
        if (list_insurance.find(x) == list_insurance.end() || list_insurance[x] < y)
            list_insurance[x] = y;
    }

    vector<bool> covered(N, false);
    queue<pair<ll, ll>> q;
    q.push({0, 0});
    while (!q.empty()){
        ll p = q.front().first;
        ll gen = q.front().second;
        q.pop();
        if (list_insurance.find(p) != list_insurance.end())
            gen = max(gen, list_insurance[p] + 1);
        if (gen > 0) covered[p] = true;
        for (ll &child : list_children[p])
            q.push({child, gen - 1});
    }
    
    ll cnt = 0;
    for (ll c : covered)
        if (c) cnt++;
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