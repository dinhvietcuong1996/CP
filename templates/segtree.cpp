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

#include <iostream>
#include <limits>         // numeric_limits<type>::max(), numeric_limits<type>::min()
#include <iomanip>        // setprecision
#include <algorithm>      // sort, max, min, reverse, swap
#include <cmath>          // pow, floor, ceil, round, abs
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <deque>
#include <numeric>      // accumulate
#include <queue>      // queue, priority_queue
#include <functional> // for function
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;

class SegmentTree {
private:
    ll e() { return 0LL;}
    ll op(ll &a, ll &b) {return a + b;}

    void _build(vector<ll> &arr, ll node, ll start, ll end){
        if (start == end) tree[node] = arr[start];
        else {
            ll mid = (start + end) / 2;
            ll left_child = 2 * node + 1, right_child = 2 * node + 2;
            _build(arr, left_child, start, mid);
            _build(arr, right_child, mid + 1, end);
            tree[node] = tree[left_child] + tree[right_child];
        }
    }

    void _update(ll &index, ll &value, ll node, ll start, ll end){
        if (start == end) tree[node] = value;
        else {
            ll mid = (start + end) / 2;
            ll left_child = 2 * node + 1, right_child = 2 * node + 2;
            if (index <= mid)
                _update(index, value, left_child, start, mid);
            else
                _update(index, value, right_child, mid + 1, end);
            tree[node] = tree[left_child] + tree[right_child];
        }
    }

    ll _query(ll &left, ll &right, ll node, ll start, ll end) {
        if (end < left || start > right) return e();
        if (left <= start && end <= right) return tree[node];
        ll mid = (start + end) / 2;
        ll left_child = 2 * node + 1, right_child = 2 * node + 2;
        ll left_query = _query(left, right, left_child, start, mid);
        ll right_query = _query(left, right, right_child, mid + 1, end);
        return op(left_query, right_query);
    }

public:
    vector<ll> tree;
    ll N;

    SegmentTree(ll N){
        this->N = N;
        tree.assign(4 * N, e());
    }

    SegmentTree(vector<ll> &arr) {
        this->N = arr.size();
        tree.assign(4 * N, 0);
        _build(arr, 0, 0, N - 1);
    }

    void update(ll index, ll value) { _update(index, value, 0, 0, N - 1);}
    ll query(ll left, ll right) {return _query(left, right, 0, 0, N - 1);}
};


int main(){
    return 0;
}