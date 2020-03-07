/// ACM-ICPC-Swiss-Subregional 2017 - by ahmed_drawy 09/10/19
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
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
int randomF() {
    return  (rand() * RAND_MAX + rand()) % 1000000;

}

int MOD ;
int mod(ll x){
    return (x%MOD + MOD)%MOD;
}
long long add(long long x, long long y)
{
    x += y;
    while(x >= MOD)
        x -= MOD;
    while(x < 0)
        x += MOD;
    return x;
}
ll multipy(ll x , ll y ){
    return ((x%MOD) *(y%MOD))%MOD;
}
const int N = 1e6 + 5;
int factor[N];
int sieve() {

    for (int i = 2; i * i < N; ++i) {
        if (factor[i])
            continue;
        for (int j = i * i; j < N; j += i)
            factor[j] = i;
    }
}
set<int> factorize(int x) {
    set<int> ret;
    int prev = -1;
    while (x > 1) {
        if (factor[x] == 0)
            factor[x] = x;
        ret.insert(factor[x]);
        x /= factor[x];
    }
    return ret;
}
struct point{
    double x,  y;
    point (double _x  =0  , double _y  = 0 ) {
        x = _x;
        y = _y;

    }

};
double slope(point & a , point&b ){
    if(a.x == b.x)
        return 1e9;
    else if(a.y == b.y)
        return  0;
    else {
        return (a.y - b.y)/(a.x - b.x);
    }
}
point calcualtepoint(point & a , point &b , int distance){

    if(a.x == b.x){
        return point(a.x , a.y  + distance);
    }
    else if(a.y == b.y){
        return point(a.x + distance , a.y  );
    }
    else {
        double s = slope(a, b);
        point fst(a.x , a.y);
        point scd(a.x , a.y);
        fst.x -=1.0*distance/sqrt((1+s*s));
        scd.x +=1.0*distance/sqrt((1+s*s));
        fst.y -=1.0*distance*s/sqrt(1+s*s);
        scd.y +=1.0*distance*s/sqrt(1+s*s);
        if(scd.x <a.x && scd.y < a.y)
            return fst;
    }

}

double areaBypoints(point&a , point &b , point&c){
    return abs((a.x*(b.y - c.y) + b.x*(a.y - c.y) + c.x*(a.y - b.y))/2.0);


}
int main() {
    smile();
    point a , b ,c  ;
    cin >>a.x >> a.y;
    cin >>b.x >> b.y;
    cin >>c.x >> c.y;
    cout<<areaBypoints( a, b , c)<<endl;
    int n ; cin >> n ;
    vector<point> mvec1;
    vector<point> mvec2;
    vector<point> mvec3;
    for (int i = 0; i <n ; ++i) {
        int x ; cin >> x;
        mvec1.push_back(calcualtepoint(a,b,x));
    }
    cin >> n ;
    for (int i = 0; i <n ; ++i) {
        int x ; cin >> x;
        mvec1.push_back(calcualtepoint(b,c,x));
    }
    cin >> n ;
    for (int i = 0; i <n ; ++i) {
        int x ; cin >> x;
        mvec1.push_back(calcualtepoint(c,a,x));
    }

    double mx = 0 ;
//    cout << areaBypoints(mvec2[0] , mvec1[0] ,mvec3[0] )<<endl;
    for (int j = 2; j <sz(mvec1) ; ++j) {
//        for (int i = 0; i <sz(mvec1) ; ++i) {
//            for (int k = 0; k <sz(mvec1) ; ++k) {
//                if(i== j || i == k || j == k )continue;
        auto p1 = mvec1[j];
        auto p2 = mvec1[j-1];
        auto p3 = mvec1[j-2];
        double a = areaBypoints(mvec1[j] , p1 , p2);
        mx = max(mx , a);
//            }
//        }
    }
    cout << mx << endl;


    return  0 ;
}
--
/// ACM-ICPC-Swiss-Subregional 2017 - by ahmed_drawy 09/10/19
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
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}
int randomF() {
    return  (rand() * RAND_MAX + rand()) % 1000000;

}

