#include "mystring.h" 

using namespace std;
int _total_MyString = 0;

void  main() {

	/////////////////////////////////////////////////////////
	cout << "Total_MyString is: " << MyString::total_MyString() << endl;

	MyString str1("String"), str2("Test String 2"), str3(str1);

	cout << "str1 is: " << str1 << endl;
	cout << "str2 is: " << str2 << endl;
	cout << "str3 is: " << str3 << endl;
	cout << "Total_MyString is: " << MyString::total_MyString() << endl;

	/////////////////////////////////////////////////////////

	cout << "Give one word " << endl;
	cin >> str1;							// from stdin "this is a test line"
	cout << "str1 is: " << str1 << endl;

	/////////////////////////////////////////////////////////

	str2 = str1;
	cout << "str2 is: " << str2 << endl;

	/////////////////////////////////////////////////////////

	str3 += str1;
	cout << "str3 is: " << str3 << endl;

	/////////////////////////////////////////////////////////
	
	cout << "str3 is: ";
	for (int i = 0; i<str3.length(); i++)
		cout << str3[i];
	cout << endl;

	for (int i = 0; i<str3.length(); i++)
		str3[i] = 'a' + i;
	cout << "str3 is: " << str3 << endl;

	/////////////////////////////////////////////////////////

	cout << "str1 is: " << str1 << endl;
	cout << "str2 is: " << str2 << endl;
	cout << "str3 is: " << str3 << endl;
	cout << "Compare str1 == str2 is: " << (str1 == str2) << endl;
	cout << "Compare str1 == str3 is: " << (str1 == str3) << endl;
	cout << "Compare str1 != str2 is: " << (str1 != str2) << endl;
	cout << "Compare str1 != str3 is: " << (str1 != str3) << endl;
	cout << "Total MyString is: " << MyString::total_MyString() << endl;


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// MyString_Derived
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	
	MyString_Derived Dstr1("String"), Dstr2("Test String 2"), Dstr3(Dstr1);

	cout << "Dstr1 is: " << Dstr1 << endl;
	cout << "Dstr2 is: " << Dstr2 << endl;
	cout << "Dstr3 is: " << Dstr3 << endl;
	cout << "Total MyString_Derived is: " << MyString_Derived::total_MyString() << endl;

	/////////////////////////////////////////////////////////

	cout << "Give one word " << endl;
	cin >> Dstr1;							// from stdin "this is a test line"
	cout << "Dstr1 is: " << Dstr1 << endl;

	/////////////////////////////////////////////////////////

	Dstr2 = Dstr1;
	cout << "Dstr2 is: " << Dstr2 << endl;

	/////////////////////////////////////////////////////////

	Dstr3 += Dstr1;
	cout << "Dstr3 is: " << Dstr3 << endl;

	/////////////////////////////////////////////////////////

	cout << "Dstr3 is: ";
	for (int i = 0; i<Dstr3.length(); i++)
		cout << Dstr3[i];
	cout << endl;

	for (i = 0; i<Dstr3.length(); i++)
		Dstr3[i] = 'a' + i;
	cout << "Dstr3 is: " << Dstr3 << endl;

	/////////////////////////////////////////////////////////

	cout << "Dstr1 is: " << Dstr1 << endl;
	cout << "Dstr2 is: " << Dstr2 << endl;
	cout << "Dstr3 is: " << Dstr3 << endl;
	cout << "Compare Dstr1 == Dstr2 is: " << (Dstr1 == Dstr2) << endl;
	cout << "Compare Dstr1 == Dstr3 is: " << (Dstr1 == Dstr3) << endl;
	cout << "Compare Dstr1 != Dstr2 is: " << (Dstr1 != Dstr2) << endl;
	cout << "Compare Dstr1 != Dstr3 is: " << (Dstr1 != Dstr3) << endl;
	

}