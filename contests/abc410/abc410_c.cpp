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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> list_A(N);
    for (ll i = 0; i < N; i++) list_A[i] = i + 1;
    ll rotated = 0;
    for (ll i = 0; i < Q; i++){
        ll type;
        cin >> type;
        if (type == 1){
            ll p, x;
            cin >> p >> x;
            p--;
            list_A[(p + rotated + N) % N] = x;
        } else if (type == 2){
            ll p;
            cin >> p;
            p--;
            cout << list_A[(p + rotated + N) % N] << endl;
        } else {
            ll k;
            cin >> k;
            k %= N;
            rotated = (rotated + k) % N;
        }
        // cout << "rotated: " << rotated << endl;
        // cout << (1 - rotated + N) % N << endl;
        // cout << "list_A: ";
        // for (ll i = 0; i < N; i++)
        //     cout << list_A[(i - rotated + N) % N] << " ";
        // cout << endl;
        // cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
//    cin >> T;
    while (T--)
        solve();
}