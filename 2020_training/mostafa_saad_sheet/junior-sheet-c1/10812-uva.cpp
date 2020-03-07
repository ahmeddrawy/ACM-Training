/// ACM-ICPC-Swiss-Subregional 2017 - by ahmed_drawy 16/10/19
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;


template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


using namespace std;
#define ll long long
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v));
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'
#define debug(x) cerr << x<<endl;
const double EPS = (1e-7);
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}
int randomF() {
    return  (rand() * RAND_MAX + rand()) % 1000000;

}


void solve(ll s,  ll d ){
    ll y1 = s- (s+d)/2;
    ll y2 = (s+d)/2;
    ll r = max(y1 , y2);
//    cout<<"check " << ((y1+ y2) == s) << endl;
    if(y1< 0 || y2<0||  s !=y1+y2 || abs(y1 - y2) !=d){
        cout<<"impossible";
    }
    else {
//        int x = s -r;
        cout << max(y1, y2) << " "<<min(y1, y2) ;

    }

}

int main() {
    smile();
    int q ; cin >> q;
    for (int i = 0; i <q ; ++i) {

        ll s , d ; cin >> s >> d;

        solve(s , d);
        cout << endl;
    }

}