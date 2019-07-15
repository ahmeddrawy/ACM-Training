/*
   problem  - 143B
   27/01/19
   by ahmed_drawy
   phase 2 - training 2019
   technique  :
   self notes :
*/


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
typedef tree<
        pair<int, int>, // change type
        null_type,
        less<pair<int, int> >, // change type
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
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
bool sortpair( const pair<int , int> & x, const pair<int , int> & y)
{

    return  x.first != y.first ? x.first < y.first : x.second > y.second ;


}
int dcomp(double x , double y)
{
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile(){
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
}


void solve(int pt , string &s ){
    cout<<'$';
    if(pt<=3){
            lp(i,0,pt)
            cout<<s[i];
    }
    else {
        lp(i,0,pt%3)
        cout<<s[i];
        if(pt%3)
        cout<<',';
        for(int i = pt%3 , j =1 ; i<pt; ++i , ++j){

            cout<<s[i];
            if(j%3== 0){
                if(i !=pt-1)
                cout<<',';
            }
        }
    }
    if(s.size() - pt >2){
        cout<<'.'<<s[pt+1]<<s[pt+2];
    }
    else if(s.size() -pt ==0) {
        cout<<".00";
    }
    else {
        cout<<'.'<<s[pt+1] <<0;
    }


}
int main(){
	smile();
	freopen("in.txt", "r" , stdin);
    string s ;
    cin >> s;

    auto ngv = s.find('-');
    bool isPT = 1 ;


    if(ngv !=string ::npos){
        cout<<'(';
        s.erase(s.begin() + ngv);
    }
    auto pt = s.find('.');
    if(pt ==string::npos){
      pt = 1<<20;
      isPT =0;
    }
    if(isPT){
            solve(pt , s);

    }
    else {
        solve(s.size() , s);
    }
    if(ngv!=string ::npos)cout<<')';



}



