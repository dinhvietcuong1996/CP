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

vector<ll> inv_mod(7);

void solve(){
    ll N;
    cin >> N;
    vector<pair<ll,ll>> list_values(6 * N);
    for (ll i = 0; i < N; i++){
        for (ll j = 0; j < 6; j++){
            cin >> list_values[i*6+j].first;
            list_values[i*6+j].second = i;
        }
    }
    sort(list_values.begin(), list_values.end());
    vector<ll> checked(N, 0);
    ll cnt_checked = 0;
    ll last_value = -1;
    ll acc_prob = 1;
    ll last_prob = 0;
    ll expected_value = 0;
    bool is_first_time = false;
    for (ll i = 0; i < 6 * N; i++){
        ll value = list_values[i].first;
        ll idx = list_values[i].second;
        if (checked[idx] == 0){
            checked[idx] = 1;
            cnt_checked++;
            if (cnt_checked == N){
                for (ll j = 0; j < N; j++){
                    acc_prob *= checked[j];
                    acc_prob %= MOD;
                    acc_prob *= inv_mod[6];
                    acc_prob %= MOD;
                }
                // cout << "acc_prob " << acc_prob << endl;
                is_first_time = true;
            }
        } else checked[idx]++;
        if (cnt_checked < N) continue;
        if (!is_first_time){
            // cout << "check[idx]: " << checked[idx] << endl;
            acc_prob *= checked[idx];
            acc_prob %= MOD;
            acc_prob *= inv_mod[checked[idx] - 1];
            acc_prob %= MOD;
        }
        is_first_time = false;
        if (i + 1 < 6 * N && value == list_values[i+1].first) continue;
        // cout << "value: " << value << ", acc_prob: " << acc_prob << " last_prob: " << last_prob << endl;
        ll cur_prob = (acc_prob - last_prob + MOD) % MOD;
        expected_value += (value * cur_prob) % MOD;
        expected_value %= MOD;
        last_prob = acc_prob;
    }
    cout << expected_value << endl;
}

int main(){
    
    inv_mod[0] = 0;
    inv_mod[1] = 1;
    for (ll i = 2; i < 7; i++)
        inv_mod[i] = (MOD - MOD / i) * inv_mod[MOD % i] % MOD;
    
    // cout << "inv_mod: ";
    // for (ll i = 1; i < 7; i++)
    //     cout << (inv_mod[i] * i) % MOD << " ";
    // cout << endl;
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
//    cin >> T;
    while (T--)
        solve();
}