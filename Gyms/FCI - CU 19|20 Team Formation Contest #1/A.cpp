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
    int n ; cin >> n ;
    cin.ignore();
    lp(i,0,n ){
        string s ;
//        cin >> s;
        getline(cin  ,s);
        ll sum = 0 ;
        vector <int > mvec;
        string t ;
        for (int j = 0; j <sz(s) ; ++j) {
            t += to_string((int )(s[j]) );
            if(j&1) {
                sum -= s[j];
//
            }
            else sum +=s[j];
        }
//        lp(j,0,sz(t)){
//                        if(j&1) {
//                sum -= s[j];
//
//            }
//            else sum +=s[j];
//        }
        cout << sum*sum  << '\n';

    }

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
bool isPerfectSquare(ll x)
{
    ll s = sqrt(x);
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
ll factorize(ll n ){
    vector<ll> mvec;
    for (ll i = 1; i*i <=n  ; ++i) {
        if(n%i ==0 && isPerfectSquare(i) ){
            mvec.push_back(i);
        }
    }
    ll mx = 0 ;
    for(auto it : mvec){
        mx = max(it , mx );
    }
    return mx;

}
int main() {
    smile();
    int n ; cin >> n ;
    while(n--) {
        ll a, b;
        cin >> a >> b;
        cout << (a * b) / (__gcd(a ,b)*__gcd(a,b))<<'\n';
    }
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


int main() {
    smile();
    int t; cin >> t;
    while(t--){
        ll k; cin >> k ;
        ll a = 1 , b =2 , c=1 - k;
        double r1 = (-b*1.0+sqrt(b*b - 4*a*c))/(2.0*a);
        double r2 = (-b*1.0-sqrt(b*b - 4*a*c))/(2.0*a);
        ll rc1 = ceil(r1);
        ll rc2 = ceil(r2);
        if(rc1 >= 0 && rc2 >= 0 ){
            cout << min(r1,  r2);
        }
        else if(rc1>=0){
            cout<<rc1;
        }
        else cout << rc2;
        cout << "\n";
    }

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
vector<int > vec[301];
bool visited [301];


void dfs(int node , int dest){
    for(auto i: vec[node]){
        int child = i;

        if (!visited[i]){
            visited[child] = true;
            dfs(i,dest);

        }

        if(child == dest)
            visited[dest] =1;
    }

}

int main() {
    smile();
    int n , m , q;
    while(cin >> n >>  m >>q){
//        vector<int> g[n];
        clr(vec , 0);
        lp(i,0,m){
            int a , b; cin >> a >> b;
            a--, b--;
            vec[a].push_back(b);
        }
        clr(visited, 0);
        lp(i,0,q){
            int x , y; cin >>x >>y;
            x--,y--;
//            cout<<dfs(0 ,2)<<endl;
            dfs(x,y);
            if(visited[y] ){
                cout<<"YES\n";
            }
            else cout<<"NO\n";
            clr(visited, 0);
        }
    }

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
vector<int > vec[301];
bool visited [301];

const int N = 100005;

int par[N] , rnk[N] ;
void init(int n ){
    lp(i,0,n){
        par[i]= i;
        rnk[i] = 1;
    }
}
int findPar(int x){
    if(par[x] ==x){
        return x;
    }
    par[x] = findPar(par[x]);
    return par[x];
}
void merge(int x , int y ){
    x = findPar(x);
    y = findPar(y);
    if (x != y) {
        if (rnk[x] < rnk[y])
            swap(x, y);
        par[y] = x;
        if (rnk[x] == rnk[y])
            rnk[x]++;
    }
}

int main() {
    smile();
    int t ;cin >>t;
    while (t--){
        clr(par , 0);
        clr(rnk , 0);
        int  n , m ; cin >> n >>m ;
        init(n);
        bool no = 0;
        lp(i,0,m){
            int x , y ;cin >> x >> y;
            if(findPar(x-1) == findPar(y-1)){
                no = 1;
            }
            merge(x-1 , y-1);

        }
        if(no || n-1!=m) cout<<"No\n";
        else {
            int par = 1 ;
            lp(i,1, n ) {
                if(findPar(i) == findPar(0))par++;
            }
            if(par == n)
                cout<<"Yes\n";
        }

//        bool no = 0;
//        lp(i,1,n){
//            if(findPar(i)!=findPar(i-1)){
//                no =1;
//                break;
//            }
//        }
//        if(no) cout<<"No\n";
//        else cout<<"Yes\n";
    }

}