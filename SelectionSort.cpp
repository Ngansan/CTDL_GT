#include <iostream>

using namespace std;

// ham sap xep
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
/* // ham sap xep tang dan
void SelectionSort(int a[], int N)
{
    int min;
    for(int i=0; i<N-1; i++)
    {
        min = i;         // i= 
        for(int j=i+1; j<N; j++)
        {                        //  0 1  2 3  4 5
            if(a[j] < a[min])    // 12 7 45 8 41 5 
            {
                min = j;             
            }                         // i= min = 0 -> a[1]=7 < a[0]= 12 -> min=1					  
 
        }
         swap(a[min], a[i]); 
    }

}

*/
// ham sap xep giam dan
void SelectionSort(int a[], int N)
{
	int max;
	for(int i=0; i<N-1; i++)
	{
		max = i;
		for(int j=i+1; j<N; j++)
		{
			if(a[j]>a[max])
			{
				max = j;
			}
		}
		swap(a[max], a[i]);
	}
}

void PrintArr(int a[], int N)
{
    for(int i=0; i<N; i++)
    {
        cout << a[i] << " ";
    }

}
int main()
{
    int N;
    int a[100];
    cout << "Nhap so phan tu: ";
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> a[i];
    }

   SelectionSort(a,N);
   PrintArr(a,N);
   system("pause");
    return 0;
}
