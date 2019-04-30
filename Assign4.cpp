#include <iostream>
#include<climits>
using namespace std;

int findMinVertex(int *weights,bool* visited,int n)
{
    int minVertex=-1,i;
    for(i=0;i<n;i++)
    {
        if(!visited[i]&&(minVertex==-1 || weights[i]<weights[minVertex]))
        {
            minVertex=i;
        }
    }
    return minVertex;
}
void prims(int **edges,int n)
{
    int *weights=new int[n];
    int *parent=new int[n];
    int i,j;
    bool *visited=new bool[n];

    for(i=0;i<n;i++)
    {
        weights[i]=INT_MAX;
        visited[i]=false;
    }

    weights[0]=0;
    parent[0]=-1;

    for(i=0;i<n-1;i++)
    {
        int minVertex=findMinVertex(weights,visited,n);
        visited[minVertex]=true;
        for(j=0;j<n;j++)
        {
            if(edges[minVertex][j]!=0 && !visited[j])
            {
                if(edges[minVertex][j]<weights[j])
                {
                    weights[j]=edges[minVertex][j];
                    parent[j]=minVertex;
                }
            }
        }
    }
    cout<<"source"<<"\t"<<"destination"<<"\t"<<"weights"<<endl;
    for(i=1;i<n;i++)
    {
        if(parent[i]<i)
        cout<<parent[i]<<"\t"<<i<<"\t"<<weights[i]<<endl;
        else
           cout<<i<<"\t"<<parent[i]<<"\t"<<weights[i]<<endl;
    }
}
int main()
{
    int i,j,e,n;
    cout<<"Enter no. of vertices \n";
    cin>>n;
    cout<<"Enter no. of edges \n";
    cin>>e;
    int** edges=new int*[n];
    for(int i=0;i<n;i++)
        edges[i]=new int[n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        edges[i][j]=0;
    for(i=0;i<e;i++)
    {
        int s,d,weight;
        cout<<"enter source vertex \n";
        cin>>s;
        cout<<"Enter destination vertex \n";
        cin>>d;
        cout<<"enter the weight \n";
        cin>>weight;
        edges[d][s]=weight;
        edges[s][d]=weight;
    }
    prims(edges,n);
    return 0;
}