int MOD ;
int mod(ll x){
    return (x%MOD + MOD)%MOD;
}
long long add(long long x, long long y)
{
    x += y;
    while(x >= MOD)
        x -= MOD;
    while(x < 0)
        x += MOD;
    return x;
}
ll multipy(ll x , ll y ){
    return ((x%MOD) *(y%MOD))%MOD;
}

struct point{
    double x,  y;
    point (double _x  =0  , double _y  = 0 ) {
        x = _x;
        y = _y;

    }

};
double slope(point & a , point&b ){

    return (a.y - b.y)/(a.x - b.x);

}
double distance(point & a , point & b){
    return sqrt((a.x - b.x)*(a.x - b.x) - (a.y-b.y)*(a.y-b.y));
}
bool online(point &a , point & b , point &c){
    return dcmp( distance(a,c ) +distance(b,c) ,distance(a,b)) == 0 ;

}
point calcualtepoint(point & a , point &b , double distance){

    if(a.x == b.x){
        return point(a.x , a.y  + distance);
    }
    else if(a.y == b.y){
        return point(a.x + distance , a.y  );
    }
    else {
        double s = slope(a, b);
        point fst(a.x , a.y);
        point scd(a.x , a.y);
        fst.x -=1.0*distance/sqrt((1+s*s));
        scd.x +=1.0*distance/sqrt((1+s*s));
        fst.y -=1.0*distance*s/sqrt(1+s*s);
        scd.y +=1.0*distance*s/sqrt(1+s*s);
        if(online(a,b ,scd))
            return scd ;
        return fst;
    }

}

double areaBypoints(point&a , point &b , point&c){
    return abs((a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y))/2.0);

}
point another(point & a , point & b , double distance ){
    double x = b.x- a.x;
    double y = b.y- a.y;
    double d=  sqrt((x)*(x) +( y)*( y) );
    x/=d;
    y/=d;
    x*=distance;
    y*=distance;
    return point(x, y);
//    return point((b.x- a.x)*distance/d , distance*(b.y-a.y)/d) ;
}
int main() {
    smile();
    point a , b ,c  ;
    cin >>a.x >> a.y;
    cin >>b.x >> b.y;
    cin >>c.x >> c.y;
//    cout<<areaBypoints( point(1,0), point(5,0) , point(6,6))<<endl;
    int n ; cin >> n ;
    vector<point> mvec1;
    vector<point> mvec2;
    vector<point> mvec3;
    for (int i = 0; i <n ; ++i) {
        double x ; cin >> x;
        if(i == 0 || i == n-1)
            mvec1.push_back(calcualtepoint(a,b,x));
    }
    cin >> n ;
    for (int i = 0; i <n ; ++i) {
        double x ; cin >> x;
        if(i == 0 || i == n-1)
            mvec1.push_back(calcualtepoint(b,c,x));
    }
    cin >> n ;
    for (int i = 0; i <n ; ++i) {
        double x ; cin >> x;
        if(i == 0 || i == n-1)
            mvec1.push_back(calcualtepoint(c,a,x));
    }

    double mx = 0 ;
//    cout << areaBypoints(mvec2[0] , mvec1[0] ,mvec3[0] )<<endl;
    for (int j = 0; j <sz(mvec1) ; ++j) {
        for (int i = j+1; i <sz(mvec1) ; ++i) {
            for (int k = i+1; k <sz(mvec1) ; ++k) {
                if(i== j || i == k || j == k )continue;
                auto p1 = mvec1[j];
                auto p2 = mvec1[i];
                auto p3 = mvec1[k];
                double a = areaBypoints(p3, p1 , p2);
                mx = max(mx , a);
            }
        }
    }
    cout<<fixed << setprecision(6) << mx << endl;


    return  0 ;
}