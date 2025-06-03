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

vector<ll> fibonacci(11);

void solve(){
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> list_boxes(M, vector<ll>(3));
    for (ll i = 0; i < M; i++)
        cin >> list_boxes[i][0] >> list_boxes[i][1] >> list_boxes[i][2];

    string ans(M, '0');
    for (ll i = 0; i < M; i++){
        vector<ll> &box = list_boxes[i];
        ll W = box[0], L = box[1], H = box[2];
        ll maxx = max(W, max(L, H));
        ll minn = min(W, min(L, H));
        if (maxx >= fibonacci[N] + fibonacci[N-1] && minn >= fibonacci[N])
            ans[i] = '1';
    }
    cout << ans << endl;
}

int main(){
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    fibonacci[2] = 2;
    for (ll i = 3; i < 11; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while (T--)
        solve();
}