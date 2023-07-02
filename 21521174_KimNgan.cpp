#include <iostream>
using namespace std;


struct Info {
	char Ma[50];
	char Ten[100];
	int NamSinh;
	int SoSanPhamMay;
};
struct DNode
{
	Info info;
	DNode* next;
	DNode* pre;
};

struct DList
{
	DNode* head;
	DNode* tail;
};
void CreateDList(DList &l)
{
	l.head = NULL;
	l.tail = NULL;
}

DNode* CreateNode(Info x)
{
	DNode* p = new DNode;
	if(p==NULL) exit(1);
	p->info=x;
	p->next=NULL;
	p->pre=NULL;
	return p;
}

void AddHead(DList &l, DNode* p)
{
	if(l.head==NULL)
	{
		l.head=p;
		l.tail=p;
	}
	else {
		p->next=l.head;
		l.head->pre=p;
		l.head=p;
	}
}

void AddTail(DList &l, DNode* p)
{
	if(l.head==NULL)
	{
		l.head=p;
		l.tail=p;
	}
	else {
		l.tail->next=p;
		p->pre=l.tail;
		l.tail=p;
	}
}


// cau 1
void InputNodes(DList &L) {
	int n;
	cout<<"Nhap so cong nhan: ";
	cin>>n;
	Info a[n];
	for (int i=0;i<n;i++){
		cout<<"CONG NHAN "<<i+1<<": \n";
		cout<<"Ma cong nhan: ";
		cin>>a[i].Ma;
		cout<<"Ten cong nhan: ";
		cin.ignore();
		gets(a[i].Ten);
		cout<<"Nam sinh cong nhan: ";
		cin>>a[i].NamSinh;
		cout<<"So san pham may: ";
		cin>>a[i].SoSanPhamMay;
		AddTail(L,CreateNode(a[i]));
	}	
}

// cau 2
void InCongNhan (Info x) {
	cout<<"\nMa cong nhan: "<<x.Ma;
	cout<<"\nTen cong nhan: "<<x.Ten;
	cout<<"\nNam sinh cong nhan: "<<x.NamSinh;
	cout<<"\nSo san pham may: "<<x.SoSanPhamMay<<endl;
 
}


void PrintList(DList L) {
DNode* p;
if (L.head == NULL)
cout << "\nDSLK rong.";
else {
p = L.head;
while (p) {
InCongNhan(p->info);
p = p->next;
}
}
}

// cau 3

void SoSanPhamNhieuNhat(DList l)
{
	if(l.head != NULL){
		int max = l.head->info.SoSanPhamMay;
		for (DNode *i = l.head; i!=NULL; i=i->next){
			if(max < i->info.SoSanPhamMay)
				max = i->info.SoSanPhamMay;
		}
		cout<<"\nCong nhan co so san pham may nhieu nhat: "<<endl;
		for (DNode *i = l.head; i!=NULL; i=i->next){
			if(max == i->info.SoSanPhamMay)
				{
					InCongNhan(i->info);
				}
		}
	}
}

// cau 4
void ThongKeTuoi (DList l){
	if (l.head != NULL){
		int tuoi30 = 0;
		int tuoi3050= 0;
		int tuoi50 = 0;
		for (DNode* i=l.head;i!=NULL;i=i->next){
			int check = 2022 - i->info.NamSinh;
			if(check < 30)	tuoi30++;
			if(check >=30 && check <= 50) tuoi3050++;
			if(check > 50)	tuoi50++;
		}
		cout<<"\nSo luong cong nhan duoi 30 tuoi la: "<<tuoi30<<endl;
		cout<<"So luong cong nhan trong khoang 30-50 tuoi la: "<<tuoi3050<<endl;
		cout<<"So luong cong nhan tren 50 tuoi la: "<<tuoi50<<endl;
	}
}

// cau 5
void SapXepGiamDan (DList &l)
{
	Info a[100];
	int temp=0;
	if(l.head != NULL) {
		for(DNode* i=l.head; i!=NULL;i=i->next) {
			a[temp] = i->info;
			temp++;
		}
		
		Info tg;
    	for(int i = 0; i < temp-1; i++){
        	for(int j = i + 1; j < temp; j++){
            	if(a[i].SoSanPhamMay < a[j].SoSanPhamMay){
                	// Hoan vi 2 so a[i] va a[j]
                	tg = a[i];
                	a[i] = a[j];
                	a[j] = tg;        
            	}
        	}
    	}
    	int temp2 = 0;
    	for(DNode* i=l.head; i!=NULL;i=i->next) {
			i->info = a[temp2];
			temp2++;
		}
		
		cout<<"\nDanh sach sau khi sap xep la: "<<endl;
		PrintList(l);
	}
}

int main(){
	DList l;
    CreateDList(l); 
    InputNodes(l); //c1
	PrintList(l); //c2
	SoSanPhamNhieuNhat(l); //c3
	ThongKeTuoi(l); //c4
	SapXepGiamDan(l); //c5
	return 0;
}
