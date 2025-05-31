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

// Binary Search
ll first_true(function<bool(ll)> check, ll low, ll high) {
    while (low < high) {
        ll mid = (low + high) / 2;
        if (check(mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

ll last_true(function<bool(ll)> check, ll low, ll high) {
    while (low < high) {
        ll mid = (low + high + 1) / 2;
        if (check(mid))
            low = mid;
        else
            high = mid - 1;
    }
    return low;
}

// Fast Exponentiation
ll fast_exp(ll base, ll exp, ll mod = MOD) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll fast_exp(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

// Greatest Common Divisor (GCD)
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Least Common Multiple (LCM)
ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return abs(a * b) / gcd(a, b);
}

// Sieve of Eratosthenes
// Generates primes up to n
vector<ll> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll p = 2; p * p <= n; p++)
        if (is_prime[p])
            for (ll i = p * p; i <= n; i += p)
                is_prime[i] = false;
    vector<ll> primes;
    for (ll p = 2; p <= n; p++)
        if (is_prime[p])
            primes.push_back(p);
    return primes;
}

// Primality Test (trial division)
bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

// Prime Factorization (using trial division)
map<ll, ll> prime_factorization(ll n) {
    map<ll, ll> factors;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1)
        factors[n]++;
    return factors;
}

int main(){
    return 0;
}