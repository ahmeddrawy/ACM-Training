/*
     #552 (Div. 3)- C
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
//    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}

int main() {
    smile();
    int a , b, c ;cin>>a>>b>>c;
    int weeks = INT_MAX;
    weeks = min(weeks , a/3);
    weeks = min(weeks , b/2);
    weeks = min(weeks , c/2);
    a -=  3*weeks;
    b -= 2*weeks;
    c -= 2*weeks;
    int ans = 0 ;
    lp(i,0,7){
        int ta = a;
        int tb = b;
        int tc = c;
        int cnt = 0 ;
        /// starting from j = i to start from diff week day and loop on it
        for(int j = i ; j <1000*7 ; ++j){     /// 1000 just in case , but it should break inside in the first weeks
            int day = j%7;
            if(day == 0 ||day == 3) {
                if(tb)
                    tb--,cnt++;
                else break;

            }
            if(day == 1 ||day == 2 ||  day ==5) {
                if(ta)
                    ta--,cnt++;
                else break;
            }
            if(day == 4 ||day == 6) {
                if(tc)
                    tc--,cnt++;
                else
                    break;
            }


        }
        ans  =max(ans , cnt);

    }

    cout<<ans + weeks *7;

}

