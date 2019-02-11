/*
 276C- phase 2 2019
  05/02/19
  by -ahmed_drawy

*/

#include <bits/stdc++.h>

using namespace std;
//#define push_back               pb;
//#define make_pair               mp;
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
void smile(){
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
}
ll arr[200005];
ll frq[200005];
vector<pii> query ;
int main(){
    smile();
    freopen("in.txt", "r" , stdin);
    int n ,q ; cin >> n >>q ;
    lp(i,0,n){
        cin>>arr[i];
    }
    lp(i,0,q){
        int  x , y ;cin >>x>>y;
        --x , --y;
        pii p = {x , y};
        query.push_back(p);
        frq [x] +=1 ;
        frq[y+1] -=1;

    }
    lp(i,1,n)frq[i] +=frq[i-1];

    vector<pii >pq;
    lp(i,0,n)
        pq.push_back({frq[i] , i });
    sort(pq.rbegin() , pq.rend());
    sort(arr, arr+n  , greater<ll >());
    lp(i,0,n){
        frq[pq[i].second] =arr[i];
    }

    lp(i,1,n)frq[i] +=frq[i-1];

    ll sum = 0 ;
    for(auto it : query ){
        pair<int  , int > curr = it ;
        if(it.first ==  0 ){
            sum+=frq[it.second];

        }
        else{
            sum +=(frq[it.second ] - frq[it.first -1]);

        }

    }
    cout<<sum;


}

