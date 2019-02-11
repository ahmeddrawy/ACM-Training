/*
   441 uva
   21/11/18
   by ahmed_drawy
   brute force with recursion
   take it once and leave it once
   i think we can make it better with dp will check this later
   accepted
   will try nested loop approach in cp3
accepted
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
int arr[14];
int  k ;
void combination( int indx , int  i , int data[] ){
    if(indx == 6){
//        sort(data , data+7);
        lp(i,0,5)   cout<<data[i]<<' ';
        cout<<data[5];
        cout<<'\n';
        return;
    }
    if(i>=k)return ;
    data[indx ]= arr[i];            /// include current indx
    combination(indx+1 , i+1 , data);
    combination(indx , i+1 , data);


}
int main(){
	smile();
//	freopen("out.txt","w", stdout);
    int t= 0;
	while(cin>>k){
        if(!k)break;
        if(t)   cout<<'\n';
        t++;
        clr(arr, 0);
        inN(arr, k);
        sort(arr, arr+k);
        lp(i,0,k-5)
            lp(j,i+1,k-4)
                lp(x , j+1 , k-3)
                    lp(y,x+1,k-2)
                        lp(z,y+1,k-1)
                            lp(w,z+1,k)
                                cout<<arr[i]<<' '<<arr[j]<<' '<<arr[x]<<' '<<arr[y]<<' '<<arr[z]<<' '<<arr[w]<<'\n';

//        int data[6];
//        combination(0,0,data);
	}
}
