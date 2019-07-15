/**

  544 B- sheet B

  12/02/19
  by -ahmed_drawy
    greedy


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
/// greedy the max L you can put if n is even is (n*n)/2
/// if n is odd (n+1)/2 *(n+1)/2 + n/2 * n/2
/// the best solution in odd is to start from the first square (0,0)
/// in even it doesn't matter
/// since you don't have to maxmize the islands size then one cell is sufficient

int main(){
    smile();
    int  n , k  ; cin >> n >>k;

    int base = (n+1)/2;
    base*=base;
    base += (n/2)*(n/2);
    if(k>base){
        cout<<"NO";
        return 0 ;
    }
    cout<<"YES\n";
    lp(i,0,n){
        lp(j,0,n){
            if(k) {
                if (i % 2 == 0 && j % 2 == 0) {
                    cout << 'L';
                    --k;
                } else if (i % 2 == 0 && j % 2 != 0) {
                    cout << 'S';

                } else if (i % 2 != 0 && j % 2 == 0) {
                    cout << 'S';
                } else {
                    cout << 'L';
                    --k;
                }
            }
            else {
                cout<<'S';
            }
        }
        cout<<endl;

    }

}
