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
    ll N, K;
    cin >> N >> K;
    vector<ll> list_A(N);
    for (ll i = 0; i < N; i++) cin >> list_A[i];
    sort(list_A.begin(), list_A.end());

    for (ll bit = 0; bit < 60; bit++){
        ll c = (1LL << bit);
        if (K < c) break;
        for (ll i = 0; i < N; i++){
            if ((list_A[i] & (1LL << bit)) == 0){
                if (K >= c){
                    K -= c;
                    list_A[i] += c;
                } else break;
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < N; i++)
        ans += __builtin_popcountll(list_A[i]);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while (T--)
        solve();
}