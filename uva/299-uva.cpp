/*
    299 uva
   3/11/18
   by ahmed_drawy
   counting inversions with merge sort
   accepted

*/


#include <bits/stdc++.h>
using namespace std;
//#define push_back               pb;
//#define make_pair               mp;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
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

ll cnt = 0;
void Merge(int arr[] , int left , int mid , int right) {
    int p = left  , q = mid +1;
    int sarr[right - left +1];
    int  k = 0;
    for(int i = left ; i <= right ; ++i){
        if(p>mid)   sarr[k++] = arr[q++];
        else if(q>right)    sarr[k++ ] = arr[p++];
        else if(arr[p]<= arr[q]){
            sarr[k++]  = arr[p++];
        }
        else {
            cnt  +=(mid - p +1);
            sarr[k++] = arr[q++];
        }
    }
    for(int i = 0 ; i< k ; ++i )
        arr[left++] = sarr[i];
}
void mergesort(int arr[] , int l , int r ){
    if(l<r){
        int mid = l+(r- l )/2;
        mergesort( arr , l , mid);
        mergesort( arr, mid+1 , r);
        Merge(arr , l , mid , r);

    }
}
int main(){
	smile();
    int t , s ,arr[50] ;
    cin>>t;
    while(t-- ){
        cin>>s;
        cnt = 0 ;
        clr(arr, 0);
        lp(i,0,s)   cin>>arr[i];
        mergesort( arr, 0 , s - 1);
        cout<<"Optimal train swapping takes ";
        cout<<cnt<<" swaps."<<endl;
    }

}
