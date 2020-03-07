//
// Created by ahmed_drawy on 29/08/19.
/// team formation 19/20
#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define inf 0x3f3f3f3f
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s*s == x);
}
bool isFibonacci(int x)
{
    return isPerfectSquare(5*x*x + 4) ||
           isPerfectSquare(5*x*x - 4);
}
int n ;
const int N = 200005;
int segTree [4*N +1] , arr[N];
int left(int pos ){
    return 2*pos;
}
int right(int pos){
    return  2*pos +1;
}
void change(int pos  ){
    segTree[pos] = segTree[left(pos)]  + segTree[right(pos)];
}
void build (int  l= 0 , int r = n -1 , int pos = 1 ){

    if(l == r ){
        segTree[pos] = isFibonacci( arr[l]);
        return;
    }
    int mid = (l + r ) / 2;
    build(l  , mid , 2*pos  );
    build(mid +1  , r , 2*pos +1);
    change(pos);

}
int Query (int x , int y , int l = 0 , int r =  n -1 , int pos = 1){
    if(x>r || l > y){
        return 0;
    }
    if(x <= l && y>= r){
        return segTree[pos];
    }
    int mid = (l+r)/2;
    return  Query(x, y, l ,mid , left(pos)) + Query(x ,y, mid +1 , r , right(pos));

}
void update(int p , int v , int l = 0 , int r =  n -1 , int pos=1){

    if(l == r ){
        segTree[pos] = v;
        return;
    }
    int mid = (l +r ) /2;
    if(p <= mid){
        update(p , v , l , mid  ,left(pos));
        change(pos);
    }
    else{
        update(p , v , mid+1 , r , right(pos));
        change(pos );
    }
}

int main() {
    smile();

}

---
//
// Created by ahmed_drawy on 29/08/19.
/// team formation 19/20
#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define inf 0x3f3f3f3f
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const int N = 1e6 + 5;
int factor[N];
int sieve() {
    for (int i = 2; i * i < N; ++i) {
        for (int i = 2; i * i < N; ++i) {
            if (factor[i])
                continue;
            for (int j = i * i; j < N; j += i)
                factor[j] = i;
        }
    }
}
vector<  map<int , int> > dp(N) ;
map<int , int> factorize(int x) {
    map<int,int> factors;
    int prev = -1;
    while (x > 1) {
        if (factor[x] == 0)
            factor[x] = x;
        factors[ factor[x]]++;
        x /= factor[x];
    }
    return  factors;
}
void build (){
    lp(i ,2, N)
        dp[i] = factorize(i);
}

int main() {
    smile();
    sieve();
//    build();
    int t; cin>>t;
    while   (t--){
        int n ; cin >> n ;
        vector<int > mvec(n);
        map<int , int> mxFrq;
        lp(i,0,n){
            int x ; cin >> x;
            mvec[i]= x;

        }
        lp(i,0,n){
            if(mvec[i] ==1)
                continue;
            map <int  ,int  > it = factorize(mvec[i]);
            for (pair<int , int > num : it){
                mxFrq[num.first] = max(mxFrq[num.first] , num.second);
            }
        }
        ll ans = 0 ;
        for (pair<int ,int > it : mxFrq)
            ans +=it.second;
        cout <<ans<<'\n';
    }

}
--- i
//
// Created by ahmed_drawy on 29/08/19.
/// team formation 19/20
#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define inf 0x3f3f3f3f
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const int N = 100005;
int dp [N][3];
int solve(int indx , int state){
    if(indx == n ){
        return 0 ;
    }
}
int main() {
    smile();
    int t; cin>>t;
    while   (t--){
        int  n ; cin >> n ;
        vector<ll > height(n);
        vector<ll > radius(n);
        lp(i,0,n){
            cin>>height[i] >>radius[i];
        }
        int j = 0 ;
        int prev = 0 ;
        ll ans = height[0];
        lp(i,1,n){
            if(radius[i]>=radius[j]){
                prev = ans;
                ans+=height[i];
//               prev = j ;
                j= i;

            }
            else if(height[i] +prev>ans){

                ans=height[i] + prev ;
                /// prev dont change
                j = i ;

            }
            else if(height[i] + prev == ans ){
                if(radius[i] < radius[j]){
                    ans=height[i] + prev ;
                    /// prev dont change
                    j = i ;
                }
            }

        }
        cout<<ans;
    }

}
----
 contest2
 //
