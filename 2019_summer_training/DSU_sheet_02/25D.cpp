/*
    summer 2019 - DSU sheet - 25D
     by ahmed_drawy




*/
#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;

#define make_pair               mp;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2 *haven't understood this yet
#define isPowerOfTwo(S) (!(S & (S - 1)))            // done
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))  // TBD
#define turnOffLastBit(S) ((S) & (S - 1))       // turn off last unset bit from right
#define turnOnLastZero(S) ((S) | (S + 1))       //turn on last unset bit from right
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
#define inf 0x3f3f3f3f
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
//typedef vector<vector<int> >    adj;
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
//    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
const long long modul = 1000000007;

ll mod(ll x)
{
    return (x%modul + modul)%modul;
}


const int N = 1001;

int par[N] , rnk[N] ;

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
struct ans{
    int X , Y , U , V;
    ans(int x , int y , int u , int v){
        X = x , Y = y , U=u , V=v;
    }

};

int main() {
    smile();
    lp(i,0,N){
        par[i] = i ;
        rnk[i]= 0 ;
    }
    int n ; cin >> n ;

    vector<pii> removed;
    lp(i,0,n-1){
        int x ,  y; cin >> x >>  y;
        if(findPar(x ) == findPar(y)){
            removed.push_back({x,y});
        }
        else
            merge(x , y);
    }
    vector<ans>anss ;
    int  k = 0 ;
    lp(i,2,n+1){
        if(findPar(i)!= findPar(1)){
            ans t(removed[k].first , removed[k].second , findPar(i), findPar(1));
            anss.push_back(t);
            k++;
            merge(i , 1 );
        }
    }
    cout<<anss.size()<<endl;
    lp(i,0,anss.size()){
        cout<<anss[i].X<<" "<<anss[i].Y<<" "<<anss[i].U<<" "<<anss[i].V<<endl;
    }
    return  0;

}