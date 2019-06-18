/*
     #552 (Div. 3)- C
  by ahmed_drawy



*/
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
void smile() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/www/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/www/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
struct compareIterator{
    bool operator()(pair<int ,list<pair<int , int> >::iterator > &x , pair<int ,list<pair<int , int> >::iterator > &y){
        return x.first <y.first;

    }

};


priority_queue < pair<int ,list<pair<int , int> >::iterator >, vector<pair<int ,list<pair<int , int> >::iterator > >, compareIterator > mq;
list<pair<int , int> >mlst;/// first in the list is redundant and can be removed
int arr[200005];
bool visited[200005];
list<pair<int , int> >::iterator solve(){
    while (true){
        if(mq.empty())break;
        auto curr = mq.top();
        if(!visited[curr.first]){

            return curr.second  ;
        }
        mq.pop();
    }
    return mlst.end();

}
int main() {
    smile();
    int n , k ; cin >> n>>k ;
    lp(i,0,n){
        cin>>arr[i];
        mlst.push_back({arr[i],i});
        auto it = mlst.end();
        --it;
        mq.push({arr[i], it});
    }
    vector<int> mvec(n);
    int turn = 0;
    int finished =  0;
    while (true){
        turn %=2;turn++;
        auto indx = solve();    /// iterator to top
        if(indx == mlst.end() )break;
        int cnt = k ;
        auto it = indx;
        ++it;
        visited[indx->first] =1;
        mvec[indx->second] = turn;
        for (; it !=mlst.end() && cnt>0;cnt-- ) {
            mvec[it->second] = turn;
            visited[it->first] = 1;
            it = mlst.erase(it);
        }
        cnt = k;
        it = indx;
        for(;cnt>0 ;cnt-- ){
            auto temp = indx;
            if(temp == mlst.begin())break;
            --temp;
            mvec[temp->second] = turn;
            visited[temp->first] = 1;
            mlst.erase(temp);
        }
        mlst.erase(indx);
    }
    lp(i,0,n)cout<<mvec[i];

}
