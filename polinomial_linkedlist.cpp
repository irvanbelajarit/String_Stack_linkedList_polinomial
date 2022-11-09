#include <iostream>
using namespace std;

struct Node		//penjumlahan polinomial dengan linked list
{
	int data;
	int p;
	Node *link;
};

void InsertN(Node **L, int c, int j)
{	
	Node *baru, *t;
	baru = new Node; 
	baru->link=NULL;
	baru->data = c;
	baru->p = j;
	if (*L == NULL)
		*L = baru;
	else
	{	t = *L;
		while (t->link != NULL)
			t = t->link;
		t->link = baru;
	}
}

void Tampil(Node *L)
{
	Node *N;
	N = L;
	while (N->link != NULL)
	{
		cout <<N->data <<" x^" <<N->p << " + ";
		N = N->link;
	}	
	if (N->link == NULL)
		cout <<N->data <<" x^" <<N->p << endl;
}

int main()
{
	int n, m, x, y;
	Node *P1, *P2, *P3;

	P1 = NULL;
	P2 = NULL;
	P3 = NULL;
	cout<<" Ketikkan banyaknya suku dalam polinomial 1: ";
	cin>> n;
	cout<< endl;
	cout<<" Ketikkan konstanta dan pangkat polinomial secara berurutan ";
	cout <<endl;
	for (int i = 0 ; i < n ; i++)
	{	cout<<" Konstanta untuk suku polinomial ke "<< i+1 <<" = ";
		cin>> x;
		cout<<" Pangkat untuk suku polinomial ke "<< i+1 <<" = ";
		cin>> y;
		InsertN(&P1, x, y);	
	}
	cout<<endl;
	cout<<" Ketikkan banyaknya suku dalam polinomial 2: ";
	cin>> m;
	cout<< endl;
	cout<<" Ketikkan konstanta dan pangkat polinomial secara berurutan ";
	cout <<endl;
	for (int i = 0 ; i < m ; i++)
	{	cout<<" Konstanta untuk suku polinomial ke "<< i+1 <<" = ";
		cin>> x;
		cout<<" Pangkat untuk suku polinomial ke "<< i+1 <<" = ";
		cin>> y;
		InsertN(&P2, x, y);	
	}
	cout<<endl;
	cout<<"Polinomial 1: "<<endl;
	Tampil(P1);
	cout<<"Polinomial 2: "<<endl;
	Tampil(P2);

	cout<<"Menjumlahkan polinomial" <<endl;
	
	Node *a, *b ;
	a = P1;
	b = P2;
	
//membuat loop untuk menelusuri p dan q] 
	while ( a->link != NULL && b->link!= NULL )
    {	// memeriksa pangkat tiap node]
		if ((a->p == b->p) && ((a->data + b->data) != NULL))
		{	// pangkat sama dan hasil jumlah tidak nol,	lakukan penjumlahan
			InsertN(&P3, (a->data + b->data), a->p);
			a = a->link;	// lanjutkan dengan node berikutnya
			b = b->link;
		}
		else 
		{  			//pangkat polinomial p < q]
			if (a->p < b->p)			//salin polinomial p
			{	InsertN(&P3, a->data, a->p);
				a = a->link;
			}
		 	else 
			{		//[pangkat polinomial p > q]
				if (a->p > b->p)		//salin polinomial q
				{	InsertN(&P3, b->data, b->p);
					b = b->link;
				}
			}
		}
	}
	if (a->link == NULL)	// node terakhir dari polinomial p 
	{						//masih ada node di pilonomial q
		while ((a->p > b->p) && (b->link != NULL))
		{	InsertN(&P3, b->data, b->p);
			b = b->link;
		}
		if (a->p == b->p)
		{	InsertN(&P3, (a->data +b->data), a->p);
			b = b->link;
		}
		else 
			InsertN(&P3, a->data, a->p);
		while (b->link != NULL)		//menyalin sisa node polinomial q
		{	InsertN(&P3, b->data, b->p);
			b = b->link;
		}
	}
	if (b->link == NULL)	// node terakhir dari polinomial q 
	{						// masih ada node di polinomial p
		while ((b->p > a->p) && (a->link != NULL))
		{	InsertN(&P3, a->data, a->p);
			a = a->link;
		}
		if (a->p == b->p)
		{	InsertN(&P3, (a->data + b->data), b->p);
			a = a->link;
		}
		else 
			InsertN(&P3, b->data, b->p);
		while (a ->link != NULL)	//menyalin sisa node polinomial p
		{	InsertN(&P3, a->data, a->p);
			a = a->link;
		}	
	}
	Tampil(P3);
	system ("pause");
}		


