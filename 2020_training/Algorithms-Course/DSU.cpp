/// by ahmed_drawy 20/12/19
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
using namespace std;
#define ll long long
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v));
#define pii pair<int, int>
#define vii vector<ll>
#define vi vector<int>
#define   endl '\n'
#define debug(x) cerr << x<<endl;
const double EPS = (1e-7);
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}
int randomF() {
    return  (rand() * RAND_MAX + rand()) % 1000000;

}

ll MOD =(ll) 1e9 +7 ;
int mod(ll x){
    return (x%MOD + MOD)%MOD;
}
long long add(long long x, long long y)
{
    x += y;
    while(x >= MOD)
        x -= MOD;
    while(x < 0)
        x += MOD;
    return x;
}
ll multipy(ll x , ll y ){
    return ((x%MOD) *(y%MOD))%MOD;
}
long long power(long long base, int exp)
{
    if (!exp)
        return 1LL;
    ll sq = power(base, exp/2);
    sq = (sq * sq)%MOD;
    if (exp&1)
        sq = (sq * base)%MOD;
    return sq;
}
bool compareT(pair<int , int > & a , pair<int  ,int > &b){
    if(a.first != b.first)
        return a.first <b.first ;
    return a.second< b.second ;
}
double dist(int x , int y , int a , int b){
    return sqrt( (x-a)*(x-a) + (y-b)*(y-b));

}
int n , m ;
const int N = 30005;
int arr[N];
int par[N];
int rnk[N];
int cnt[N];
int findParent(int x ){
    if(par[x] == x){
        return x;
    }
    return par[x] = findParent(par[x]);
}
void makeset(){
    for (int i = 0; i <n ; ++i) {
        par[i] = i ;
        rnk[i] = 0 ;
        cnt[i] = 1 ;
    }
}


bool merge(int x , int y) {
    x = findParent(x);
    y = findParent(y);
    if(x!= y){
        if(rnk[x]<rnk[y]){
            par[x] = par[y];
            cnt[y]+=cnt[x];
        }
        else {
            par[y] = par[x];
            cnt[x]+=cnt[y];
            if(rnk[x] == rnk[y])
                rnk[x]++;
        }
        return true ;
    }
    return false ;
}


int main(){
    smile();
    int Case = 0 ;
    int t ; cin >>t;
    while(t--) {
        cin >> n  >> m;
        makeset();
        for (int i = 0; i < m; ++i) {
            int x, y; cin >> x>>y ;
            x--,y--;
            merge(x, y);
        }
        int mx= 0;
        for(int i = 1 ; i <= n ;++i){
            mx =max(mx , cnt[i-1]);

        }
        cout << mx << endl;

    }
}