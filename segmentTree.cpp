#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<int>a;
struct tree
{
    int sum;
    int L,R;
    int lazy;
}tree[4*N];
void push_down(int i)
{
    if(tree[i].lazy!=0&&tree[i].L!=tree[i].R)
    {
        tree[2*i].lazy+=tree[i].lazy;
        tree[2*i].sum+=(tree[i].lazy*(tree[2*i].R-tree[2*i].L+1));
        tree[2*i+1].lazy+=tree[i].lazy;
        tree[2*i+1].sum+=(tree[i].lazy*(tree[2*i+1].R-tree[2*i+1].L+1));
        tree[i].lazy=0;
    }
}
void build(int L,int R,int i)
{
    tree[i].L=L;
    tree[i].R=R;
    tree[i].lazy=0;
    if(L==R)
    {
        tree[i].sum=a[L];
        return;
    }
    build(L,(L+R)/2,2*i);
    build((L+R)/2+1,R,2*i+1);
    tree[i].sum=tree[2*i].sum+tree[2*i+1].sum;
}
int query(int L,int R,int i)
{
    if(L<=tree[i].L&&tree[i].R<=R)
    {
        return tree[i].sum;
    }
    if(R<tree[i].L||tree[i].R<L)
    {
        return 0;
    }
    push_down(i);
    return query(L,R,2*i)+query(L,R,2*i+1);
}
void add(int L,int R,int pos,int i)
{
    if(L<=tree[i].L&&tree[i].R<=R)
    {
       tree[i].lazy+=pos;
       tree[i].sum+=pos*(tree[i].R-tree[i].L+1);
       return;
    }
    if(R<tree[i].L||tree[i].R<L)
    {
        return;
    }
    add(L,R,pos,2*i);
    add(L,R,pos,2*i+1);
    tree[i].sum=tree[2*i].sum+tree[2*i+1].sum;
    
}
/*
最基础版线段树：有的单点修改和区间求和的功能

区间之间的三种关系：相交，属于，相离

父子关系规则：父：i, 左儿子：2*i 右儿子：2*i+1

建树：确定每个节点对应的区间

查询：把所有被包裹在目标区间内的规则区间求和

修改：单点修改，修改后回溯，修改与该点相关的所有区间

思考：若要区间修改的话，就要修改到特定叶子节点，这样可能会很复杂
不如像查询一样，只修改到被包裹在目标区间内的规则区间，然后在这些规则区间的节点上留一个标记。
然后回溯，使规则区间上方的节点的sum正确。

然后在查询的时候，查到哪，把标记转移到哪，并修改转移的节点的sum.a

思考：懒标记如何优化的；避免了查询前的反复修改，使修改恰好使查询能够完成，不必修改到更精细的单位，除非需要他们。

思考：如果要区间乘法修改和加减修改同时进行，那么要设置两种标记，在同一add函数中运行。

    










*/