#include <iostream>
using namespace std;
//penjumlahan dan perkalian polinomial dengan array

void tampil(int a[], int n)
{
	for (int i = 0 ; i < n ; i++)
	{	if (i == 0)
			cout << a[0] <<" + ";
		else	
			if (i == 1)
				cout << a[1] << " x + ";
			else
				if (i == n-1)
					cout << a[i] <<" x^"<< i << endl;
				else
					cout << a[i] << " x^"<< i << " + ";
	}	
	cout<<"\n";
}

int main()
{
	int p[20], q[20], r[20], s[40];
	int n, m, i,j;
	
	for (i = 0 ; i < 20 ; i++)
	{	p[i] = 0;
		q[i] = 0;
		r[i] = 0;
	}
	for (i = 0 ; i < 40 ; i++)
		s[i] = 0;

	cout<<" Ketikkan pangkat tertinggi dari polinomial 1: ";
	cin>> n;
	cout<< endl;
	cout<<" Ketikkan konstanta polinomial mulai dari suku pangkat terendah ";
	cout<<endl;
	cout<<" Ketikkan angka 0 jika tidak ada konstanta pada suku tersebut";
	cout << endl;
	for (i = 0 ; i < n ; i++)
	{	cout<<" Konstanta untuk suku polinomial ke "<< i+1 <<" ";
		cin>> p[i];
	}
	cout<<endl;
	cout<<" Ketikkan pangkat tertinggi dari polinomial 2: ";
	cin>> m;
	cout<<" Ketikkan konstanta polinomial mulai dari suku pangkat terendah ";
	cout<<endl;
	cout<<" Ketikkan angka 0 jika tidak ada konstanta pada suku tersebut";
	cout << endl;
	for (i = 0 ; i < m ; i++)
	{	cout<<" Konstanta untuk suku polinomial ke "<< i+1  <<"  ";
		cin>> q[i];
	}
	cout<<endl;
	cout<<"Polinomial 1: "<<endl;
	tampil(p,n);
	cout<<"Polinomial 2: "<<endl;
	tampil(q,m);
	if (n > m)
	{	for ( i = 0; i < n ; i++)
		r[i] = p[i] + q[i];
		cout<< " Hasil penjumlahan 2 polinomial: "<<endl;
		tampil(r,n);
	}
	else 
	{	for ( i = 0; i < m ; i++)
		r[i] = p[i] + q[i];
		cout<< " Hasil penjumlahan 2 polinomial: "<<endl;
		tampil(r,m);	
	}
	for (i = 0; i < n ; i ++ )
	{	for ( j = 0 ; j < m ; j++ )
		{	s[i+j]  =  s[i+j] + p[i] * q[j];
		}
	}
	cout<<endl;
	cout<< " Hasil perkalian 2 polinomial: "<<endl;
	tampil(s, m+n-1);	
}

