#include<iostream>
#include<vector>
#include<string>
#include"binary_search_tree.h"
using namespace std;

void bst::insert(const int type, const string bookname, const string authors, const string price) {
	book temp = { bookname, authors, price };
	if (tree.size() == 0)
		tree.push_back(temp);
	else {
		int i = 1;
		while (tree[i - 1].bookName.size()) {
			switch (type) {
			case 1:
				i = i * 2 + (tree[i - 1].bookName.compare(bookname) == -1 ? 1 : 0);
				break;
			case 2:
				i = i * 2 + (tree[i - 1].authors.compare(authors) == -1 ? 1 : 0);
				break;
			case 3:
				i = i * 2 + (tree[i - 1].price.compare(price) == -1 ? 1 : 0);
				break;
			default:
				cout << "type¿é¤J¿ù»~" << endl;
				return;
			}
			if (i - 1 >= tree.size())
				larg_tree();
		}
		tree[i - 1] = temp;
	}
}

void bst::del(int type, string str) {
	for (vector<book>::iterator i = tree.begin(); i != tree.end(); ++i)
		if (!i->bookName.compare(str) || !i->authors.compare(str) || !i->price.compare(str))
			initial_book(*i);
}

void bst::search(int type, string str) {
	int n = 0;
	for (vector<book>::iterator i = tree.begin(); i != tree.end(); ++i) {
		if (!i->bookName.compare(str) || !i->authors.compare(str) || !i->price.compare(str)) {
			cout << "yes" << endl;
			print_book(*i);
			n = 1;
		}
	}
	if (n == 0)
		cout << "No" << endl;
}

void bst::larg_tree() {
	book temp;
	initial_book(temp);
	int size = (tree.size() + 1) * 2;
	for (int i = tree.size(); i < size; i++)
		tree.push_back(temp);
}

void bst::print_book_big5(const book& book){
	for (int i = 0; i < book.bookName.size(); i++)
		cout << (int)book.bookName.at(i) << " ";
	cout << endl;
	for (int i = 0; i < book.authors.size(); i++)
		cout << (int)book.authors.at(i) << " ";
	cout << endl;
	for (int i = 0; i < book.price.size(); i++)
		cout << (int)book.price.at(i) << " ";
	cout << endl;
}

void bst::inorder(void(*ptr_f) (const book&), int i){
	if (i - 1 >= tree.size())		return;
	inorder(ptr_f,i * 2);
	if (tree[i - 1].bookName == "") return;
	else (ptr_f)(tree[i - 1]);
	inorder(ptr_f,i * 2 + 1);
}