
//
// Created by ahmed_drawy on 06/08/19.
// 12086-uva - segment tree training
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
//typedef first                    ft;
//typedef second                   sd;
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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE

    freopen("/home/tw3/Desktop/training/in.txt", "r", stdin);
    freopen("/home/tw3/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const long long modul = 1000000007;

ll mod(ll x) {
    return (x%modul + modul)%modul;
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
        segTree[pos] = arr[l];
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
    int cnt = 0 ;
    while (cin >> n && n && ++cnt) {
        if(cnt >1)
            cout<<"\n";
        cout  <<"Case "<<cnt<< ":\n" ;
        inN(arr, n);
        build();
        string query ;
        while(cin >> query && query!="END"){
            int x, v;

            cin >> x >> v;
            if(query== "S")
                update(x - 1, v);
            else
                cout << Query(x-1 ,v-1) << "\n";
        }

    }

}