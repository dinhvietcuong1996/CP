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
    ll N;
    cin >> N;
    vector<ll> list_A(N);
    for (ll i = 0; i < N; i++) cin >> list_A[i];

    ll left = 0, right = 0;
    ll min_cost = INF;
    while (left < N){
        right = left;
        while(right < N && list_A[left] == list_A[right])
            right++;

        ll cur_cost  = list_A[left] * (left + N - right);
        min_cost = min(min_cost, cur_cost);
        left = right;
    }
    cout << min_cost << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while (T--)
        solve();
}