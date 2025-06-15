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
    ll N;
    cin >> N;
    vector<pair<ll, ll>> list_events(N);
    for (ll i = 0; i < N; i++) cin >> list_events[i].first >> list_events[i].second;

    map<ll, vector<ll>> avaiable_potions;
    vector<ll> list_potions_dff(N + 1, 0);
    vector<ll> list_actions(N + 1, 0);
    for (ll i = 0; i < N; i++){
        ll type = list_events[i].first;
        ll potion = list_events[i].second;
        if (type == 1){
            avaiable_potions[potion].push_back(i);
            continue;
        }
        if (avaiable_potions.find(potion) == avaiable_potions.end() || avaiable_potions[potion].empty()){
            cout << -1 << endl;
            return;
        }
        ll idx = avaiable_potions[potion].back();
        list_actions[idx] = 1;
        avaiable_potions[potion].pop_back();
        list_potions_dff[idx] += 1;
        list_potions_dff[i] -= 1;
    }
    ll cur_potions = 0;
    ll ans = 0;
    for (ll i = 0; i < N; i++){
        cur_potions += list_potions_dff[i];
        ans = max(ans, cur_potions);
    }
    cout << ans << endl;
    for (ll i = 0; i < N; i++){
        if (list_events[i].first == 1)
            cout << list_actions[i] << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--)
        solve();
}