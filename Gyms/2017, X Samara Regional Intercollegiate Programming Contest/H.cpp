///SAMARA 2017 LOCAL ROUND
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif
}
const int N = 1001;
int arr[N][N];
int maxl[N][N];
int maxr[N][N];
int maxld[N][N];
int maxrd[N][N];

int main(){
    smile();
    int  n , m  ; cin >> n >>  m;
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j <m ; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <n ; ++i) {
        for (int j = 1; j <m ; ++j) {
            maxl[i][j] = max(maxl[i][j-1] , arr[i-1][j-1]);
            maxl[i][j] = max(maxl[i][j] , maxl[i-1][j]);
        }
    }
    for (int i = 1; i <n ; ++i) {
        for (int j = m-2; j>=0 ; --j) {
            maxr[i][j] = max(maxr[i][j+1] , arr[i-1][j+1]);
            maxr[i][j] = max(maxr[i][j] , maxr[i-1][j]);
        }
    }
    for (int i = n-2; i >=0 ; --i) {
        for (int j =1; j<m ; ++j) {
            maxld[i][j] = max(maxld[i][j-1] , arr[i+1][j-1]);
            maxld[i][j] = max(maxld[i][j] , maxld[i+1][j]);
        }
    }
    for (int i = n-2; i >=0 ; --i) {
        for (int j = m-2; j>=0 ; --j) {
            maxrd[i][j] = max(maxrd[i][j+1] , arr[i+1][j+1]);
            maxrd[i][j] = max(maxrd[i][j] , maxrd[i+1][j]);
        }
    }

    int mn = INT_MAX;
    int ansr = 0 , ansl = 0 ;
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j < m; ++j) {
            int temp = max(maxl[i][j] , maxld[i][j]);
            temp = max(temp, maxrd[i][j]);
            temp = max(temp, maxr[i][j]);
            if(temp < mn ){
                ansl= i , ansr = j;
                mn = temp ;
            }
        }

    }
    cout << ansl +1 <<" " << ansr+1;
}