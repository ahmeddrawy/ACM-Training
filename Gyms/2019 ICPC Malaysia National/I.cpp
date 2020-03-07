// Created by ahmed_drawy on 07/09/19.
/// 2019 ICPC Malaysia National
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
    string l1, l2 , l3 ;cin >> l1 >> l2>> l3;
    int f1 =l1.find('=');
    int f2 =l2.find('=');
    int f3 =l3.find('=');
    if(f1 != string :: npos){
        for (int i = f1+1; i <sz(l1) ; ++i) {
            if(l1[i] !='.') {
                cout << l1[i];
                return 0;
            }
        }
        cout <<"You shall pass!!!"<<endl;

    }if(f2 != string :: npos){
        for (int i = f2+1; i <sz(l2) ; ++i) {
            if(l2[i] !='.') {
                cout << l2[i];
                return 0;
            }
        }
        cout <<"You shall pass!!!"<<endl;

    }if(f3 != string :: npos){
        for (int i = f3+1; i <sz(l3) ; ++i) {
            if(l3[i] !='.') {
                cout << l3[i];
                return 0;
            }
        }
        cout <<"You shall pass!!!"<<endl;

    }
}