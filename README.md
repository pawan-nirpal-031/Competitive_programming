# Competitive_programming

https://www.codechef.com/FEB20B/problems/CASH (nice one)

https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm  (permutaion genrator)

https://www.hackerrank.com/challenges/coin-change/problem

https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/tutorial/

Important Que : Connected cells in a grid : https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem



#define N 100
#define M 100
char a[N][M];
bool vis[N][M];
int g_c =0;
int c =0;

void dfs(char a[][N],bool vis[][N],int i ,int j){
    if(vis[i][j]==0){
        vis[i][j]=1;
        c+=1;
        if((int)(a[i][j])==(1+(int)(a[i][j+1]))){
            dfs(a,vis,i,j+1);
        }
        if((int)(a[i][j])==(1+(int)(a[i+1][j+1]))){
            dfs(a,vis,i+1,j+1);
        }
        if((int)(a[i][j])==(1+(int)(a[i+1][j]))){
            dfs(a,vis,i+1,j);
        }
        if((int)(a[i][j])==(1+(int)(a[i+1][j-1]))){
            dfs(a,vis,i+1,j-1);
        }
        if((int)(a[i][j])==(1+(int)(a[i][j-1]))){
            dfs(a,vis,i,j-1);
        }
        if((int)(a[i][j])==(1+(int)(a[i-1][j-1]))){
            dfs(a,vis,i-1,j-1);
        }
        if((int)(a[i][j])==(1+(int)(a[i-1][j]))){
            dfs(a,vis,i-1,j);
        }
        if((int)(a[i][j])==(1+(int)(a[i-1][j+1]))){
            dfs(a,vis,i-1,j+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    for(int i =0;i<=n;i++){
        for(int j =0;j<=m;j++){
            vis[i][j]=0;
        }
    }
    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            if(vis[i][j]==0 && a[i][j]=='A'){
                c=0;
                dfs(a,vis,i,j);
                if(c>g_c){
                    g_c = c;
                }
            }
        }
    }
    cout<<g_c;
    return 0;
}


