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

vector<ll> power2(1e5+1);

void solve(){
    ll N;
    cin >> N;
    vector<ll> list_P(N), list_Q(N);
    for (ll i = 0; i < N; i++) cin >> list_P[i];
    for (ll i = 0; i < N; i++) cin >> list_Q[i];

    vector<ll> list_R(N);
    ll i_P = 0, i_Q = 0;
    for (ll i = 0; i < N; i++){
        if (list_P[i] > list_P[i_P])
            i_P = i;
        if (list_Q[i] > list_Q[i_Q])
            i_Q = i;
        // list_R[i] = max((1 << list_P[i_P]) + (1 << list_Q[i - i_P]), (1 << list_Q[i_Q]) + (1 << list_P[i - i_Q]));
        ll p1 = list_P[i_P], p2 = list_Q[i - i_P];
        if (p1 < p2) swap(p1, p2);
        ll q1 = list_Q[i_Q], q2 = list_P[i - i_Q];
        if (q1 < q2) swap(q1, q2);
        if ((p1 > q1) || (p1 == q1 && p2 > q2))
            list_R[i] = (power2[p1] + power2[p2]) % MOD;
        else
            list_R[i] = (power2[q1] + power2[q2]) % MOD;

    }
    for (ll &r : list_R)
        cout << r << " ";
    cout << endl;
}

int main(){
    power2[0] = 1;
    for (ll i = 1; i < 1e5 + 1; i++){
        power2[i] = power2[i - 1] * 2;
        power2[i] %= MOD;
    }

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while (T--)
        solve();
}