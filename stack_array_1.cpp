#include <iostream>

using namespace std;


int maksimal = 5;
string piring_arr[5];
int top = 0;



bool isFull()
{
  if( top == maksimal ){
    return true;
  }else{
    return false;
  }
}

bool isEmpty()
{
  if( top == 0 ){
    return true;
  }else{
    return false;
  }
}


void pushArray(string data){
	
	if(top<maksimal){
		piring_arr[top] = data;
		top++;
		
	}else {
		cout<<"data Penuh"<<endl;
	}
}


void popArray()
{
  if( isEmpty() ){
    cout << "Data kosong!!" << endl;
  }else{
    piring_arr[top-1] = "";
    top--;
  }
}

void displayArray(){
	cout<<"Data Stack array : "<<endl;
	for(int i = maksimal-1 ;i>=0;i--){
		if(piring_arr[i]!=""){
				cout<<"Data : "<<piring_arr[i]<<endl;
		}
		
	
	}
	cout<<"\n";
}

void peekArray(int posisi){
  if( isEmpty() ){
    cout << "Data kosong!!" << endl;
  }else{
    int index = top;
    for( int i = 0; i < posisi; i++ ){
      index--;
    }
    cout << "Data posisi ke-" << posisi << " : " << piring_arr[index] << endl;
  }
}

void changeArray(string data, int posisi){
  if( isEmpty() ){
    cout << "Data kosong!!" << endl;
  }else{
    int index = top;
    for( int i = 0; i < posisi; i++ ){
      index--;
    }
    piring_arr[index] = data;
  }
}

int countArray()
{
  if( isEmpty() ){
    return 0;
  }else{
    return top;
  }
}

void destroyArray(){
  for( int i = 0; i < top; i++ ){
    piring_arr[i] = "";
  }
  top = 0;
}

int main(){
	pushArray("piring 1");
	displayArray();
	
	pushArray("piring 2");
	pushArray("piring 3");
	pushArray("piring 4");
	pushArray("piring 5");
	pushArray("piring 6");
	displayArray();
	
	cout<<"keluarkan data :"<<endl;
	popArray();
	displayArray();
	
	cout << "Apakah data full ? : " << isFull() << endl;
	  cout << "Apakah data kosong ? : " << isEmpty() << endl;
////	  
	  peekArray(2);
//	  
  cout << "Banyak data : " << countArray() << endl;
////
 changeArray("piring Putih", 2);
////  
  displayArray();
//
 destroyArray();
//
  cout << "Apakah data full ? : " << isFull() << endl;
  cout << "Apakah data kosong ? : " << isEmpty() << endl;

}
