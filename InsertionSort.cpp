 #include <iostream>

using namespace std;

//void InsertionSort(int a[], int N)
//{
//    int i, key, j;
//    for(int i=1; i<N; i++)
//    {
//        key = a[i];
//        j = i - 1;
//
//        while(j>=0&&a[j]>key)
//        {
//            a[j+1] = a[j];
//            j--;
//        }
//        a[j+1] = key;
//    }
//
//}
// ham sap xep giam dan
//void InsertionSort(int a[], int N)
//{
//    int i, key, j;
//    for(int i=1; i<N; i++)
//    {
//        key = a[i];
//        j = i - 1;
//
//        while(j>=0&&a[j]<key)
//        {
//            a[j+1] = a[j];
//            j--;
//        }
//        a[j+1] = key;
//    }
//
//}


void InsertionSort(int a[], int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key = a[i];
		j=i-1;
		while(j>=0;&&a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

void PrintArr(int a[], int N)
{
    for(int i=0; i<N; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}


int main()
{
    int a[100];
    int N;
    cout << "Nhap so phan tu: ";
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> a[i];
    }

    InsertionSort(a,N);
    PrintArr(a,N);
    system("pause");
    return 0;
}
