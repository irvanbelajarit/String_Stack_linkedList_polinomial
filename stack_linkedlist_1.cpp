#include <iostream>
using namespace std;

struct dataBarang{
  string namaBarang;
  int hargaBarang;

  // pointer
  dataBarang *prev;
  dataBarang *next;
};

dataBarang *head, *tail, *cur, *newNode, *del;
int maksimalBarang = 5;

void createBarang(string namaBarang, int hargaBarang){
  head = new dataBarang();
  head->namaBarang = namaBarang;
  head->hargaBarang = hargaBarang;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

int countBarang()
{
  if( head == NULL ){
    return 0;
  }else{
    int banyak = 0;
    cur = head;
    while( cur != NULL ){
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}


bool isFullBarang()
{
  if( countBarang() == maksimalBarang ){
    return true;
  }else{
    return false;
  }
}

bool isEmptyBarang()
{
  if( countBarang() == 0 ){
    return true;
  }else{
    return false;
  }
}

void pushBarang( string namaBarang, int hargaBarang ){

  if( isFullBarang() ){
    cout << "Stack Full!!" << endl;
  }else{
    if( isEmptyBarang() ){
      createBarang(namaBarang, hargaBarang);
    }else{
      newNode = new dataBarang();
      newNode->namaBarang = namaBarang;
      newNode->hargaBarang = hargaBarang;
      newNode->prev = tail;
      tail->next = newNode;
      newNode->next = NULL;
      tail = newNode;
    }
  }

}

void popBarang()
{
  del = tail;
  tail = tail->prev;
  tail->next = NULL;
  delete del;
}


void displayBarang()
{
  if( isEmptyBarang() ){
    cout << "Data Barang kosong" << endl;
  }else{
    cout << "\n\nData barang : " << endl;
    cur = tail;
    while( cur != NULL ){
      cout << "Data Barang : " << cur->namaBarang << " - Rp." << cur->hargaBarang << endl;
      cur = cur->prev;
    }
  }
}

void peekBarang(int posisi){

  if( isEmptyBarang() ){
    cout << "Data Barang kosong" << endl;
  }else{
    int nomor = 1;
    cur = tail;
    while( nomor < posisi ){
      cur = cur->prev;
      nomor++;
    }
    cout << "Data Barang Posisi ke-" << posisi << " : " << cur->namaBarang << " - Rp." << cur->hargaBarang << endl;
  }

}

void changeBarang(string namaBarang, int hargaBarang, int posisi){

  if( isEmptyBarang() ){
    cout << "Data Barang kosong" << endl;
  }else{
    int nomor = 1;
    cur = tail;
    while( nomor < posisi ){
      cur = cur->prev;
      nomor++;
    }
    cur->namaBarang = namaBarang;
    cur->hargaBarang = hargaBarang;
  }

}

void destroyBarang()
{
  cur = head;
  while( cur != NULL ){
    del = cur;
    head = head->next;
    delete del;
    cur = cur->next;
  }
}

int main(){
	pushBarang("RAM", 500000);
    displayBarang();

  pushBarang("Motherboard", 1000000);
 pushBarang("Monitor", 1800000);
  pushBarang("Joystick", 250000);
  pushBarang("Keyboard", 650000);
  displayBarang();
  pushBarang("Mouse", 1500000);
  displayBarang();
//
 cout << "Apakah data barang full ? : " << isFullBarang() << endl;
  cout << "Apakah data barang kosong ? : " << isEmptyBarang() << endl;
 cout << "Jumlah data barang : " << countBarang() << endl;
//
 popBarang();
  displayBarang();
cout<<"\n";
  peekBarang(3);
//
  changeBarang("Webcam", 750000, 2);
 displayBarang();
//
  destroyBarang();
  cout << "Apakah data barang full ? : " << isFullBarang() << endl;
  cout << "Apakah data barang kosong ? : " << isEmptyBarang() << endl;
  cout << "Jumlah data barang : " << countBarang() << endl;
  displayBarang();
}


