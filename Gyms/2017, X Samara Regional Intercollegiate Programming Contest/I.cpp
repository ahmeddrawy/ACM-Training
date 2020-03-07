///samara 2017
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
const int N = 1001;
ll a[N][N];
ll b[N][N];
ll c[N][N];
ll rnd[N][1];
ll lhs[N][1];
ll brand[N][1];
ll rhs[N][1];
int randomF() {
    return  (rand() * RAND_MAX + rand()) % 1000000;

}
int MOD = 1e9 +7;
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
int main(){
    smile();
    int n ; cin >> n ;
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >>a[i][j];
        }
    }
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >>b[i][j];
        }
    }
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >>c[i][j];
        }
    }
    bool yes = 1 ;
    for (int t = 0; t <15 && yes ; ++t) {
        for (int i = 0; i < n; ++i) {
            rnd[i][0] = rand()%2;
        }
        memset(lhs , 0 , sizeof lhs);
        memset(rhs , 0 , sizeof rhs);
        memset(brand , 0 , sizeof brand);
//        memset(lhs , 0 , sizeof lhs);
        for (int i = 0; i < n; ++i) {  /// b*rand
//            for (int j = 0; j < 1; ++j) {
            int j =0 ;
            for (int k = 0; k <n ; ++k)
                brand[i][j] = add(brand[i][j],  multipy(b[i][k] , rnd[k][j]));
//            }
        }
        for (int i = 0; i < n; ++i) {  /// a*(b*rand)
//            for (int j = 0; j < 1; ++j) {
            int j =0 ;
            for (int k = 0; k <n ; ++k)
                lhs[i][j]=  add( lhs[i][j] , multipy(a[i][k] , brand[k][j]));
//            }
        }
        for (int i = 0; i < n; ++i) {  /// c*rand
//            for (int j = 0; j < 1; ++j) {
            int j =0 ;
            for (int k = 0; k <n ; ++k)
                rhs[i][j] += c[i][k] * rnd[k][j];
//            }
        }
        for (int i = 0; i <n  &&  yes; ++i) {
//            for (int j = 0; j < 1; ++j) {
            int j =0 ;
            if(mod(lhs[i][j])!= mod(rhs[i][j])){
                yes = false ;
                break;
            }
//            }
        }

    }
    if(yes) cout <<"YES";
    else cout <<"NO";
}