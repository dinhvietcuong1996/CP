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
    ll X;
    cin >> X;
    vector<ll> list_A(3, 0);
    ll cnt = 0;
    while (list_A[0] < X || list_A[1] < X || list_A[2] < X) {
        ll m = min(list_A[1], list_A[2]);
        if (list_A[0] != X){
            if (m == 0) list_A[0] = 1;
            else list_A[0] = min(2 * m + 1, X);
            cnt++;
        }
        m = min(list_A[0], list_A[2]);
        if (list_A[1] != X){
            if (m == 0) list_A[1] = 1;
            else list_A[1] = min(2 * m + 1, X);
            cnt++;
        }
        m = min(list_A[0], list_A[1]);
        if (list_A[2] != X){
            if (m == 0) list_A[2] = 1;
            else list_A[2] = min(2 * m + 1, X);
            cnt++;
        }
        // cout << "list_A: ";
        // for (auto &a : list_A) {
        //     cout << a << " ";
        // }
        // cout << endl;
        // break;
    }
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