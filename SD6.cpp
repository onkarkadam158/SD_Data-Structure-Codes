#include <iostream>

using namespace std;
void max_heapify(int *arr, int i, int n)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    
    if(l<n && arr[l]> arr[largest])
        largest=l;
        
        
       
    if(r<n && arr[r]> arr[largest])
        largest=r;  
    
    if(largest!=i)
    {
    	swap(arr[i],arr[largest]);
    	
    	max_heapify(arr,largest,n);
    	
	}
       
    
}

void min_heapify(int *arr, int i, int n)
{
    int minimum=i;
    int l=2*i+1;
    int r=2*i+2;
    
    if(l<n && arr[l]< arr[minimum])
        minimum=l;
        
        
       
    if(r<n && arr[r]< arr[minimum])
        minimum=r;  
    
    if(minimum!=i)
    {
    	swap(arr[i],arr[minimum]);
    	
    	min_heapify(arr,minimum,n);
    	
	}
       
       
    
    
    
}



void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	
	
	
}

void build_minheap(int *a,int n)
{
    int i;
    for(i = n/2-1; i >= 0; i--)
    {
        min_heapify(a,i,n);
    }
   
}


void build_maxheap(int *a,int n)
{
    int i;
    for(i = n/2-1; i >= 0; i--)
    {
        max_heapify(a,i,n);
    }
  
   
}


void sort( int * a, int n)
{
	int size= n;
	
	for(int i=n-1;i>=0;i--)
	{
		int last= a[i];
	int	first=a[0];
		a[i]=a[0];
		a[0]=last;
		
		size--;
		max_heapify(a,0,i);
		
	}

	
}
int main()
{
    int n, i, x;
    cout<<"enter no of students in class\n";
    cin>>n;
    int a[20];
    int b[20];
    for (i = 0; i < n; i++)
    {
        cout<<"enter marks obtained by students"<<(i)<<endl;
        cin>>a[i];
        b[i]=a[i];
    }
    build_maxheap(a,n);
    cout<<"Max Heap\n";
    
    for (i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }
    
   cout<<"the maximun marks obtained by students "<<a[0]<<endl;
    
    cout<<"min heap";
    build_minheap(b,n);
    for (i = 0; i < n; i++)
    {
        cout<<b[i]<<endl;
    }
    cout<<"the minimum marks obtained by students "<<b[0]<<endl;

}

/*enter no of students in class
5
enter marks obtained by students0
34
enter marks obtained by students1
67
enter marks obtained by students2
4
enter marks obtained by students3
12
enter marks obtained by students4
56
Max Heap
67




56
4
12
34
the maximun marks obtained by students 67
min heap4
12
34
67
56
the minimum marks obtained by students 4

--------------------------------
Process exited after 8.014 seconds with return value 0
Press any key to continue . . .
*/



