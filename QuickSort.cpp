#include <iostream>

using namespace std;

void Input(int a[], int x)
{
	for(int i=0; i<x; i++)
	{
		cin >> a[i];
	}
}
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

//int partition(int a[], int low, int high)
//{
//	int pivot = a[high];
//	int left = low;
//	int right = high - 1;
//	while(true)
//	{
//		while(left<=right && a[left] < pivot) left++;
//		while(right>=left && a[right] > pivot) right--;
//		if(left >= right) break;
//		swap(a[left],a[right]);
//		left++;
//		right--;
//	}
//	swap(a[left],a[high]);
//	return left;
//}
// C1
//void QuickSort(int a[], int low, int high)
//{
//	if(low < high)
//	{
//		int pi = partition(a,low,high);
//		QuickSort(a,low,pi-1);
//		QuickSort(a,pi+1,high);
//	}
//}

//C2
void QuickSort(int a[], int left, int right)
{
	int i,j,x;
	x=a[(left+right)/2];
	i=left;
	j=right;
	while(i<j)
	{
		while(a[i]<x) i++;
		while(a[j]>x) j--;
		if(i<=j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(left<j) QuickSort(a,left,j);
	if(i<right) QuickSort(a,i,right);
}



void Print(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout << a[i];
		cout << "\n";
	}
}
int main()
{
	int a[100];
//	int a[] ={1,78,98,45,12,4};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "Nhap vao so phan tu trong mang: ";
	cin >> n;
	Input(a,n);

	QuickSort(a,0,n-1);
	cout << "mang sau khi da sap xep: " << endl;
	Print(a,n);

    return 0;
}
