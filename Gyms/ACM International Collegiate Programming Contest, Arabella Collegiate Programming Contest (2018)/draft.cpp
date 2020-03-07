// Created by ahmed_drawy on 11/09/19.
///dp educational contest atcoder
#include <bits/stdc++.h>
#include <string.h>
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
//#define dbg (v)    for(auto it : v)cout<<it<<' ';
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
#define endl '\n'
#define cint(c) (int)c -'0';
#define itc(c) (char)c +'A';
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
#endif
}
#define fastin smile()


int main() {
    fastin;
    int t; cin >> t;
    while(t--) {
        int n , m , k ; cin >> n >> m >> k;
        string a , b ; cin >>a >> b;
        map <char , vector<int>  >mmap;
        map <char , vector<int>  >amap;
        lp(i,0,sz(b)){
            mmap[b[i]].push_back(i);
        }
        lp(i,0,sz(a)){
            amap[a[i]].push_back(i);
        }
        int window = k-1 ;
        int ans = 0 ;
        for (int i = 0; i+window <n ; ++i) {

            if(mmap[a[i]].size() && mmap[a[i+window]].size()){
                auto v2 = mmap[a[i+window]];
                for(auto it : mmap[a[i]]){
                    auto  u = lower_bound(v2.begin() , v2.end() , it)  - v2.begin();
                    ans += (v2.size() - u );
                }
                continue;
                int f= -1  ,f2 = -1 ;
                int pos1 = -1;
                int pos2 = -1;
                do {
                    f = b.find(a[i] ,pos1+1 );
                    f2 = b.find(a[i + window], pos2+1)  ;
                    if(f2 > f){
                        ans +=1;
                        pos2 =f2;
                    }
                    else if ( f2 == string::npos && f != string ::npos){
                        pos2 = f;
                        pos1 = f;
                    }
                }
                while(f!= string :: npos    || f2!=string ::npos    );

            }
        }
        cout << ans << endl;
    }
}

---

---

---


--
// Created by ahmed_drawy on 11/09/19.
///dp educational contest atcoder
#include <bits/stdc++.h>
#include <string.h>
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
//#define dbg (v)    for(auto it : v)cout<<it<<' ';
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
#define endl '\n'
#define cint(c) (int)c -'0';
#define itc(c) (char)c +'A';
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
#endif
}
#define fastin smile()

int main() {
    fastin;
    int t;  cin >> t;
    while(t-- ){
        int n, m  ; cin >> n >> m;
        vector<pair<int , pair<int , int > > > vec;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <m ; ++j) {
                int x ;
                cin >> x ;
                vec.push_back({x , {i,j}});
            }
        }
        sort(vec.rbegin() , vec.rend());
        int msz = sz(vec);
        int mn = INT_MAX;
        for (int k = 0; k+ 3 <msz ; ++k) {
            bool no = 0 ;
            for (int i = 0; i <4 ; ++i) {
                for (int j = i+1; j <4 ; ++j) {
                    if(abs(vec[k+i].second.second - vec[k+j].second.second) <=1 && abs(vec[k+i].second.first - vec[k+j].second.first)<=1){
                        no =1;
                        break;
                    }
                }
            }
            if(!no){
                mn = min(mn  , abs(vec[k].first - vec[k+3].first) );
            }
        }
        cout<<mn << endl;

    }

}
----
// Created by ahmed_drawy on 11/09/19.
///dp educational contest atcoder
#include <bits/stdc++.h>
#include <string.h>
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
//#define dbg (v)    for(auto it : v)cout<<it<<' ';
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
#define endl '\n'
#define cint(c) (int)c -'0';
#define itc(c) (char)c +'A';
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
#endif
}
#define fastin smile()


int main() {
    fastin;
    int t; cin >> t;
    while(t--) {
        int n , m , k ; cin >> n >> m >> k;
        string a , b ; cin >>a >> b;
        map <char , vector<int>  >mmap;

        lp(i,0,sz(b)){
            mmap[b[i]].push_back(i);
        }
        int window = k-1 ;
        int ans = 0 ;
        map<pii , bool> mset;
        set<pair<char  , char > > queries;
        for (int i = 0; i+window <n ; ++i) {
            queries.insert({a[i] , a[i+window]});
        }
        for (auto it : queries){
            auto start = it.first , end = it.second ;
            for(auto scnd  : mmap[start]){
                ans += count(b.begin() + scnd , b.end() , end);
            }

        }
        cout << ans << endl;
    }
}