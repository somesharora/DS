#include<iostream>
using namespace std;
void maxheapify(int a[],int i,int n)
{
	int j,temp;
	temp=a[i];
	j=2*i;
	while(j<=n)
	{
		if((j<n) && (a[j]<a[j+1]))
		j=j+1;
		if(temp>a[j])
		break;
		else if(temp<a[j])
		{
			a[j/2]=a[j];
			j=2*j;
			
		}
	}
	a[j/2]=temp;
	return;
}
void heapsort(int a[],int n)
{
	int i,temp;
	for(i=n;i>=2;i--)
	{
		temp=a[i];
		a[i]=a[1];
		a[1]=temp;
		maxheapify(a,1,i-1);
	}
}
void buildmaxheap(int a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
    maxheapify(a,i,n);
}

int main()
{
	int n,i;
	cout<<"enter no of elements";
	cin>>n;
	int a[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	buildmaxheap(a,n);
	heapsort(a,n);
	
	cout<<"the answer is";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
}
