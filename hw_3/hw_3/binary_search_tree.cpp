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
	for (vector<book>::iterator i = tree.begin(); i != tree.end(); ++i) {
		switch (type) {
		case 1:
			if (!i->bookName.compare(str)) {
				initial_book(*i);
			}
			break;
		case 2:
			if (!i->authors.compare(str)) {
				initial_book(*i);
			}
			break;
		case 3:
			if (!i->price.compare(str)) {
				initial_book(*i);
			}
			break;
		default:
			break;
		}
	}
	cout << "¦³del" << str << endl;
}

void bst::search(int type, string str) {
	cout << "¦³·j´M" << str << endl;
	for (vector<book>::iterator i = tree.begin(); i != tree.end(); ++i) {
		switch (type) {
		case 1:
		case 2:
		case 3:
			if (!i->bookName.compare(str) || !i->authors.compare(str) || !i->price.compare(str)) {
				cout << "yes" << endl;
				print_book(*i);
			}
			break;
		default:
			break;
		}
	}
}

void bst::print_tree() {
	cout << "print" << endl;
	for (vector<book>::iterator i = tree.begin(); i != tree.end(); ++i) {
		if (i->bookName.size())
			print_book(*i);
	}
}

void bst::print_tree_big5() {

}

void bst::larg_tree() {
	book temp;
	initial_book(temp);
	int size = (tree.size() + 1) * 2;
	for (int i = tree.size(); i < size; i++)
		tree.push_back(temp);
}

void bst::initial_book(book& book) {
	book.bookName = "";
	book.authors = "";
	book.price = "";
}