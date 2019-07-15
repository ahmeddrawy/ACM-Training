/** good one - check comments below
   problem  - 514 B
   19/01/19
   by ahmed_drawy
    sheet B
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
int dcomp(double x , double y)
{
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile(){
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
}
int main(){
	smile();
// 	freopen("in.txt", "r" , stdin);
	int x , y, x1, y1 , n ; cin >> n>>x >> y ;
	map<pii , int > mmap ;
	bool onX = 0  , onY = 0 ;
	lp(i,0, n ){
        cin>>x1>>y1 ;
        if(x1 == x){
            onX=1;continue;
        }
        if(y1 ==y) {    /// count all on the same as Y as one , and the same with x
            onY=1;
            continue;

        }
        int yy = y1 - y ;
        int xx  = x1 - x ;
        int gcd = __gcd(abs(yy) , abs(xx));
        /// counting the same with the same slope as one , here i don't get the slope because of the percision problems
        /// calcaulating difference for y1- y and x1 - x
        /// 3 cases if both are -ve then put the abs for both and if one only is -ve put the -ve in y
        /// the third case is both are +ve
        /// dividing by the gcd to put the fraction in the simplest form and count 1/2 , 2/4 as one
        if(yy < 0 && xx  < 0 ){
            mmap[{abs(yy) /gcd , abs(xx) / gcd} ] ++;
        }
        else if((yy  < 0 && xx>0)||(xx<0 && yy>0)) {
            mmap[{ -1* abs(yy)/gcd , abs(xx)/gcd} ] ++;
        }
        else {
            mmap[{yy/gcd , xx/gcd}]++;
        }
	}

	cout<<mmap.size() +onX+ onY ;

}


