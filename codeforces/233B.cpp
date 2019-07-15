/*
   p233B
   24/11/18
   by ahmed_drawy
   ACCEPTED

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

void printarr(int arr [] , int n){
lp(i,0,n) cout<<arr[i]<<" ";cout<<endl;
}

void printset(int n ){
    stack <int> myst;
    while(n)    myst.push(n%2), n/=2;
    while(!myst.empty())    cout<<myst.top(), myst.pop();
    cout<<endl;
}
int fun(ll i ){
    int sum = 0;
    while(i){
        sum +=i%10;
        i/=10;
    }
    return sum;
}

int main(){
	smile();

    ll n ; cin >> n ;

    for(ll i  = 1 ; i <=153 ; ++i){    /// searching for s(x) then solving quadratic equation
            ll rt = i*i +4*n ;
            if(rt >=0){

                ll x1 = -1*i + sqrt(rt);
                    x1/=2;
                ll x2 = -1*i - sqrt(rt);
                    x2/=2;

            if(x1*x1 + i*x1 -n == 0 || x2*x2 +i*x2 - n == 0){
                if(x1==x2 && x1 <=0)  continue;
                else if(x1<x2 && x1<=0) swap(x1,x2);
                else if(x2<x1 && x2 >0)swap(x1,x2);

                if(fun(x1) == i  ){

                    cout<<x1;
                    return 0 ;
                }
                else if(x2>0 && fun(x2) ==i){
                    cout<<x2;
                    return 0;
                }
            }
            }


    }

///    for(ll i = 0 ; i*i <=n ;++i){
//            if(i*i +fun(i) * i == n && n>fun(i) *i){
//                cout<<i;
//                return 0;
//
//            }
//
//    }
    cout<<-1;

}

