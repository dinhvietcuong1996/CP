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
    vector<bool> list_squares(N, false);
    ll cnt = 0;
    for (ll i = 0; i < Q; i++){
        ll a;
        cin >> a;
        a--;
        if (!list_squares[a]){
            list_squares[a] = true;
            if (a > 0 && list_squares[a-1] && a < N - 1 && list_squares[a +1])
                cnt--;
            else if (((a > 0 && !list_squares[a-1]) || (a == 0)) && ((a < N - 1 && !list_squares[a + 1]) || a == N - 1))
                cnt++;
        } else {
            list_squares[a] = false;
            if (a > 0 && list_squares[a-1] && a < N - 1 && list_squares[a+1])
                cnt++;
            else if (((a > 0 && !list_squares[a-1]) || (a == 0)) && ((a < N - 1 && !list_squares[a + 1]) || a == N - 1))
                cnt--;
        }
        cout << cnt << endl;
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