/*
   problem  - 186B
   13/01/19
   by ahmed_drawy
   accepted
   sheet
   technique  : greedy - choose the bigger one in 2 cases and max on it
   self notes :
*/


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
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
struct cmpPAIR{
    bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
        return  x.first != y.first ? x.first > y.first : x.second < y.second ;
}
};

int main(){
	smile();
 	freopen("in.txt", "r" , stdin);
	auto cmp = []( const pair<double , int> & x, const pair<double , int> & y){
	    return fabs(x.first - y.first)<=1e-3?x.second <y.second : x.first>y.first;
//        return  x.first != y.first ? x.first > y.first : x.second < y.second ;
    };///declaring function to sort the set with the criteria i want

    set<pair<double ,int> ,decltype(cmp) >mset(cmp);
    int n , t1 , t2 , a ,b ;
    double k ;
    cin >>n>>t1>>t2>>k;
    lp(i,0,n){
       cin>>a>>b;
        mset.insert({max((a- a*(k/100) )*t1+ b*t2 , (b -b*(k/100))*t1 + a*t2) , i+1});

    }
    cout<<fixed<<setprecision(2);
    for(auto it = mset.begin() ; it != mset.end() ; ++it){

        cout<<it->second << " "<<it->first<<'\n';
    }
}


