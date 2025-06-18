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

map<ll, ll> prime_factorization(ll n) {
    map<ll, ll> factors;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1)
        factors[n]++;
    return factors;
}

void solve(){
    ll N;
    cin >> N;
    vector<ll> list_A(N);
    for (ll i = 0; i < N; i++) cin >> list_A[i];
    multiset<ll> multiset_A(list_A.begin(), list_A.end());

    ll cnt = 0;
    for (ll i = 1; i <= 2e5; i++){
        ll a = i;
        ll cnt_a = multiset_A.count(a);
        if (cnt_a == 0) continue;
        map<ll, ll> factors = prime_factorization(a);
        ll b = 1;
        for (auto& [factor, power] : factors)
            if (power % 2 == 1)
                b *= factor;

        for (ll n = 1; n <= 2e5; n++){
            ll bs = n * n * b;
            if (bs > 2e5) break;
            if (bs == a){
                cnt += cnt_a * (cnt_a - 1);
                continue;
            }
            ll cnt_bs = multiset_A.count(bs);
            cnt += cnt_a * cnt_bs;
        }
    }
    cnt /= 2;
    ll cnt_0 = multiset_A.count(0);
    cnt += cnt_0 * (cnt_0 - 1) / 2;
    cnt += cnt_0 * (N - cnt_0);
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
