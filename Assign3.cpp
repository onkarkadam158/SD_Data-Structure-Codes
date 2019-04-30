#include<iostream>
#define MAX 10
using namespace std;
class airport
{
	string city[MAX];
	int distance[10][10];
public :
    int n;
    airport();
    void read_city();
    void show_graph();
};
airport::airport()
{
	n=0;
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
			distance[i][j]=0;
	}
}
void airport::read_city()
{
	int k;
	cout<<"\nEnter the no. of cities: " ;
	cin>>n;
	cout<<"Enter city name:\n";
	for(int k=0;k<n;k++)
	{
	    cout<<k+1<<"] ";
		cin>>city[k];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1 ; j<n ; j++)
		{
			cout<<"\nEnter Distance between "<<city[i]<<" to "<<city[j]<<": ";
			cin>>distance[i][j];
			distance[j][i]=distance[i][j];
		}
	}
}
void airport::show_graph()
{
    cout<<"\t";
    for(int k=0;k<n;k++)
    {
        cout<<city[k]<<"\t";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<city[i]<<"\t";
        for(int j=0;j<n;j++)
        {
            cout<<distance[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int main()
{
	airport obj;
	obj.read_city();
	obj.show_graph();
}
