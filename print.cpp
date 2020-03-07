/// matrix exponentiation
void matrixMultiply (ll Matrix[2][2] , ll mid[2][2] ){
    int res[2][2] = {{0,0 } , {0,0}};

    for (int i = 0; i<2 ; ++i) {
        for (int j = 0; j <2 ; ++j) {
            for (int k = 0; k <2 ; ++k) {
                res[i][j] = add(res[i][j],multipy( Matrix[i][k],mid[k][j]));
            }
        }
    }
    for (int l = 0; l <2 ; ++l) {
        for (int i = 0; i < 2; ++i) {
            Matrix[l][i] = res[l][i];
        }
    }
//    return res;



}

void binpow( ll y[2][2],int b ) {
    if(b== 0 || b==1) {
        return  ;

    }
    binpow(y, b/2);
//    matrixMultiply(y, y);
//    vector<vector<ll >> y = binpow(b/2);
    matrixMultiply(y , y);
    if(b&1)
        matrixMultiply(y , M);
    return ;

}
/// to get distance from point by coordinates


int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

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

///
/// sparse table implementation
const int N = 1e5 +5;
const int lgN = 17;
int memo[N][lgN];/// memo (i, j) contains the minimum element index in range starting from i with length 2^j
int arr[N];
void processSparseTable(){
    for (int i = 0; i < N; ++i) {
        memo[i][0] = i;
    }
    for (int j = 1; 1<<j <=N ; ++j) {
        for (int i = 0; i + (1<<j) -1<N ; ++i) {
            if(arr[memo[i][j-1]] <= arr[memo[i+(1<<(j-1))][j-1]]){
                memo[i][j] =memo[i][j-1];
            }
            else{
                memo[i][j]= memo[i+(1<<(j-1))][j-1];
            }
        }
    }

}
int RMQ(int l , int r){
    int len =(int)log2( r-l+1);
    int length = 1<<len;
    if (arr[memo[l][len]] <= arr[memo[r - (1 << len) + 1][len]])
        return memo[l][len];
    else
        return memo[r - (1 << len) + 1][len];
    if(arr[memo[l][len]] <=arr[memo[r-length +1][len]])
        return memo[l][len];
    return memo[l+ (1<<(len-1)) -1][len-1];
}