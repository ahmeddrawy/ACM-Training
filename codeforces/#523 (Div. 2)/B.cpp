/*
    pB round 523 live
   22/11/18
   by ahmed_drawy

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
int arr[100005];
int r[100005];
int c[100005];
int main(){
	smile();
	map<int , int >mmap;
	priority_queue<pii>pq;
    int n , m ; cin>>n>>m;
    ll sum = 0 ;int mx = 0;
    lp(i,0,n){
        cin>>arr[i];
        sum+=arr[i];
//        pq.push({arr[i] , i});
        mmap[arr[i]]++;
        mx = max(mx  , arr[i]);
    }
    ll ans = mx ;
    lp(i,1,mx+1){
        if(mmap[i])
        ans +=mmap[i] -1;


    }
    cout<<sum-ans;
//    if(mmap[mx ]>1)  cout<<sum - mx-(n-mx);
//   else  cout<<sum-ans;
//    while(!pq.empty()){
//        pii curr = pq.top();
//        pq.pop();
//        r[curr.second] = 1;
//        c[curr.first] = 1;
//
//    }
//    ll ans = n;
//    lp(i,0,mx){
//        if(c[i] !=0)    ans+=1;
//    }
//    if(ans ==0) cout<<0;
//    cout<<sum-ans;
//    ll ans = 0;
//    int rows = mx;
//    ans +=mx ;
//    sort(arr  , arr+n);
//    lp(i,0,n){
//
//
//        if(arr[i]<=mx &&arr[i]>1){
//            if(rows == 0)
//                ans+=1;
//        else    rows--,ans -=1;
//
//        }
//        else{
//            ans+=1;
//        }
//    }
//    cout<<sum-ans-1<<endl;
//
////    int rows = n;
////    int ans = sum - mx;
////    sort(arr, arr+n);
////    if(mx >=n)
////    lp(i,0,n-){
////        if(arr[i] == 1)     ans++;
////    }
////    else {
////
////    }
//////    for(int i = mx ; i >=1 ; --i){
////        if(mmap[i]){
////            mmap[mx]--;
////            ans++;
////            rows--;
////        }else {
////            if(mmap[mx]) mmap[mx]--,rows--;
////        }
////    }
//    cout<<rows<<" "<<mx<<endl;
//    cout<<sum -mx -rows;

}

