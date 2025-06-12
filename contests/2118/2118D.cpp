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

void simulate(ll N, vector<ll> &list_P, vector<ll> &list_D, ll K, ll start_pos){
    ll cur_pos = start_pos;
    ll cur_time = 0;
    ll n_loops = 0;
    ll direc = 1;
    while (n_loops < 20000){
        ll light_idx = lower_bound(list_P.begin(), list_P.end(), cur_pos) - list_P.begin();
        if (light_idx == N || (light_idx == 0 && list_P[light_idx] > cur_pos)){
            cout << "YES" << endl;
            return;
        }
        // cout << "cur_pos: " << cur_pos << ", light_idx: " << light_idx << ", cur_time: " << cur_time << endl;
        if (list_P[light_idx] != cur_pos){
            if (direc < 0) light_idx--;
            cur_time += abs(list_P[light_idx] - cur_pos);
            cur_pos = list_P[light_idx];
            // cout << "cur_pos: " << cur_pos << ", light_idx: " << light_idx << ", cur_time: " << cur_time << endl;

        }
        if ((cur_time - list_D[light_idx]) % K == 0){
            if (direc > 0) direc = -1;
            else direc = 1;
        }
        if (direc > 0) cur_pos++;
        else cur_pos--;
        cur_time++;
        n_loops++;
        // cout << "cur_pos: " << cur_pos << ", light_idx: " << light_idx << ", cur_time: " << cur_time << endl;
        // cout << endl;
    }
    cout << "NO" << endl;
}

void solve(){
    ll N, K;
    cin >> N >> K;
    vector<ll> list_P(N), list_D(N);
    for (ll i = 0; i < N; i++) cin >> list_P[i];
    for (ll i = 0; i < N; i++) cin >> list_D[i];
    ll Q;
    cin >> Q;
    vector<ll> list_Q(Q);
    for (ll i = 0; i < Q; i++) cin >> list_Q[i];
    for (ll &a : list_Q){
        simulate(N, list_P, list_D, K, a);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while (T--)
        solve();
}