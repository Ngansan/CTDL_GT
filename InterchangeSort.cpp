#include <iostream>

using namespace std;

// y tuong: i=0
// j = i +1 (j>i)
//while(j<n)-> if(a[j]<a[i])-> j++-> quay lai buoc 3
// i++, if(i<n-1)-> lap lai buoc 2, nguoc lai-> dung


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void InterchangeSort(int a[], int N)
{
    for(int i=0; i<N-1; i++ )
    {
        for(int j=i+1; j<N; j++)
        {
            if(a[j]<a[i]) // sx tang dan, neu sx giam dan thi a[j]>a[i]
            {
                swap(a[i],a[j]);
            }
        }
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
    cout << "So phan tu: ";
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> a[i];
    }
    InterchangeSort(a,N);
    PrintArr(a,N);

    system("pause");

    return 0;
}
