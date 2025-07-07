#include<iostream>
using namespace std;


int main () {
    int t; cin >> t;
    while ( t-- ) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        if ( a > b ) cout << ( (a ^ 1) == b ? y : -1 ) << endl;
        else {
            
            int multix = a % 2 == 0 ? (b-a)/2 : (b-a+1)/2;
            int multiy = a % 2 == 0 ? (b-a+1)/2 : (b-a)/2;
            cout << ( y < x ? (1LL)*multix*x + (1LL)*multiy*y : (1LL)*(multix+multiy)*x ) << endl; 
        }
    }
    return 0;
}
