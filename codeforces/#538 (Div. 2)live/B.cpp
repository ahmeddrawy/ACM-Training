/**

  A- #538 (Div. 2) - live

  10/02/19
  by -ahmed_drawy



*/

#include <bits/stdc++.h>

using namespace std;
//#define push_bac                pb;
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
#ifndef ONLINE_JUDGE
    freopen("/home/www/Desktop/training/in.txt", "r" , stdin);
//    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE


}
ll arr[200005];
int main(){
    smile();
    int  n , m  , k  ; cin >> n >>m>>k;
    lp(i,0,n ) {
        cin >>arr[i ];

    }
    int cnt =n -  m*k;
    ll ans = 0 ;
    vector<int > indx  ;
    lp(i,0,n ){
        priority_queue<ll , vector<ll > , greater<ll> > pq;

        for(int j = 0  ; j < m  ; ++j , ++i){
            pq.push(arr[i]);


        }
        cout<<pq.top()<<endl;
////        sort(mvec.rbegin() ,m/*vec.rend() );

        while(cnt  && arr[i+1] >pq.top()){
            pq.push(arr[i+1]);
            ++i;
            cnt--;

        }
        while (!pq.empty()){

            cout<<pq.top()<<" ";
        }
        cout << endl ;
//
//       if(cnt && i == n){
//            mvec.push_back(arr[i]);
//        }
//
//        indx.push_back(i);
//        --i;
//
//        lp(j,0,m)
//            ans+=mvec[j];
//*/
    }
    cout<<ans <<endl;
    for(int i = 0 ; i < k-1 ; ++i )cout<<indx[i]<<" ";

}