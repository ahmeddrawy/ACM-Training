/*

   problem  - C
   25/01/19
   by ahmed_drawy
    round 534 div2 - upsolve
    greedy - fill the one corner up with horizontal and other corner down with vertical
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
int arr[10][10];
bool can (int x , int y){
    return x >0 &&x<=4 &&y>0 &&y<=4 && !arr[x][y];
}
void deleted(){
    lp(i,1,5){
        int sum = 0;

        lp(j,1,5){
            sum +=arr[i][j];
        }
        if(sum == 4){
            lp(j,1,5)
                arr[i][j] = 0;
        }


    }
    lp(i,1,5){
        int sum = 0;
        lp(j,1,5){
            sum +=arr[j][i];
        }
        if(sum == 4){
            lp(j,1,5)
                arr[j][i] = 0;
        }

    }

}
void printit(){
    lp(i,1,5){
        lp(j,1,5) cout<<arr[i][j];
        cout<<endl;
    }
}
/// fill the above right corner with vertical or horizontal and the opposite below with the opposite
/// to greedily  fill the grid
int main(){
	smile();
  	freopen("in.txt", "r" , stdin);
    string s ; cin >> s;
    lp(k,0,s.size()){
        cout<<k<<" ";
        bool breaked = 0;
        deleted();
        if(s[k ] == '1'){
          lp(i,1,5){
                lp(j,1,5){

                        if(can(i,j) && can(i,j+1)){
                            cout<<i<<" "<<j<<'\n';
                            arr[i][j] =1;
                            arr[i][j+1] =1;
                            breaked =1 ;
                            break;
                        }


                }
                if(breaked)
                    break;

            }

        }
        else {

            for(int i = 4 ; i >= 1  ; --i ){
                for(int j = 4 ; j >= 1  ; --j ){
                    if(can(i,j) && can(i-1 , j)){
                        cout<<i-1<<" "<<j<<'\n';
                        arr[i][j] =1;
                        arr[i-1][j] =1;
                        breaked =1 ;
                        break;
                    }

                }
             if(breaked )break;
            }
        }
    }
}



