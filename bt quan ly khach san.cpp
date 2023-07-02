#include <iostream>
#include <cmath>
#include <algorithm>
#include <math.h>
#include<stdio.h>
#include<conio.h>

using namespace std;


struct Hotel
{
    int num;
    char type;
    int status;
};

struct node
{
	Hotel info;
    node* pNext;
};

typedef struct node NODE;

struct list{
	NODE* pHead;
	NODE* pTail;
};

typedef struct list LIST;

void CreateList(LIST &l)  // Kh?i t?o danh sách
{

	l.pHead = NULL;
	l.pTail = NULL;
}

NODE* CreateNode(int x,char y,int z) {
NODE* p = new NODE;
if (p == NULL)
exit(1);

p->info.num = x;
p->info.type=y;
p->info.status=z;
p->pNext = NULL;
return p;
}

void AddHead(LIST& l, NODE* p) // Thêm vào cu?i
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void AddTail(LIST& l, NODE* p) // Thêm vào d?u
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void PrintList(LIST l) {
NODE* p;
if (l.pHead == NULL)
cout << "\nDSLK rong.";

else {
p = l.pHead;
while (p) {
cout <<"so phong: "<< p->info.num << "\t"<<"loai phong: "<<p->info.type<<"\t"<<"tinh trang: "<<p->info.status<<endl;

p = p->pNext;
}

}
cout<<endl;
}
void ThongKe(LIST l,int &dem1,int &dem3)
{
    int dem2,dem4;
    dem1=0;
    dem2=0;
    dem3=0;
    dem4=0;
    for(NODE* p=l.pHead;p!=NULL;p=p->pNext)
    {
        if(p->info.type=='A'&&p->info.status==1)dem1+=1;
        if(p->info.type=='A'&&p->info.status==0)dem2+=1;
        if(p->info.type=='B'&&p->info.status==1)dem3+=1;
        if(p->info.type=='B'&&p->info.status==0)dem4+=1;
    }
    cout<<"so phong don da co khach la "<<dem1<<endl;
    cout<<"so phong don trong la "<<dem2<<endl;
    cout<<"so phong doi da co khach la "<<dem3<<endl;
    cout<<"so phong doi trong la "<<dem4<<endl;
}
int DoanhThu(LIST l,int dem1,int dem3)
{
    int tien;
    tien=dem1*200 + dem3*350;
    return tien;
}
int RemoveHead(LIST &l,int& x)
{
    if(l.pHead!=NULL)
    {
        x=l.pHead->info.num;
        NODE* p=l.pHead;
        l.pHead=l.pHead->pNext;
        if(l.pHead=NULL)
            l.pTail=NULL;
        delete p;
        return 1;
    }
    return 0;
}
int RemoveAfterQ(LIST &l,int &x,NODE* q)
{
    if(q!=NULL)
    {
        NODE*p=q->pNext;
        x=p->info.num;
        if(p!=NULL)
        {
            if(l.pTail=p)
                l.pTail=q;
            q->pNext=q->pNext;
            delete p;
            return 1;
        }
    }
    return 0;
}

void Xoa_Node_info_x(LIST l, int x)
{
    int dem = 0;
    NODE *p = l.pHead;
    NODE *preX = l.pHead;
    while (p != NULL)
    {
        if (p->info.num == x)
        {
            NODE *r = p;
            if (p == l.pHead) {
                l.pHead = (l.pHead)->pNext;
                p = l.pHead;
                preX = l.pHead;
            }
            else {
                preX->pNext = p->pNext;
                p = p->pNext;
            }
            dem++;
            free(r);
            continue;
        }
        preX = p;
        p = p->pNext;
    }

     PrintList(l);
}

int main()
{
    LIST l;

    CreateList(l);
    int dem1, dem3;
    int n;
    cout<<"nhap N node: ";
    cin>>n;
    int x,z;
    char y;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        cin>>y;
        cin>>z;
        AddTail(l,CreateNode(x,y,z));
    }
    PrintList(l);
    ThongKe(l,dem1,dem3);
    cout<<"doanh thu ks trong 1 ngay la "<<DoanhThu(l,dem1,dem3)<<endl;
    Xoa_Node_info_x(l, x);
    return 0;
}


