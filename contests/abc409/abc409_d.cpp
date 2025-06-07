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
    string S;
    cin >> S;
    string ans = S;
    ll start = -1, end = N - 1;
    for (ll i = 0; i < S.size() - 1; i++){
        if (start == -1){
            if (S[i + 1] < S[i]){
                start = i;
                break;
            }
        }
    }
    if (start == -1){
        cout << S << endl;
        return;
    }
    for (ll i = start + 1; i < S.size(); i++){
        if (S[i] > S[start]){
            end = i - 1;
            break;
        }
    }
    // cout << start << " " << end << endl;
    for (ll i = start; i < end; i++){
        ans[i] = S[i + 1];
    }
    ans[end] = S[start];
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