// Strategy.  Use recursive composition 
// 
// Benefit:  
//		No more type checking and type casting 

#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////
// Component class 
///////////////////////////////////////////////////////////////
class AbsFile {

public:
	virtual void ls() = 0;														//*********
protected:
	char        name_[20];
	static int  indent_;
};

int AbsFile::indent_ = 0;


///////////////////////////////////////////////////////////////
// Leaf class 
///////////////////////////////////////////////////////////////


class File : public AbsFile {

public:
	File(char* n) { strcpy(name_, n); }

	void ls()																				//*********
	{
		for (int i = 0; i < indent_; i++)    cout << ' ';
		cout << name_ << endl;
	}
};

///////////////////////////////////////////////////////////////
// Composite  class 
///////////////////////////////////////////////////////////////
class Dir : public AbsFile {
public:

	Dir(char* n) { strcpy(name_, n); total_ = 0; }

	void add(AbsFile* f) {
		for (int i = 0; i < total_; i++)
			if (files_[i] == f)return;
		files_.push_back(f);
		total_++;
		//files_[total_++] = f; 
	}

	void ls() {																			//*********
		for (int i = 0; i < indent_; i++)   cout << ' ';
		cout << name_ << ":" << endl;
		indent_ += 3;

		for (int i = 0; i < total_; i++)
			files_[i]->ls();														//*********

		indent_ -= 3;
	}

	void remove(File *f) {
		for (int i = 0; i < total_; i++) {
			if (files_[i] == f) {
				for (i += 1; i < total_; i++)
					files_[i - 1] = files_[i];
				files_.pop_back();
				total_--;
			}
		}
	}
private:
	std::vector<AbsFile*>  files_;
	int       total_;
};



///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

void main(void) {
	Dir   one("1"), two("2"), three("3");
	File  a("a"), b("b"), c("c"), d("d"), e("e");

	one.add(&a);
	one.add(&two);
	one.add(&b);
	two.add(&c);
	two.add(&d);
	two.add(&three);
	three.add(&e);
	one.ls();

	
	/////////////////////////////
	// 1) 實作 remove function
	
	one.remove( &b );
	two.remove( &c );
	one.ls();
	/////////////////////////////
	
	// 2) add 重複: 不加入

	one.add( &a );			//重複: 不加入a
	one.ls();
	
	/////////////////////////////
	// 3) 修改 AbsFile*  files_[10]; 成動態記憶體分配 (realloc)

	File 	 a1("a1"), a2("a2"), a3("a3"), a4("a4"), a5("a5"),  a6("a6"), a7("a7"), a8("a8"), a9("a9"), a10("a10");
	one.add( &a1 );
	one.add( &a2 );
	one.add( &a3 );
	one.add( &a4 );
	one.add( &a5 );
	one.add( &a6 );
	one.add( &a7 );
	one.add( &a8 );
	one.add( &a9 );
	one.add( &a10 );
	one.ls();


	/**/
}

/*
輸出:

1:
a
2:
c
d
3:
e
b

*/