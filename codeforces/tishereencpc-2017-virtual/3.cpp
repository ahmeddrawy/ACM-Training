/*
   pH
   5/12/18
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
int dp[1001][3];
int n , k ;
int arr[1001][3];
//int solve(int indx  ,int curr, int sum = 0  , int kk = 0){
//    if(sum == k || indx == n )    return 0 ;
//    int &ret= dp[indx][sum];
//    if(~ret)    return ret;
//    ret = INT_MAX;
//    ret= min(ret , solve(indx +1 , 0 , sum , ) );
//
//    for(int i =  curr ; i < 3 ; ++i)    {
//        ret = min(ret , solve(indx , curr, sum  , kk));
//        ret = min (ret , arr[indx][i] + solve(indx, i , sum , kk+1));
//
//    }
//
//
//
//    return ret;
//}
int solve(int indx , int curr , int sum , int no = 0){
    if(sum == k || indx== n)    return 0 ;
    int & ret = dp[indx][curr];
    if(~ret)return ret ;
    ret= INT_MAX;
    ret = min (ret , solve( indx + 1 ,  0 , sum ));
    if(no < 2 && curr <2){
        ret = min(ret , solve( indx , curr+1 , sum +1 ,no ));
        ret = min(ret , arr[indx][curr ] +solve( indx , curr+1 , sum +1 ,no +1 ));
    }
    else {
        ret = min (ret , solve(indx+1 , 0 , sum , 0));
    }
}
vi vec2(3);
int main(){
	smile();
	int t; cin >> t;
	while(t--){
            clr(dp , -1);
        cin>>n>>k;
        vector<int> vec;
        lp(i,0, n ){

            lp(j,0,3){
                cin>>arr[i][j];
                vec2[j] =arr[i][j];
            }
            sort(vec2.begin() , vec2.end());
            vec.push_back(vec2[0]);
            vec.push_back(vec2[1]);
        }
        sort(vec.begin() , vec.end());
        ll ret = 0 ;
        for(int i = 0 ;i < k ;  ret +=vec[i] , ++i);
        cout<<ret<<'\n';
	}



}

