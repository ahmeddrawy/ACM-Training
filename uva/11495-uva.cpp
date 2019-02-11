/*
    11495 uva
    sagheer training
    merge sort
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

void printarr(int arr [] , int n){
lp(i,0,n) cout<<arr[i]<<" ";cout<<endl;
}

void printset(int n ){
    stack <int> myst;
    while(n)    myst.push(n%2), n/=2;
    while(!myst.empty())    cout<<myst.top(), myst.pop();
    cout<<endl;
}
ll cnt = 0;
void Merge(int A[] , int left , int mid , int right){
    ll p = left , q = mid +1 ;
    int Arr[right - left +1];
    int  k = 0 ;
    for(int i = left ;i <=right  ; ++i){
        if(p>mid)                   ///if the first part is finished
            Arr[k++] = A[q++];
        else if(q>right)            /// if the second is finished
            Arr[k++]= A[p++];
        else if(A[p] <=A[q])            /// check if the first part element smaller than the second one
            Arr[k++] = A[p++];
        else{
            cnt+=mid - p +1,Arr[k++] = A[q++];  /// counting inversions
//            cout<<q<<" <= q == p => "<<p <<" left "<<left<<" mid "<<mid<<" right "<<right <<endl;
        }

    }
    for(int i = 0 ; i < k ; ++i)
        A[left++] = Arr [i];
}
void mergesort(int arr[] , int left , int right){
    if(left<right){
        int mid = left +(right-left)/2;
        mergesort(arr , left , mid);
        mergesort(arr , mid+1 , right);
        Merge(arr, left , mid , right);


    }

}
 int arr[100005];
int main(){
	smile();
	while(1){
        int n ; cin>>n ;
        if(!n)return 0;
        cnt = 0;
        clr(arr, 0);
        lp(i,0,n)   cin>>arr[i];
        mergesort(arr, 0  , n-1);
        if(cnt&1)
            cout<<"Marcelo\n";
        else
            cout<<"Carlos\n";
	}

}
