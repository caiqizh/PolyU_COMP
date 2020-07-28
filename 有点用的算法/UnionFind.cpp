#include <iostream>

// O(m logn) 路径压缩
namespace UnionFind{
    const int MAXN = 1e6+5;
    int fa[MAXN];
    
    void build(int n){
        for(int i =0;i<n;i++)fa[i]=i;
    }

    int find(int k){
        if(fa[k]==k)return k;
        fa[k] = find(fa[k]);
        return fa[k];
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b)
            fa[a] = b;
    }

}


// 按秩合并
namespace rnkUnionFind{
    const int MAXN = 1e6+5;
    int fa[MAXN];
    int rnk[MAXN];
    
    void build(int n){
        for(int i =0;i<n;i++)fa[i]=i,rnk[i]=1;

    }

    int find(int k){
        if(fa[k]!=k)
            fa[k] = find(fa[k]);
        return fa[k];
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            if(rnk[a]>rnk[b])
                std::swap(a,b);
            fa[a] = b;
            rnk[b]+=rnk[a];
        }
    }

}


int main(){
    // init
    UnionFind::build(10);
    // check father
    for(int i = 0 ;i<10;i++){
        std::cout<<UnionFind::find(i)<<" ";
    }
    std::cout<<std::endl;
    // merge two union
    UnionFind::merge(0,1);
    UnionFind::merge(3,4);
    UnionFind::merge(7,8);
    UnionFind::merge(0,3);
    // check new union
    for(int i = 0 ;i<10;i++){
        std::cout<<UnionFind::find(i)<<" ";
    }
    std::cout<<std::endl;


    // init
    rnkUnionFind::build(10);
    // check father
    for(int i = 0 ;i<10;i++){
        std::cout<<rnkUnionFind::find(i)<<" ";
    }
    std::cout<<std::endl;
    // merge two union
    rnkUnionFind::merge(0,1);
    rnkUnionFind::merge(3,4);
    rnkUnionFind::merge(7,8);
    rnkUnionFind::merge(0,3);
    // check new union
    for(int i = 0 ;i<10;i++){
        std::cout<<rnkUnionFind::find(i)<<" ";
    }
    std::cout<<std::endl;
}
