/*
    upsolving
    413 - uva
  17/02/19
  by ahmed_drawy



*/

#include <bits/stdc++.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
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
    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE


}
int arr[55];

int main() {
    smile();

    int n ;
    while( cin >> n) {
        if(!n) break;
        inN(arr, n );
        vector<bool> mvec(n);
        std::fill(mvec.end() - 2, mvec.end(), true);
        double ans  = 0 ;
        ll cnt  = 0 ;
        do {
            ans++;
            vector<int > temp ;
            lp(i,0,n){
                if(mvec[i]){
                    temp.push_back(arr[i]);
                }
            }


            if(__gcd(temp[0] , temp[1]) == 1)
                cnt++;

        }
        while(next_permutation(mvec.begin() , mvec.end()));
        double ret = 0 ;
        if(cnt )
            ret = (ans * 6.0 )/cnt;

        ret =sqrt(ret);
        cout<<fixed<<setprecision(6);
        if(cnt)
            cout<<ret<<'\n';
        else {
            cout<<"No estimate for this data set.\n";
        }
    }

}
//#pragma clang diagnostic pop