#include<iostream>
typedef long long int ll;
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        ll n, l, r, k;
        cin >> n >> l >> r >> k;

        if ( n % 2 != 0 ) cout << l << endl;
        else if ( n == 2 ) cout << -1 << endl;
        else {
            ll ans = 1;
            bool check = false;
            while ( ans <= r ) {

                if ( ans > l ) {
                    check = true;
                    if ( k < n-1 ) cout << l << endl;
                    else cout << ans << endl;

                    break;
                }
                ans *= 2;
            }
            if ( !check ) cout << -1 << endl;
        }
    }
    return 0;
}
