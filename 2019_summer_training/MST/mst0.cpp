
//
// Created by ahmed_drawy on 23/06/19.
//  summer training  - MST -  i dont know yet - UVA

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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE

    freopen("/home/www/Desktop/training/in.txt", "r", stdin);
    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const long long modul = 1000000007;

ll mod(ll x) {
    return (x%modul + modul)%modul;
}
double  dist(double x1 , double y1  , double x2 , double y2){
    return sqrt(pow(x2 -x1 , 2) +  pow(y2 -y1 , 2)  );
}
const int N = 201;

int par[N] , rnk[N] ;
void makeset(){
    lp(i,0,N){
        par[i] = i ;
        rnk[i] = 0 ;
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

    int cnt = 0;
    while(true) {

        makeset();
        int pts;
        cin >> pts;
//        if(cnt)cout<<endl;
        cnt++;
        if(!pts)break;


        vector<pair<double, double> > mvec(pts);
        vector<pair<double, pair<int, int> > > edges;
        lp(j, 0, pts) {
            double x, y;
            cin >> x >> y;
            mvec[j] = {x, y};

        }
        lp(k, 0, pts) {
            lp(j, k + 1, pts) {  /// MAKE ALL EDGES ,NO NEED FOR O(N^2)
                if (k != j) {
                    double temp = dist(mvec[k].first, mvec[k].second, mvec[j].first, mvec[j].second);
                    edges.push_back({temp, {k, j}});
                }
            }
        }
        sort(edges.begin(), edges.end());
        int kk = 0 , src = 0 , dest = 1;
        double ret = 0 ;
        while(true){
            int psrc = findPar(src), pdest = findPar(dest);
            if(psrc == pdest){
                break;
            }
            auto curr = edges[kk++];
            auto dest = curr.first;
            auto x = findPar(curr.second.first);
            auto y = findPar(curr.second.second);
            if(x!=y){
                ret= max(ret , dest);
                merge(x  , y);
            }

        }
        cout<<"Scenario #"<<cnt<<endl;
        cout<<"Frog Distance = "<<fixed<<setprecision(3);
        cout<<ret<<endl<<endl;


    }
}