// Created by ahmed_drawy on 29/08/19.
/// team formation 19/20
#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define inf 0x3f3f3f3f
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}


ll modul = 26;
ll mod(ll x) {
    return (x%modul + modul)%modul;
}

ll dist(int c , int d ,map<int ,ll> &leftm,map<int ,ll> &rightm){
//    if(d<c)swap(d,c);
    int temp = mod(c+1);
    ll ans = rightm[c];
    while(mod(temp) !=d){
        ans+=rightm[mod(temp)];
        temp++;
//        mod(temp);
    }
    temp = mod(c-1);
    ll ans2 = leftm[c]; /// moving from d to c
    while(mod(temp) !=d){
        ans2+=leftm[mod(temp)];
        temp--;
//        mod(temp);
    }
    return min(ans , ans2);


}
ll arr[26][26];
void build (map<int ,ll> &leftm,map<int ,ll> &rightm){
    lp(i,0,26){
        lp(j,0,26){
            if(i==j)
                continue;
            arr[i][j] = dist(i , j,leftm , rightm);
        }
    }
}
int main() {
    smile();
    int t; cin >> t;

    while(t--) {
        int n, k  ;
        cin >> n>> k;
        vector<char> mvec(n);
        lp(i,0,n){
            string s ; cin >> s;
            mvec[i] = s[0];
        }
        map<int ,ll> leftm;
        map<int ,ll> rightm;
        lp(i,0,26){
            ll x, y;
            cin>>x >> y;
            leftm[i] = x;
            rightm[i] = y;
        }
        build(leftm , rightm);
        ll mx = 0;
        vector<ll> diff(n);
        lp(i,0,26){ /// 26 start
            lp(j,0,n){
                diff[j] =  arr[mvec[j]-'a'][i];  /// starting from current to i char
            }
            sort(diff.begin() , diff.end());
            lp(zz , 1, n)
                diff[zz] +=diff[zz-1];
            ll lw = upper_bound(diff.begin() , diff.end() , k) - diff.begin() ;
            mx = max(mx , lw);
        }
        cout<<mx << '\n';
    }



}

--


//
//int  check (int indx){
//    int left = l[indx] , rig = r[indx];
//    if(rig == n){
//        return 1;
//    }
//    if(l[rig+1]){
//        return 1 + check(l[rig+1]);
//    }else return -1;
//}
---
//
// Created by ahmed_drawy on 29/08/19.
/// team formation 19/20
#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define inf 0x3f3f3f3f
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
#define endl '\n'
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
int n,q ;

const int N = (1<<7 )+1;
int r ;
int dp[N][N][N];


ll fact(int  n ){
    if(n == 1) return 1;
    return n*fact(n-1);
}

int main() {
    smile();
    int t ; cin >> t;
    while(t--) {
        cin >> n >> r;
        clr(dp , 0);
        int cnt = 0 ;
        for (int msk1 = 1; msk1 <=(1<<n)-1 ; ++msk1) {
            for (int msk2 = 1; msk2 <=(1<<n)-1 ; ++msk2) {
                for (int i = 0; i <min(r, n ) ; ++i) {
                    if(i!= r-1) {
                        if ((msk1 & (1 << i)) ==( msk2 & (1 << i))) {
                            dp[msk1][msk2] = 0;
                            dp[msk1][msk2] +=dp[msk1][msk2-1];
                        }
                    }else {
                        dp[msk1][msk2] = (msk1 & (1 << i)) ==( msk2 & (1 << i));
                        dp[msk1][msk2] +=dp[msk1][msk2-1];
                    }
                }
            }
            cnt+=dp[msk1][(1<<n)-1];
        }
        ll f= fact(n);
        cout <<(cnt*1.0)/f*f<<endl;
    }


}