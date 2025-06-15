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
    ll N, M, X;
    cin >> N >> M >> X;
    vector<ll> list_C(N);
    vector<vector<ll>> list_books(N, vector<ll>(M));
    for (ll i = 0; i < N; i++){
        cin >> list_C[i];
        for (ll j = 0; j < M; j++) cin >> list_books[i][j];
    }
    ll cur_ans = numeric_limits<ll>::max();
    ll cur_cost = 0;
    vector<ll> understanding(M, 0);
    function<void(ll)> backtrack = [&](ll i) {
        if (i == N){
            for (ll &u : understanding)
                if (u < X) return;
            cur_ans = min(cur_ans, cur_cost);
            return;
        }
        backtrack(i + 1);

        cur_cost += list_C[i];
        for (ll j = 0; j < M; j++)
            understanding[j] += list_books[i][j];
        backtrack(i + 1);
        cur_cost -= list_C[i];
        for (ll j = 0; j < M; j++)
            understanding[j] -= list_books[i][j];
    };
    backtrack(0);
    if (cur_ans == numeric_limits<ll>::max())
        cout << -1 << endl;
    else
        cout << cur_ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--)
        solve();
}