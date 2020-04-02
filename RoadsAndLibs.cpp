#include <iostream>
#include <vector>
typedef long long int ll;
using namespace std;
ll c=0;
void dfs(vector<long>g[],vector<bool>&visit,long u){
	if(visit[u]==0){
		visit[u]=1;
		c+=1;
		for(long i =0;i<g[u].size();i++){
			if(visit[g[u][i]]==0)
			  dfs(g,visit,g[u][i]);
		}
	}
}
int main(){
	long q;
	cin>>q;
	while(q--){
		long n,m,l,r;
		cin>>n>>m>>l>>r;
		vector<long>g[n+1];
		for(long i=0;i<m;i++){
			ll x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(l<=r || m==0){
			cout<<n*l<<'\n';
			continue;
		}
	long ans =0;
		vector<bool>visit(n+1,0);
		for(long i =1;i<=n;i++){
			c=0;
			if(visit[i]==0){
				dfs(g,visit,i);
				ans+=l+(c-1)*r;
					
			}
			
		}
		cout<<ans<<'\n';
		
	}
	return 0;
}