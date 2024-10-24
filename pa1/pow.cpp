#include <iostream>
using namespace std;

const int MOD = 1000000007;
//快速幂
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  
            result = (result * base) % mod;
        }
        base = (base * base) % mod;  
        exp /= 2;  
    }
    return result;
}

int main() {
    int m;
    cin >> m;
    long long n;
    cin >> n;
    cout << mod_pow(m, n, MOD) << endl;
    return 0;
}
