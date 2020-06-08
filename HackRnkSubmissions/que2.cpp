#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<int>::iterator vii;
typedef unsigned long long ull;
typedef long long ll;

#define MODULO 1000000007

int t;
int b, p, f;
int h, c;

int main() {
    cin >> t;
    for(int tc = 0; tc < t; ++tc){
        cin >> b >> p >> f;
        cin >> h >> c;

        b /= 2;
        if(h < c){
            swap(h, c);
            swap(p, f);
        }

        int res = 0;

        int cnt = min(b, p);
        b -= cnt, p -= cnt;
        res += h * cnt; 
        
        cnt = min(b, f);
        b -= cnt, f -= cnt;
        res += c * cnt; 
            
        cout << res << endl;
    }
    return 0;
}