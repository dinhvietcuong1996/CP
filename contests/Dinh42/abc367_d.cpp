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
    vector<ll> list_A(N);
    for (ll i = 0; i < N; i++) cin >> list_A[i];

    vector<ll> prefix_sum_A(2*N+1, 0);
    for (ll i = 0; i < 2 * N; i++)
        prefix_sum_A[i + 1] = (prefix_sum_A[i] + list_A[i % N]) % M;

    vector<ll> prefix_sum_A_mod_M(M, 0);
    ll cnt = 0;
    for (ll i = 0; i <= 2 * N; i++){
        if (i >= N) prefix_sum_A_mod_M[prefix_sum_A[i-N] % M]--;
        if (i >= N + 1) cnt += prefix_sum_A_mod_M[prefix_sum_A[i] % M];
        prefix_sum_A_mod_M[prefix_sum_A[i] % M]++;
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
