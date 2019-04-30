
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
typedef struct data
 {
 char name[10];
 int rollno;
 char div;
 char address[100];
 }Rec;
 class student
{

 Rec Records;
 public:
  void Create();
  void Display();
  int Search();
  void deletion();
};

void student::Create()
{
 char ch='y';
 ofstream seqfile;
 seqfile.open("stud.DAT",ios::out|ios::binary);
 do
 {
  cout<<"\n Enter Name: ";
  cin>>Records.name;
  cout<<"\n Enter roll no: ";
  cin>>Records.rollno;
  cout<<"\n Enter division";
  cin>>Records.div;
  cout<<"\n Enter ADDRESS: ";
  cin>>Records.address;
  seqfile.write((char*)&Records,sizeof(Records));
  cout<<"\nDo you want to add more records?";
  cin>>ch;
  }while(ch=='y');
  seqfile.close();
}
void student::Display()
{
 ifstream seqfile;
 seqfile.open("stud.DAT",ios::in|ios::binary);
 seqfile.seekg(0,ios::beg);
 cout<<"\n The Contents of file are ..."<<endl;
 while(seqfile.read((char *)&Records,sizeof(Records)))
 {
   if(Records.rollno!=-1)
   {
   cout<<"\nName: "<<Records.name<<flush;
   cout<<"\nRoll No: "<<Records.rollno;
   cout<<"\nDivision :"<<Records.div;
   cout<<"\nAddress: "<<Records.address;
   cout<<"\n";
    }
 }
 seqfile.close();
}
int student::Search()
{
 fstream seqfile;
 int id,pos,offset;
 cout<<"\n Enter the roll no for searching the record ";
 cin>>id;
 seqfile.open("stud.DAT",ios::in|ios::binary);
 pos=-1;
 seqfile.seekg(0,ios::beg);
 int i=0;
 while(seqfile.read((char *)&Records,sizeof(Records)))
 {
  if(id==Records.rollno)
  {
   pos=i;
   break;
  }
  i++;
 }
  seqfile.close();
  return pos;
}
void student::deletion()
{
    int id,pos;
    cout<<"For deletion"<<endl;
    fstream seqfile;
    pos=Search();
    seqfile.open("stud.DAT",ios::in|ios::binary|ios::out);
    seqfile.seekg(0,ios::beg);
    if(pos==-1)
    {
    cout<<"\n Record is not present in the file";
    return;
    }
  int offset=pos*sizeof(Records);
  seqfile.seekp(offset);
  strcpy(Records.name,"");
  Records.rollno=-1;
  Records.div=-1;
  strcpy(Records.address,"");
  seqfile.write((char *)&Records,sizeof(Records));
  seqfile.seekg(0);
  seqfile.close();

}
int main()
{
student e;
 char ans='y';
 int choice,key;
 int h=0;
 do
 {
     cout<<"1.Create"<<endl;
     cout<<"2.Display"<<endl;
     cout<<"3.Search"<<endl;
     cout<<"4.Delete"<<endl;
     cout<<"Enter your choice"<<endl;
     cin>>choice;
         switch(choice)
         {
         case 1:
            e.Create();
            break;
         case 2:
           e.Display();
           break;
         case 3:
            h=e.Search();
            if(h<0)
            cout<<"\n Student not present in file"<<endl;
            else
            cout<<"\n Student is present in file"<<endl;
             break;
         case 4:
            e.deletion();
            break;
         }
         cout<<"Do you want to continue"<<endl;
         cin>>ans;
 }while (ans=='y');
return 0;
}
