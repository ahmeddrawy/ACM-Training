// Created by ahmed_drawy on 07/09/19.
/// Codeforces Round #580 (Div. 2)
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
char arr[1001][1001];
char res [1001][1001];
int n ;
void rotateleft(){
    for (int i =0; i <n; ++i) {

        for (int j = 0; j < n; ++j) {
            res[i][j] = arr[j][i];
//            swap(arr[i][j] , arr[j][i]);
        }

    }
    for (int k = 0;  k < n; ++k) {
        for (int i = 0;2* i < n; ++i) {
            swap(res[i][k], res[n-i-1][k]);
        }
    }
    lp(k,0,n)
        lp(j,0,n)arr[k][j] =res[k][j];
}
int main() {
    smile();
    cin >> n ;
    string s ; cin >> s;
    lp(i,0,n)cin>>arr[i];
    int l = 0,r=0 ;
    lp(i,0,sz(s)){
        if(s[i] =='L')l++;
        else r++;
    }
    l+=3*r;
    l%=4;
    lp(i,0,l)
        rotateleft();
    lp(i,0,n)cout<<arr[i]<<endl;

}
--
// Created by ahmed_drawy on 07/09/19.
/// Codeforces Round #580 (Div. 2)
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
vector<int  > v[7];
int main() {
    smile();
    char arr[7];
    clr(arr, 0);
    string s;
    lp(i,0,5){
        cin >> s;
        if(s[1] == '<'){
            swap(s[0] ,s[2]);
        }
        int fst = -1 , scnd= -1 ;
        for (int j = 0; j < 5; ++j) {
            if(arr[j] == s[0])
                fst = j;
            else if(arr[j] == s[2])
                scnd = j;
        }

        if(scnd>=0&& fst == -1){
            char tmp = arr[scnd];
            arr[scnd] = s[0];
            for (int j = scnd+1; j <5 ; ++j) {
                swap(arr[j], tmp);

            }
        }
        else if(scnd>=0 &&fst >=0){
            if(fst < scnd){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
        else if(fst>=0){
            char tmp = arr[fst+1];
            arr[fst+1] = s[2];
            for (int j = fst+2; j <5 ; ++j) {
                swap(tmp , arr[j]);

            }
//           arr[fst+1] = s[2];

        }



    }
    lp(i,0,5)cout<<arr[i];
}


// Created by ahmed_drawy on 07/09/19.
/// Codeforces Round #580 (Div. 2)
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
set<int>g[7];
int main() {
    smile();
    char arr[7];
    clr(arr, 0);
    string s;
    lp(i,0,5){
        cin >> s;
        if(s[1] == '<'){
            swap(s[0] ,s[2]);
        }
        int u = s[0] - 'A' , v = s[2]- 'A';
        if(g[u].find(v))
            g[u].insert(v);

    }



}
lp(i,0,5)cout<<arr[i];
}
---
// Created by ahmed_drawy on 07/09/19.
/// Codeforces Round #580 (Div. 2)
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
//set<int> v[7];
//int visited[7];
#define cint(c) (int)c -'A';
#define itc(c) (char)c +'A';
int main() {
    smile();
    string s;
    int lst = 0;
    vector<char > v = {'A' , 'B','C','D','E'};
    do{

    }while (next_permutation(v.begin() , v.end()))
    lp(i,0,5){
        cin >> s;
        if(s[1] == '<'){
            swap(s[0] ,s[2]);
        }
        int fst = -1 , scnd= -1 ;
        int f =cint(s[0]);
        int sc = cint(s[2]);
        if(lst == 0 ){
            v[f].insert(s[2]);
            lst++;
        }

        else {
            for (int j = 0; j <sz(v[sc]) ; ++j) {
                if(v[sc][j] == s[0]){
                    cout <<"impossible"<<endl;
                    return 0;
                }
            }
            v[f].insert(s[2]);


        }



    }
    vector <pii> mmap (6, {0,0});
    int cnt =0 ;
    lp(i,0,5){
        mmap[i].first = sz(v[i]);
        for(auto it : v[i]){
            for (auto scd : v[it - 'A']){
                if(scd == i+'A'){
                    cout <<"impossible"<<endl;
                    return 0;
                }
            }
            mmap[i].first += sz(v[it-'A']);
            mmap[i].second = i;
        }
    }

    sort(mmap.rbegin() , mmap.rend());
    string ans  ;
    lp(i,0,5){
        if(mmap[i].first == 5- i ){
            ans += mmap[i].second +'A';
        }
        else {
            cout << "impossible";
            return 0 ;
        }
    }
    cout << ans;





}