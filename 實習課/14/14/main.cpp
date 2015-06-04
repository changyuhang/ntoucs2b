#include <iostream>
using namespace std;

// Target Class
class LookUpTable {
public:
	virtual int insert(int) = 0; //�[�J�@�ӭ� �^�Ǧ��\(1) ����(0)
	virtual int remove(int) = 0; //�R���@�ӭ� �^�Ǧ��\(1) ����(0)
	virtual int* get(int) = 0;	//�d�ߤ@�ӭ� 
	//���\�^�� ���Ы���table����
	//���Ѧ^��(0)
};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//����: �ϥ� LookUpTable

void run_LookupTable(LookUpTable *ptr) {
	int i, *vptr;

	cout << "Test insert ���\ " << endl;
	for (i = 0; i<10; i++)
		cout << ptr->insert(i) << endl;	//�^�Ǧ��\(1)  

	cout << "Test insert����" << endl;
	for (i = 0; i<10; i++)
		cout << ptr->insert(i) << endl;  	  //�^�� ����(0)

	cout << "Test table��" << endl;
	for (i = 0; i<10; i++) {
		if (vptr = ptr->get(i))
			cout << *vptr << endl;  // ���\ 
		else
			cout << 0 << endl;  	   // ����
	}


	cout << "Test remove���\ " << endl;
	for (i = 0; i<10; i += 2)
		cout << ptr->remove(i) << endl;  //�^�Ǧ��\(1)

	cout << "Test remove����" << endl;
	for (i = 0; i<10; i += 2)
		cout << ptr->remove(i) << endl;  //�^�ǥ���(0)

	cout << "Test table��" << endl;
	for (i = 0; i<10; i++) {
		if (vptr = ptr->get(i))
			cout << *vptr << endl;  // ���\ 
		else
			cout << 0 << endl;  	   // ����
	}
}


/////////////////////////////////////////////////////////////////////
// Adaptee Class 
/*
�A�i��int array[1000] ��@�@��²�� class
�]�t insert remove get functions ����@
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
	//�[�J�@�ӭ� ���\result�]��1  ����result�]��0
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
	//�R���@�ӭ� ���\result�]��1  ����result�]��0
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
	//�d�ߤ@�ӭ�   ���\ ����ptr����table����
	//���� ����ptr�]��0
};


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//
// ��@�W �{���u�[ adapter
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
	// override (��g) LookUpTable functions   
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
	} //�[�J�@�ӭ� �^�Ǧ��\(1) ����(0)
	int remove(int value) {
		for (int i = 0; i <= place; i++) {
			if (a[i] == value) {
				a[i] = -1;
				return 1;
			}
		}
		return 0;
	} //�R���@�ӭ� �^�Ǧ��\(1) ����(0)
	int* get(int value) {
		for (int i = 0; i <= place; i++) {
			if (a[i] == value) {
				return &a[i];
			}
		}
		return 0;
	}	//�d�ߤ@�ӭ� 

};

/////////////////////////////////////////////////////////////////////
// Object Adapter
class adapter_object : public LookUpTable
{

public:
	int a[10000];
	int place;
	adapter_object() { place = 0; }
	// override (��g) LookUpTable functions   
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
	} //�[�J�@�ӭ� �^�Ǧ��\(1) ����(0)
	int remove(int value) {
		for (int i = 0; i <= place; i++) {
			if (a[i] == value) {
				a[i] = -1;
				return 1;
			}
		}
		return 0;
	} //�R���@�ӭ� �^�Ǧ��\(1) ����(0)
	int* get(int value) {
		for (int i = 0; i <= place; i++) {
			if (a[i] == value) {
				return &a[i];
			}
		}
		return 0;
	}	//�d�ߤ@�ӭ� 

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