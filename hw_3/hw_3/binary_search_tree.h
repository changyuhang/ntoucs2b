#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct book{
	string bookName;
	string authors;
	string price;
};

class bst{
public:
	void insert(const int, const string, const string, const string);
	void search(const int, const string);
	void del(const int, const string);
	void print_tree();
	void print_tree_big5();
	void clean() { tree.clear(); }
	//~bst();
private:
	void larg_tree();
	void print_book(const book book) { cout << book.bookName << " " << book.authors << " " << book.price << endl; }
	void initial_book(book&);
	vector<book> tree;
};