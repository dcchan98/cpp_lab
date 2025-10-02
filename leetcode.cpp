#include <bits/stdc++.h>
using namespace std;
#define LOCAL
// overwrite << operator
// 1. Pair
template<typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

// 2. Generic container (works for vector, set, map, unordered_map, etc.)
template<typename T_container,
         typename T = typename T_container::value_type,
         typename = typename enable_if<!is_same<T_container, string>::value>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const auto &x : v) os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << endl; }

template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifdef LOCAL
#define print(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int MIN_INT = -2147483648;
const int MAX_INT = 2147483647;

const vector<pair<int, int> > DIR = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// Check if its in range, and it is unvisited
bool isVisitable(int i, int j, int m, int n, const vector<vector<int> > &visited) {
    return i >= 0 && i < m && j >= 0 && j < n && !visited[i][j];
}

// 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
int main() {
    pair<int, int> p = {1, 3};
    vector<vector<pair<int, int> > > vec(5, vector<pair<int, int> >(3, {1, 2}));
    pair<int, vector<int> > p2 = {1, {1}};
    print(p);
    print(vec);
    unordered_map<int, int> um;
    um[5] = 1;
    print(um);
    unordered_map<int,vector<int>> umVec;
    umVec[1] = {1   };
    print(umVec)
}
