#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct snode
{
	char info;
	snode* pnext;
};
struct nv
{
	string hoten;
	string gioitinh;
	string ntn;
};
struct nhanvien
{
	nv thongtin;
	nhanvien* pnext;
};
template <class type>
struct queue
{
	type* head;
	type* tail;
};
template <class type>
struct stack
{
	type* head;
	type* tail;
};
snode* createsnode(char a)
{
	snode* p;
	p = new snode;
	p->info = a;
	p->pnext = NULL;
	return p;
}
nv getnv()
{
	nv z;
	cin >> z.hoten >> z.ntn >> z.gioitinh;
	return z;
}
nhanvien* createnv(nv z)
{
	nhanvien* p = new nhanvien;
	p->thongtin = z;
	p->pnext = NULL;
	return p;
}
template <class type>
void createqueue(queue<type>& z)
{
	z.head = NULL;
	z.tail = NULL;
}
template <class type>
void createstack(stack<type>& z)
{
	z.head = NULL;
	z.tail = NULL;
}
template <class type>
void addqueue(queue<type>& z, type* p) //addtail
{
	if (z.head == NULL)
	{
		z.head = p;
		z.tail = z.head;
	}
	else
	{
		z.tail->pnext = p;
		z.tail = p;
	}
}
template <class type>
void push(stack<type>& z, type* p) //addhead
{
	if (z.head == NULL)
	{
		z.head = p;
		z.tail = z.head;
	}
	else
	{
		p->pnext = z.head;
		z.head = p;
	}
}
bool ispalindrome(string str)
{
	stack<snode> a;
	queue<snode> b;
	createqueue(b);
	createstack(a);
	for (int i = 0; i < str.length(); i++)
	{
		addqueue(b, createsnode(str[i]));
		push(a, createsnode(str[i]));
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (a.head->info != b.head->info)
			return false;
		a.head = a.head->pnext;
		b.head = b.head->pnext;
	}
	return true;
}
void printnv(nhanvien* z)
{
	cout << left << setw(10) << z->thongtin.hoten << setw(15) << z->thongtin.ntn << setw(10) << z->thongtin.gioitinh << endl;
}
queue<nhanvien> nhapdsnv()
{
	queue<nhanvien> z;
	createqueue(z);
	int n;
	cout << "nhap so luong nv: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		addqueue(z, createnv(getnv()));
	}
	return z;
}
void demerging()
{
	queue<nhanvien> z;
	z = nhapdsnv();
	queue<nhanvien> nu, nam;
	createqueue(nu);
	createqueue(nam);
	nhanvien* p = z.head;
	nv l;
	while (p != NULL)
	{
		if (p->thongtin.gioitinh == "nam")
		{
			l = p->thongtin;
			addqueue(nam, createnv(l));
		}
		if (p->thongtin.gioitinh == "nu")
		{
			l = p->thongtin;
			addqueue(nu, createnv(l));
		}
		p = p->pnext;
	}
	cout << left << setw(10) << "ten" << setw(15) << "ngay thang nam sinh" << setw(10) << "gioi tinh" << endl;
	while (nu.head != NULL)
	{
		printnv(nu.head);
		nu.head = nu.head->pnext;
	}
	while (nam.head != NULL)
	{
		printnv(nam.head);
		nam.head = nam.head->pnext;
	}
}
int main()
{
	string str;
	int n, a;
	cout << "1. kiem tra palindrome." << endl;
	cout << "2. demerging" << endl;
	cin >> a;
	while (a == 1 || a == 2)
	{
		switch (a)
		{
		case 1:
			cout << "nhap chuoi can kiem tra: ";
			cin.ignore();
			getline(cin, str);
			if (ispalindrome(str) == true)
				cout << "true" << endl;
			else cout << "false" << endl;
			break;
		case 2:
			demerging();
			break;
		default:
			break;
		}
		cout << "1. kiem tra palindrome." << endl;
		cout << "2. demerging " << endl;
		cin >> a;
	}
}
