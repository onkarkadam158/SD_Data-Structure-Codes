#include<iostream>
#define MAX 999;
using namespace std;

class kruskal
{
private:
    struct node
    {
        int v1,v2,cost;
    }G[20];
public:
    int edges,vertices;
    void create();
    void mincost();
    void input();
    int minimum(int);
};
int find (int v2,int parent[])
{
    while(parent[v2]!=v2)
    {
        v2=parent[v2];
    }
}
void uni(int i,int j,int parent[])
{
    if(i<j)
        parent[j]=i;
    else
        parent[i]=j;
}
void kruskal::input()
{
    cout<<"enter number of companies"<<endl;
    cin>>vertices;
    cout<<"enter number of connection"<<endl;
    cin>>edges;
}
void kruskal::create()
{
    cout<<"\n enter edges in v1-v2 form and corresponding cost"<<endl;
    for(int k=0;k<edges;k++)
    {
      cin>>G[k].v1>>G[k].v2>>G[k].cost;
    }
}
int kruskal::minimum(int n)
{
    int i,small,pos;
    small=MAX;
    pos=-1;
    for(i=0;i<n;i++)
    {
        if(G[i].cost<small)
        {
            small=G[i].cost;
            pos=i;
        }
    }
    return pos;
}
void kruskal::mincost()
{
    int count,k,v1,v2,i,j,tree[10][10],pos,parent[10];
    int sum=0;
    count=0;
    k=0;
    for(i=0;i<vertices;i++)
        parent[i]=i;
    while(count!=vertices-1)
    {
    pos=minimum(edges);
    if(pos==-1)
        break;
    v1=G[pos].v1;
    v2=G[pos].v2;
    i=find(v1,parent);
    j=find(v2,parent);
    if(i!=j)
        {
        tree[k][0]=v1;
        tree[k][1]=v2;
        k++;
        count++;
        sum=sum+G[pos].cost;
        uni(i,j,parent);
        }
    G[pos].cost=MAX;
    }
    if(count==vertices-1)
    {
        cout<<"spanning tree is"<<endl;
        for(i=0;i<vertices-1;i++)
        {
            cout<<tree[i][0]<<"-"<<tree[i][1]<<endl;
        }
        cout<<"cost required to set cables"<<sum<<endl;
    }
    else
    {
        cout<<"connection can't be set up"<<endl;
    }
}
int main()
{
    kruskal k;
    k.input();
    k.create();
    k.mincost();
}
