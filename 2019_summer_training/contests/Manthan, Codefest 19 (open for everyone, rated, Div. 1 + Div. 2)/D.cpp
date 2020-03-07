
//
// Created by ahmed_drawy on 03/09/19.
/// Manthan, Codefest 19 (open for everyone, rated, Div. 1 + Div. 2)
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
int n ;
bool visited[200005];
bool used[200005];
ll arr[200005];
ll sums[200005];
vi getSum(ll sum  , int scnt ){
    int  it = 0 ;
    vector<int > mvec;
    while(true) {
        mvec.clear();

        int tmp = sum;
        lp(i, 0 + it, n) {
            if (arr[i] <= tmp && !visited[i] ) {

                tmp -= arr[i];
                used[i] = 1;
                mvec.push_back(i);

            }
        }
        if(mvec.size() == scnt){
            for (int i = 0; i <sz(mvec) ; ++i) {
                visited[mvec[i]] = 1;
            }
            break;
        }
        else {
            it++;

        }
    }
    return mvec;

}
int main() {
    smile();
    cin >> n ;
    lp(i,0,n)arr[i] = n - i ; /// sorted descending
    inN(sums , n )
    int lst = 0 ;
    vector<int > ans (n, 0 );
    vector< pair <vector <int> , pii>  > ranges; ;
    for (int j = 1; j <n ; ++j) {
        if(sums[j] != sums[j-1]){

            auto indx = getSum(sums[j] - sums[j-1] , j- lst  );
            ranges.push_back({indx , {lst ,j}});
//            for (int i = lst, k = 0 ; i <j  ; ++i) {
//                ans[i] = arr[indx[k]];
//                visited[indx[k++]] = 1;
//            }
            lst= j ;

        }


    }
    for (auto it : ranges) {
        auto v = it.first;
        auto l = it.second.first;
        auto r = it.second.second;
        int k = 0 ;
        lp(i,l,r){
            ans[i] =   arr[v[k++]];
        }
    }
    vector<int > res;
    lp(i,0,n){
        if(!visited[i])
            res.push_back(arr[i]);
    }
    int j =0;
    lp(i,0,n){
        if(!ans[i]){
            ans[i] =res[j++];
        }
    }
    lp(i,0,n)cout<<ans[i]<<" ";

}