#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int cap, n;
int value[501], wt[501];
map<pii, int> dp;

int call(int i, int w){
    if(i==n) return 0;
    if(dp.find(pii(i, w))!=dp.end()) //use find() rather direct access
        return dp[pii(i,w)];
    int ret1=0, ret2=0;
    if(w+wt[i]<=cap)
        ret1= value[i]+call(i+1,w+wt[i]);
    ret2= call(i+1,w);
    return dp[pii(i,w)]=max(ret1,ret2);
}

int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&cap,&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&value[i],&wt[i]);
    }
    printf("%d\n",call(0,0));
    return 0;
}
