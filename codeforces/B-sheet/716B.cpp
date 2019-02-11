/*

  716B - sheet B
  08/02/19
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
int dp[300005][20][4];
int n ;
const int mod = 1e9+7;
int solve (int indx,int sum , int k = 0  ){
    cout<<indx << " "<<sum <<" "<<k <<endl;
    if(k== 3)return sum !=6 ;
    int & ret = dp[indx][sum][k];
    if(~ret) return ret;
    ret= 0 ;
    if(k ==1 ){
        lp(i,0,n){
            ret = solve(i + n  , sum +1 , k+1)%mod  + solve(i + n , sum +2 , k +1 )%mod
                + solve(i +n , sum +3 , k+1)%mod;
            ret %= mod ;
        }
    }
    else {
        ret = solve(indx + n  , sum +1 , k+1)%mod  + solve(indx + n , sum +2 , k +1 )%mod
            + solve(indx +n , sum +3 , k+1)%mod;
        ret %= mod ;

    }

    return ret ;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r" , stdin);
//    freopen("out.txt" , "w" , stdout);
    #endif // ONLINE_JUDGE
    string s; cin >> s;
    int n = s.size();
    if(n<26){
        cout<<-1;
        return 0 ;
    }
    bool ok = 1;
    for(int i = 0 ; i< n && ok ; ++i){
        map<char ,int  > temp;
        for(int j = 0 ; j < 26 && i + j < n  && ok ; ++j ){
            temp[s[i+j]]++;
        }
        queue<char> mq;
        int cnt = 0 ;
        lp(i,0,26){
            if(temp[i+'A'] == 0){
                    cnt++;
                mq.push(i+'A');
            }
        }
        if(cnt<=temp['?']){

            for(int j = i ; j < i+26 && j <  n ; ++j){
                if(s[j] == '?' &&  !mq.empty()){/// mq will never be empty but for safety - i think its redundant but for the goddamn sake of safety and errors
                    s[j] = mq.front();
                    mq.pop();
                }

            }
            ok = false ;
        }

    }
    if(!ok){
        lp(i,0,  n){
            if(s[i] == '?')
                s[i] = (i+26)%26 + 'A';
        }
    }
    else s="-1";
    cout<<s;

}
