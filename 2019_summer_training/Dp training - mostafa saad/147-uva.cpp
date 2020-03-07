/// 147 -uva - by ahmed_drawy 28/09/19
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v));
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'
#define debug(x) cerr << x<<endl;
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
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
/// max 632 level
const int N = 3e4 + 3;
ll dp[N][11];
int visited[N][11] ;
int id = 0 ;
int coins [6] = {50, 25, 10,5 , 1 };
int cnt = 0 ;
ll solve(int rem , int indx){
    if(rem == 0 )
        return 1ll ;
    ll &ret= dp[rem][indx];
    if(visited[rem][indx] == id)
        return ret;
    visited[rem][indx] = id;
    ret= 0 ;
    int sum =  0;
    for (int i = indx; i <5 ; ++i) {
        int coin = coins[i];
        if(rem >= coin)
            ret +=solve(rem - coin ,i);
//        else
//        ret +=solve(rem , i +1);
    }
    return ret;
}
int main() {
    smile();

//    solve(30000,0);
//    table();
    int rem ;
    while(cin >>rem) {


//        debug(rem)
//            clr(dp, -1)
        id++;
        ll ret = solve(rem,0);
        if(ret > 1)
            cout << "There are "<<ret <<" ways to produce ";
        else cout<<"There is only 1 way to produce "    ;
        cout <<rem<<" cents change." <<endl;
        //debug(cnt)
    }
}
