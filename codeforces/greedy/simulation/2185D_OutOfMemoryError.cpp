#include<bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

int32_t main(){
    FIO;
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int tt=1;
    cin>>tt;//needed?
    while(tt--){
        
        int n,m,h;cin>>n>>m>>h;// why int worked but ll didn't work?!! mmmmm..............
        vector<int>a(n);  //,b(m),c(m);
        for(auto&x:a)cin>>x;
        vector<int>orig=a;
        //save last updates after reseting
        
        
        queue<pair<int,int>>q;//we want first input  // we want first in first out (first updatings then last)
        for(int i = 0 ; i < m ; i++){
            int x,y;cin>>x>>y,x--;// fix : y-- is not right because only decreasing the index is the right thing
            // fix : check current value also not only original
            if (a[x]+y<=h)
            {
                q.push(pair<int,int>{x,y}); // same as : q.push({x,y});
                a[x]+=y;
            }
            else 
            {
                //idea remove if not valid but firstly reverse operations
                // actually this is O(n) not nSquared because if you moved n then removed n it is O(2n)
                while(!q.empty()){
                    int idx=q.front().first;
                    int change=q.front().second;
                    a[idx]-=change;
                    q.pop();//fix : forgetting to remove ,, infinite loop
                }
                // now i think this clearance is not necessary
                // queue<pair<int,int>>().swap(q);// can be : q = queue<pair<int,int>>();
            }
            
            // //dbg:
            // cerr<<x<<' '<<y<<endl;
            // for(auto&x:a)cerr<<x<<' ';
            // cerr<<endl;
            
        }
        
        //actually also you can use a stack to store because you always incrementing so order doesn't matter
        
        for(auto&x:a)cout<<x<<' ';
        cout<<'\n';
    }
    return 0;
}
