/**
   problem  - 476B
   07/01/19
   by ahmed_drawy
   mostafa saad sheet
   recursion
   technique  :/// ezhaustive recursion to get all the cases where n == ncnt and p == pcnt
                /// divide by the number of 2 ^ no of ? (because total search space to get the probability)
                /// max length = 10 so max complexity for 2^n == 1024

   self notes    :   need to try better approach using DP
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

string in , s ;
int Ncnt , Pcnt;
int cnt = 0 ;
int sq = 0 ;
void solve(int indx , int p , int n ){
    if(indx == s.size() ){

        if(p == Pcnt && n == Ncnt ){ /// ezhaustive recursion to get all the cases where n == ncnt and p == pcnt
            cnt++;
            return;
        }
        return ;
    }
    if(s[indx ] == '+')
        solve(indx+1 , p +1 , n );
   else if(s[indx ] == '-')
            solve(indx +1 , p , n+1 );
   else {

        solve(indx+1 , p , n+1);
        solve(indx+1 , p+1 , n);
   }
    return;


}

int main(){
	smile();
// 	freopen("in.txt", "r" , stdin);
    cin >> in >> s ;
    lp(i,0, in.size()){
        in[i] == '+'?Pcnt++ : Ncnt++;
    }


    lp(i,0, s.size())
        if(s[i] == '?') sq++;
    solve(0, 0, 0 );

    cout<<fixed<<setprecision(9);
    cout<<double(cnt) / (1<<sq);

}



