#include<iostream>
using namespace std;


class hashTable
{

public:
	int data[10],occ[10];
	int key,index=0,index2=0,n;

hashTable()
{

	for(int i=0;i<10;i++)
	{
		occ[i]=0;	
		data[i]=0;
	}


}

void insert();
void calIndex();
void display();
void search();
void delet();


};




void hashTable::insert()
{	
	
	cout<<"\n\n\tHow many Keys u Want To Enter?? ";
	cin>>n;

for(int i=0;i<n;i++)
{
	cout<<"\n\n\tEnter Key Value";
	cin>>key;

	index = (key % 10);
	calIndex();
}

}




void hashTable::calIndex()
{

	if(occ[index]==0)
	{
	data[index] = key;
	occ[index] = 1;
	}
	else if(occ[index] == 1)
	{
	for(int j=0;j<10;j++)
	{
		index2 = 7 - (key % 7);
		
		index = (index + j*index2)%10;
		
		if(occ[index] == 0)	
			break;
	}
	data[index] = key;
	occ[index] = 1;

	}
}




void hashTable::display()
{
	cout<<"\t\t\tIndex "<<"\t\tKey\n";
	for(int i=0;i<10;i++)
	cout<<"\t\t\t"<<i<<"\t\t"<<data[i]<<"\n";

}

/*
void hashTable::delet()
{
	int del;
	cout<<"\n\n\tEnter Key to be Deleted ";
	cin>>del;

	for(int i=0;i<10;i++)
	{
	if(data[i]==del)
	{
		cout<<"\n\t\t"<<del<<" Deleted from Index "<<i<<"\n";
		data[i]=0;
		occ[i]=0;	
	}
	}
	

}
*/

void hashTable::search()
{	
	int search;
	cout<<"\n\n\tEnter Key to be Searched ";
	cin>>search;
	
	for(int i=0;i<10;i++)
	{
	if(data[i]==search)
	{
		cout<<"\n\t\t"<<search<<" Found at Index "<<i<<"\n";	
	}
	}
}



int main()
{
	int ch;
	hashTable h1;

	do{

	cout<<"Enter Ur Choice\n1.Insert\n2.Display\n3.Search\n0.Exit\n";
	cin>>ch;

	switch(ch)
	{
		case 1: h1.insert();
				break;
		case 2: h1.display();
				break;
		case 3: h1.search();
				break;
		
	}
}while(ch!=0);

}
/*Enter Ur Choice
1.Insert
2.Display
3.Search
0.Exit
1


        How many Keys u Want To Enter?? 5


        Enter Key Value11


        Enter Key Value23


        Enter Key Value21


        Enter Key Value45


        Enter Key Value67
Enter Ur Choice
1.Insert
2.Display
3.Search
0.Exit
2
                        Index           Key
                        0               0
                        1               11
                        2               0
                        3               23
                        4               0
                        5               45
                        6               0
                        7               67
                        8               21
                        9               0
Enter Ur Choice
1.Insert
2.Display
3.Search
0.Exit
3


        Enter Key to be Searched 67

                67 Found at Index 7
Enter Ur Choice
1.Insert
2.Display
3.Search
0.Exit*/




