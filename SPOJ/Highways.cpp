// Problem: Highways
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/HIGHWAYS/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

bool multicases_=true;
#define int long long



struct node{
	int idx,cost;
};
struct cmp{
	bool operator()(node&a,node&b){
		return a.cost>b.cost;//smaller comes firstly
	}
};//fix : don't forget ;

vector<vector<node>>adj;
vector<bool>vis;
int n,m;

int dijkstra(int src,int target){
	
	priority_queue<node,vector<node>,cmp>pq;
	
	pq.push({src,0});
	
	while(!pq.empty()){
		
		node u=pq.top();
		pq.pop();
		
		if(u.idx==target)return u.cost;
		
		if(vis[u.idx]) continue;
		
		vis[u.idx]=true;
		
		for(auto&v:adj[u.idx]){	//fix : don't forget .idx (inside the [])
			if(!vis[v.idx]){	//fix : don't forget .idx (same thing ^)
				pq.push({v.idx,u.cost+v.cost});
				////////fix   ^   is , not +
			}
		}
		
	}
	
	
	return -1;
}

void solve(int tc){
	// //dbg:
	 // cerr<<"at the test case no."<<tc<<" : \n";
	
	int src,target;
	cin>>n>>m>>src>>target;
	
	adj.assign(n+1,{});
	vis.assign(n+1,false);
	
	//or efficiently loop and clear edges till the nth node
	
	for(int i = 1 ,u,v,w; i<=m ; i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		//undirected :
		adj[v].push_back({u,w});
	}
	int ans=dijkstra(src,target);
	if (ans==-1)cout<<"NONE"<<'\n';/////don't forget the endline here also
	else cout<<ans<<'\n';
	
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	//pre computations:
	
	
	int tc=1;
	if(multicases_)cin>>tc;
	int total_tcs=tc;
	while(tc--){
		solve(total_tcs-tc);
	}
	return 0;
}
