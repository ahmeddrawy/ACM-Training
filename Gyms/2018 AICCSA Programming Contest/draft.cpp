#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <inttypes.h>
#include <stdint.h>

#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define show(x) cout << #x << " = " << x << "\n"
#define mem( a , b ) memset( a , b , sizeof a )
#define popcnt(x) __builtin_popcount(x)
#define all(x) x.begin() , x.end()
#define mod(x,m) ((x%m + m )%m)
#define SZ(a) (int)a.size()
#define ll  long long
#define ld  long double
#define vii vector  <ll>
#define dqi deque   <ll>
#define sii set     <ll>
#define vpi vector  <pii>
#define vi  vector  <int>
#define mii map     <ll,ll>
#define pii pair    <ll,ll>
#define pi  pair    <int,int>
#define pb  push_back
#define F   first
#define S   second
#define L   length()
#define OO  (ll)1e18
#define oo  1e9
#define lSOne(x)(x&-x)
#define EPS 1e-15
using namespace std;
using namespace __gnu_pbds;
void ONLINE__JUDGE();

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;

pii swapii( pii pr ){ return { pr.S , pr.F }; }
ll binEXP( ll x , ll pw , ll MOD = LLONG_MAX );
int dx[] = {  0 ,  0 , -1 , +1 , -1 , +1 , -1 , +1 };
int dy[] = { -1 , +1 ,  0 ,  0 , -1 , +1 , +1 , -1 };

const ll MOD = 1e9 + 7;
const ll MAX = 1e5 + 7;


int main(){
    FASTIO ONLINE__JUDGE();

    return 0;
}

a
void ONLINE__JUDGE()
{
#ifndef ONLINE_JUDGE
    freopen( "/home/tw3/Desktop/Desktop/training/in.txt"        , "r" , stdin  );
//    freopen( "/home/tw3/Desktop/Desktop/training/out.txt"   , "w" , stdout );
#endif // ONLINE_JUDGE
}
ll binEXP( ll x , ll pw , ll MOD )
{ ll res=1; while(pw>0){ pw%2 ? res *= x : 0; x *= x; x%=MOD; pw /= 2; res%= MOD; } return res%=MOD; }
---
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define vii vector<ll>
#define  F first
#define  S second
const int N = 1e5 +4 ;
#define   endl '\n'

int id_to_score[N];
map<int, set<int>> scores;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///
    freopen("/home/tw3/Desktop/Desktop/training/in.txt" , "r" , stdin);///
    int T; cin >> T;
    while(T--) {
        int n, q; cin >> n >> q;
        fill(id_to_score, id_to_score + n + 2, 0);
        scores.clear();
        for(int i=0; i<n; ++i)
            scores[0].insert(i);
        int id = -1, time = 0;
        int cnt = 0;
        for(int i=1; i<=q; ++i) {
            int x, p; cin >> x >> p;
            x--;
            auto it = scores[id_to_score[x]].find(x);
            scores[id_to_score[x]].erase(it);
            id_to_score[x] += p;
            scores[id_to_score[x]].insert(x);
            int t = *((scores.rbegin()->S).begin());
            if(t != id) {
                id = t;
                time = i;
                cnt++;
            }
        }
        if(cnt > 1)
            cout << time << endl;
        else
            cout << "0\n";
    }
    return 0;
}