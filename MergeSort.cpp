#include <iostream>

using namespace std;

void Input(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
}

void Merge(int a[], int l, int m, int r)
{
	int n1 = m - l +1;
	int n2 = r - m;
	
	int L[n1], R[n2];
	
	for(int i = 0; i < n1; i++)
		L[i] = a[l + i];
	for(int j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];
		
	int i = 0;
	int j = 0;
	int k = l;
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	
	while(j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
		
}






void MergeSort(int a[], int l, int r)
{
	if(l<r)
	{
		int q = (l+r)/2;
		MergeSort(a,l,q);
		MergeSort(a,q+1,r);
		Merge(a,l,q,r);
	}
}

void PrintArr(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
		
	}
	cout << "\n";
}

int main()
{
//	int a[] = {12, 11, 13, 5, 6, 7};
//	int a_size = sizeof(a) / sizeof(a[0]);

	int a[100];
	int n;
	cin >> n;
	
	MergeSort(a,0,n-1);
	
	cout << "\tMang sau khi da sap xep\n";
	PrintArr(a,n);
	
    
    return 0;
}



