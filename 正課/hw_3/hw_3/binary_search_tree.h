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
	void print_tree(){ inorder(&bst::print_book); }
	void print_tree_big5(){ inorder(&bst::print_book_big5); }
	void clean() { tree.clear(); }
	~bst(){ tree.clear(); }
private:
	void larg_tree();
	static void print_book(const book& book) { cout << book.bookName << " " << book.authors << " " << book.price << endl; } 
	static void print_book_big5(const book&);
	void initial_book(book& book){ book = { "", "", "" }; }
	void inorder( void(*ptr_f)(const book&), int i = 1);
	vector<book> tree;
};