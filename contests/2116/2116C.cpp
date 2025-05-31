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

ll gcd(ll a, ll b){
    while (b != 0){
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void solve(){
    ll N;
    cin >> N;
    vector<ll> list_A(N);
    for (ll i = 0; i < N; i++) cin >> list_A[i];

    ll global_gcd = list_A[0];
    for (ll i = 1; i < N; i++) global_gcd = gcd(global_gcd, list_A[i]);

    bool found_2 = false;
    bool found_exact = false;

    ll smallest_gcd_pair = numeric_limits<ll>::max();
    for (ll i = 0; i < N; i++){
        if (list_A[i] == global_gcd){
            smallest_gcd_pair = global_gcd;
            found_exact = true;
            break;
        }
        for (ll j = i + 1; j < N; j++){
            smallest_gcd_pair = min(smallest_gcd_pair, gcd(list_A[i], list_A[j]));
            if (smallest_gcd_pair == global_gcd){
                found_2 = true;
                break;
            }
        }
        if (found_2) break;
    }
    ll cnt = 0;
    while (smallest_gcd_pair > global_gcd){
        ll cur_smallest_gcd = numeric_limits<ll>::max();
        for (ll i = 0; i < N; i++){
            cur_smallest_gcd = min(cur_smallest_gcd, gcd(smallest_gcd_pair, list_A[i]));
        }
        cnt++;
        smallest_gcd_pair = cur_smallest_gcd;
    }

    for (ll i = 0; i < N; i++)
        if (list_A[i] != global_gcd)
            cnt++;
    
    cout << cnt << endl; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while (T--)
        solve();
}