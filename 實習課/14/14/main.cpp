#include <iostream>
using namespace std;

// Target Class
class LookUpTable {
public:
	virtual int insert(int) = 0; //加入一個值 回傳成功(1) 失敗(0)
	virtual int remove(int) = 0; //刪除一個值 回傳成功(1) 失敗(0)
	virtual int* get(int) = 0;	//查詢一個值 
	//成功回傳 指標指到table的值
	//失敗回傳(0)
};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//測試: 使用 LookUpTable

void run_LookupTable(LookUpTable *ptr) {
	int i, *vptr;

	cout << "Test insert 成功 " << endl;
	for (i = 0; i<10; i++)
		cout << ptr->insert(i) << endl;	//回傳成功(1)  

	cout << "Test insert失敗" << endl;
	for (i = 0; i<10; i++)
		cout << ptr->insert(i) << endl;  	  //回傳 失敗(0)

	cout << "Test table值" << endl;
	for (i = 0; i<10; i++) {
		if (vptr = ptr->get(i))
			cout << *vptr << endl;  // 成功 
		else
			cout << 0 << endl;  	   // 失敗
	}


	cout << "Test remove成功 " << endl;
	for (i = 0; i<10; i += 2)
		cout << ptr->remove(i) << endl;  //回傳成功(1)

	cout << "Test remove失敗" << endl;
	for (i = 0; i<10; i += 2)
		cout << ptr->remove(i) << endl;  //回傳失敗(0)

	cout << "Test table值" << endl;
	for (i = 0; i<10; i++) {
		if (vptr = ptr->get(i))
			cout << *vptr << endl;  // 成功 
		else
			cout << 0 << endl;  	   // 失敗
	}
}


/////////////////////////////////////////////////////////////////////
// Adaptee Class 
/*
你可用int array[1000] 實作一個簡單 class
包含 insert remove get functions 的實作
*/

class adaptee{
	int a[10000];
	int place;
	adaptee() { place = 0; }
	void insert(int value, int &result) {
		for (int i = 0; i <= place; i++) {
			if (a[i] == value) {
				result = 0;
				return;
			}
		}
		if (place < 10000) {
			a[place] = value;
			place++;
			result = 1;
		}
		else
			result = 0;
	}
	//加入一個值 成功result設成1  失敗result設成0
	void remove(int value, int &result) {
		for (int i = 0; i <= place; i++) {
			if (a[i] == value) {
				a[i] = -1;
				result = 1;
				return;
			}
		}
		result = 0;
		return;
	}
	//刪除一個值 成功result設成1  失敗result設成0
	void get(int value, int * &ptr) {
		for (int i = 0; i <= place; i++) {
			if (a[i] == value) {
				*ptr = a[i];
				return;
			}
		}
		*ptr = 0;
		return;
	}
	//查詢一個值   成功 指標ptr指到table的值
	//失敗 指標ptr設成0
};


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//
// 實作上 程式只加 adapter
//
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
// Class Adapter
class adapter_class : public LookUpTable
{

public:
	int a[10000];
	int place;
	adapter_class() { place = 0; }
	// override (改寫) LookUpTable functions   
	int insert(int value) {
		for (int i = 0; i <= place; i++) {
			if (a[i] == value) {
				return 0;
			}
		}
		if (place < 10000) {
			a[place] = value;
			place++;
			return 1;
		}
		else
			return 0;
	} //加入一個值 回傳成功(1) 失敗(0)
	int remove(int value) {
		for (int i = 0; i <= place; i++) {
			if (a[i] == value) {
				a[i] = -1;
				return 1;
			}
		}
		return 0;
	} //刪除一個值 回傳成功(1) 失敗(0)
	int* get(int value) {
		for (int i = 0; i <= place; i++) {
			if (a[i] == value) {
				return &a[i];
			}
		}
		return 0;
	}	//查詢一個值 

};

/////////////////////////////////////////////////////////////////////
// Object Adapter
class adapter_object : public LookUpTable
{

public:
	int a[10000];
	int place;
	adapter_object() { place = 0; }
	// override (改寫) LookUpTable functions   
	int insert(int value) {
		for (int i = 0; i <= place; i++) {
			if (a[i] == value) {
				return 0;
			}
		}
		if (place < 10000) {
			a[place] = value;
			place++;
			return 1;
		}
		else
			return 0;
	} //加入一個值 回傳成功(1) 失敗(0)
	int remove(int value) {
		for (int i = 0; i <= place; i++) {
			if (a[i] == value) {
				a[i] = -1;
				return 1;
			}
		}
		return 0;
	} //刪除一個值 回傳成功(1) 失敗(0)
	int* get(int value) {
		for (int i = 0; i <= place; i++) {
			if (a[i] == value) {
				return &a[i];
			}
		}
		return 0;
	}	//查詢一個值 

};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


void main() {

	cout << "Test adapter_class" << endl;
	adapter_class ac;
	run_LookupTable(&ac);

	cout << "Test adapter_object" << endl;
	adapter_object ao;
	run_LookupTable(&ao);

}