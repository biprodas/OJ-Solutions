#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mx 100005

struct info {
    i64 prop, sum;
} tree[mx*3];

void update(int node, int b, int e, int i, int j, i64 x){
    if (i > e || j < b)
        return;
    if (b >= i && e <= j){ //relevant node
        tree[node].sum += ((e - b + 1) * x); //number of node in this range is e-b+1
        tree[node].prop += x;
        return;
    }
    int left = node << 1; // left= node*2
    int right = left + 1;
    int mid = (b + e) >> 1; //mid= (b+e)/2
    update(left, b, mid, i, j, x);
    update(right, mid + 1, e, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
}

i64 query(int node, int b, int e, int i, int j, i64 carry){
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    int left = node << 1;
    int right = left + 1;
    int mid = (b + e) >> 1;

    i64 p1 = query(left, b, mid, i, j, carry + tree[node].prop);
    i64 p2 = query(right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main(){
    int t, n, c;
    cin>>t;
    while(t--){
        memset(tree, 0, sizeof(tree)); //clear the tree
        scanf("%d%d",&n,&c);
        while(c--){
            int x, p, q, v;
            scanf("%d",&x);
            if(x){
                scanf("%d%d",&p,&q);
                i64 ans= query(1,0,n-1,p-1,q-1,0);
                printf("%lld\n",ans);
            }
            else{
                scanf("%d%d%d",&p,&q,&v);
                update(1,0,n-1,p-1,q-1,v);
            }
        }
    }
    return 0;
}

//problem-Link: http://www.spoj.com/problems/HORRIBLE/