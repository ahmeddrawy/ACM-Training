//
// Created by ahmed_drawy on 20/06/19.
//  #560 (Div. 3)_virtual A

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
#define inf 0x3f3f3f3f
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
//typedef vector<vector<int> >    adj;
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
const long long modul = 1000000007;

ll mod(ll x) {
    return (x%modul + modul)%modul;
}
const int N = 200001;
int arr[N];

int main() {
    smile();
    int n; cin >> n ;
    string s ; cin >> s;
    s = s + "==";
    vector<char> mvec;
    int cnt = 0 ;
    for (int k = 0; k <n ;) {
        if((k-cnt)%2 == 0 ){
            int i = k +1;
            for ( i = k+1; i <=n ; ++i) {
                if(s[k]!= s[i])break;
                else cnt++;
            }
            mvec.push_back(s[k]);
            k= i;

        }
        else{
            mvec.push_back(s[k]);
            k++;
        }
    }
    cout<< n - mvec.size() +( mvec.size()%2!=0) <<endl;
    lp(i,0,mvec.size() - mvec.size()%2 !=0){
        cout<<mvec[i];
    }

    return 0;
    for (int i = 0, j =1 ; i <=n && j<=n ; ) {
        if(i%2 == 0 && s[i] == s[j]){
            j++;
        }
        else {
            mvec.push_back(s[i]);
            i= j;j = i +1;
        }
    }
    cout<< n- mvec.size() + (mvec.size() %2 !=0)<<endl;
    lp(i,0,mvec.size() - mvec.size()%2 !=0){
        cout<<mvec[i];
    }

}
//
// Created by ahmed_drawy on 20/06/19.
//  #560 (Div. 3)_virtual A

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
#define inf 0x3f3f3f3f
typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
//typedef vector<vector<int> >    adj;
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
const long long modul = 1000000007;

ll mod(ll x) {
    return (x%modul + modul)%modul;
}
const int N = 200001;
int arr[N];

int main() {
    smile();
    int n; cin >> n ;
    string s ; cin >> s;
    s = s + "==";
    vector<char> mvec;
    int cnt = 0 ;
    for (int k = 0; k <n ;) {
        if((k-cnt)%2 == 0 ){
            int i = k +1;
            for ( i = k+1; i <=n ; ++i) {
                if(s[k]!= s[i])break;
                else cnt++;
            }
            mvec.push_back(s[k]);
            k= i;

        }
        else{
            mvec.push_back(s[k]);
            k++;
        }
    }
    cout<< n - mvec.size() +( mvec.size()%2!=0) <<endl;
    lp(i,0,mvec.size() - mvec.size()%2 !=0){
        cout<<mvec[i];
    }

    return 0;

}