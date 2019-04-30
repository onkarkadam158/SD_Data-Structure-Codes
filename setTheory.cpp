#include<iostream>
using namespace std;


void create(int *s1,int *s2);
void display(int *s);
void intersection(int *s1,int *s2);
void insert(int *s);
void remove(int *s);
void contain(int *s);
void set_size(int *s);
void intersection(int *s1,int *s2);
int linear(int *s,int e);
#define SIZE 20


int main()
{
	int s1[SIZE], s2[SIZE];
	int element,ch,c,i,r;

	do{
		cout<<"\n***MENU***";
		cout<<"\n1:CREATE \n2:ADD ELEMENT \n3:REMOVE ELEMENT \n4:CONTAIN ELEMENT \n5:SIZE OF ELEMENT \n6:INTERSECTION";
		cout<<"\n Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:create(s1,s2);
					break;
			case 2: cout<<"\n IN WHICH SET YOU WANT TO INSERT ELEMENT(1/2):";
					cin>>c;
					if(c==1)
						insert(s1);
					else
						insert(s2);
					break;
			case 3:cout<<"\n IN WHICH SET YOU WANT TO REMOVE ELEMENT(1/2):";
					cin>>c;
					if(c==1)
						remove(s1);
					else
						remove(s2);

					break;
			case 4:cout<<"\n IN WHICH SET YOU WANT TO CHECK THE ELEMENT(1/2):";
					cin>>c;
					if(c==1)
						contain(s1);
					else
						contain(s2);
					break;
			case 5:cout<<"\n IN WHICH SET YOU WANT TO CHECK THE SIZE(1/2):";
					cin>>c;
					if(c==1)
						set_size(s1);
					else
						set_size(s2);

					break;
			case 6:intersection(s1,s2);
			default: cout<<"\n WRONG CHOICE!!!";
		}

	}while(ch<6);
	return 0;
}
int linear(int *s, int e)
{
	int f;
	for(int i=1;i<=s[0];i++)
	{
		if(s[i]==e)
		{
			f=1;
			return f;
		}
	}
	if(f==0)
		return f;

}
void intersection(int *s1,int *s2)
{
	int s3[SIZE],i,j=1;
	for( i=1;i<=s1[0];i++)
	{
	if(linear(s2,s1[i])==1)
	{
		s3[j]=s1[i];
		}
	}
}
void set_size(int *s)
{
	cout<<"\n SIZE OF SET:"<<s[0];
}
void contain(int *s)
{
	int element;
	cout<<"\n Enter element to check:";
	cin>>element;
	if(linear(s,element)==1)
		cout<<"\n ELEMENT PRESENT!";
	else
		cout<<"\n ELEMENT NOT PRESENT!!!";


}
void remove(int *s)
{
	int element,i,j;
	cout<<"\n Enter element to remove:";
	cin>>element;
	for(i=1;i<=s[0];i++)
	{
		if(s[i]==element)
		{
			for(int j=i;j<=s[0];j++)
				{
					s[j]=s[j+1];
				}
				s[0]-=1;
				cout<<"\n SIZE:"<<s[0]<<"\n";
				display(s);
				return;
		}
	}
	cout<<"\n ELEMENT NOT FOUND!!!";
}

void insert(int *s)
{
	int element;
	cout<<"\n Enter the element:";
	cin>>element;
	int size=s[0];
	s[++size]=element;
	s[0]=size;
	display(s);
}

void create(int *s1,int *s2)
{
	int n,i;
	cout<<"\n enter size of set1:";
	cin>>n;
	s1[0]=n;
	cout<<"\n enter elements:";
	for(i=1;i<=n;i++)
	{
	cin>>s1[i];
	}
	cout<<"\n ELEMENTS OF SET1:";
	display(s1);
	cout<<"\n enter size of set2:";
	cin>>n;
	s2[0]=n;
	cout<<"\n enter elements:";
	for(i=1;i<=n;i++)
	{
	cin>>s2[i];
	}
	cout<<"\n ELEMENTS OF SET2:";
	display(s2);

}
void display(int *s)
{
	int i;
	for(i=1;i<=s[0];i++)
	{
		cout<<" "<<s[i];
	}
}
