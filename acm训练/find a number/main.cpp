//#include <bits/stdc++.h>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#define fr first
#define sc second
#define r_0 return 0
#define ll long long
#define ppb pop_back
#define pb push_back
#define pf push_front
#define ppf pop_front
#define ld long double
#define TIME ios_base::sync_with_stdio(0);
#define foi freopen( "input.txt", "r", stdin );
#define foo freopen( "output.txt", "w", stdout );

using namespace std;

string s, str, ans;
ll n, x, c, cnt, t, m, y, a, b;

vector<ll>g[1000002], va;
bool used[1000002];

void dfs( ll v ){
    used[v] = 1;
    for ( ll i = 0; i < g[v].size(); i ++ ){
        ll to = g[v][i];
        if ( !used[to] ){
            used[to] = 1;
            dfs(to);
        }
    }
}

int main(){

    cin >> n;

    cout << 0 << " " << 0 << " " << n;

    r_0;
}
