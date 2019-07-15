/*
  D  #535 (Div. 3)
  06/02/19
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
int n ;
int  dx[] ={1, 2, 3};
int arr[200005];
int dp[200005][4];
int solve(int indx , int clr= 0 ){
    cout<<indx <<" "<<clr << endl;
    if (indx == n ) return 0 ;
    int & ret = dp [indx] [clr];
    if(~ret) return ret;
    ret= 1<<25 ;
    lp(i,0,3){
//        cout<<(arr[indx ]== dx[i]);
        if(clr == dx[i] ) continue;
        ret = min(ret  , 1 +solve(indx +1 , dx[i]   ) );

    }
    return ret ;

}
string ch[]={"R", "G", "B"};
int myint[] = {1 , 2, 3};
int main(){
    smile();
    freopen("in.txt", "r" , stdin);
    int n ; cin >> n ;
    string x ; cin >> x ;
    string s = x;
    lp(i,1,n){
        if(s[i] == s[i-1]){
//            if((i+1) <n ){
//                if(s[i] == 'R')
//                    s[i] ='G';
//                else if(s[i ] == 'G')
//                    s[i] ='R';
//                else
//                    s[i] = 'R';
//            }
//            else {
                if(s[i+1] == 'R' ){
                    if(s[i-1] == 'G')
                        s[i] = 'B';
                    else
                        s[i] = 'G';
                }
                else if(s[i+1 ] == 'G'){
                    if(s[i-1 ] == 'R')
                        s[i] = 'B';
                    else
                        s[i] = 'R';

                }
                else { ///s[i+1] == B
                    if(s[i-1] == 'R')
                        s[i] = 'G';
                    else
                        s[i] = 'R';

                }
//            }
//            ++i;
        }


    }
    int cnt= 0 ;
    lp(i,0,n){
        if(s[i] !=x[i] ) cnt++;
    }
    cout<<cnt <<'\n';
    cout<<s;


}
