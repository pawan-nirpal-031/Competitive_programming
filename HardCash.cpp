#include <iostream>
using namespace std;
typedef long long int ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        ll s =0;
        for(ll i =0;i<n;i++){
            cin>>a[i];
            s+=(a[i]%k);
        }
        cout<<s%k<<'\n';
    }
    return 0;
}