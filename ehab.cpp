#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define vii vector<ll>
#define  F first
#define  S second
const int N = 1e5 +4 ;
#define   endl '\n'

ll cnt[15][N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///
    freopen("/home/tw3/Desktop/Desktop/training/in.txt" , "r" , stdin);///

    int q; cin >> q;
    while ( q-- ){
        vii vec; ll x, y; memset(cnt , 0 , sizeof cnt);
        cin >> x >> y; vec.clear(); vec.resize(x);
        for ( ll& i : vec ) cin >> i;

        for ( int i = 0; i < x; ++i ){
            for ( int j = 1; j <= 10; ++j ){
                cnt[j][i + 1] = (vec[i]%j == 0);
            }
        }
        for ( int i = 1; i <=- x; ++i ){
            for ( int j = 1; j <= 10; ++j ){
                cnt[j][i] += cnt[j][i - 1];
            }
        }

        for ( int i = 0; i < y; ++i ){
            int l ,  r, msk; int ret  = 0;

            cin >> l >> r >> msk;
            for ( int j = 1, k = 0; j <= 10; ++j , k++ ){
                if ( (msk&(1 << k)) != 0 ){
                    ret += cnt[j][r] - cnt[j][l - 1];
                }
            }
            cout << ret << endl;
        }

    }
    return  0;
}