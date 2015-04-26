/*
C++�ĤT���@�~
�@��:�i�y��B�d�۸�
�ɶ�:2015/04/27
�򥻤W���g���Finorder��X��big5��X�S�g(���i�o�g�F...)
*/

#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include"binary_search_tree.h"
using namespace std;

int main() {
	fstream fin;
	fin.open("test.txt", ios::in);
	string read, bookname, authors, blank, num, price_num;
	char construct;								//I=��J		?=�j�M		D=�R�� P�̷�InOrder���ǱN�ثe�𤤪����y��ƦC�L�X��	B�̷�InOrder���ǱN�ثe�𤤪����y��ƦC�L�X�� ���O�C�L�X BIG5���X
	char type;									//����覡     1 bookName BIG5���X�j�p���G BIG5���X�]�t��Ӧ줸��	   2 authors BIG5���X�j�p���G    3 price 
	bst bst;

	while (getline(fin, read, ' ')) {
		construct = read[0];
		if (construct == 'I') {                   //input function inputs
			getline(fin, num, ' ');
			type = num[0];
			type -= '0';
			getline(fin, blank, '"');
			getline(fin, bookname, '"');
			getline(fin, blank, '"');
			getline(fin, authors, '"');
			getline(fin, blank, ' ');
			getline(fin, price_num, ' ');
			getline(fin, blank, '\n');
			bst.insert(type, bookname, authors, price_num);
		}
		else if (construct == '?') {                    //search function inputs
			getline(fin, num, ' ');
			type = num[0];
			type -= '0';
			if (type == 1) {
				getline(fin, blank, '"');
				getline(fin, bookname, '"');
				getline(fin, blank, '\n');
				bst.search(type, bookname);

			}
			else if (type == 2) {
				getline(fin, blank, '"');
				getline(fin, authors, '"');
				getline(fin, blank, '\n');
				bst.search(type, authors);
			}
			else if (type == 3) {

				getline(fin, price_num, ' ');
				getline(fin, blank, '\n');
				bst.search(type, price_num);
			}
		}
		else if (construct == 'D') {                    //delete function inputs
			getline(fin, num, ' ');
			type = num[0];
			type -= '0';
			if (type == 1) {
				getline(fin, blank, '"');
				getline(fin, bookname, '"');
				getline(fin, blank, '\n');
				bst.del(type, bookname);
			}
			else if (type == 2) {
				getline(fin, blank, '"');
				getline(fin, authors, '"');
				getline(fin, blank, '\n');
				bst.del(type, authors);
			}
			else if (type == 3) {
				getline(fin, price_num, ' ');
				getline(fin, blank, '\n');
				bst.del(type, price_num);
			}
		}
		else if (construct == 'P') {
			bst.print_tree();
			getline(fin, blank, '\n');
		}
		else if (construct == 'B') {
			bst.print_tree_big5();
			getline(fin, blank, '\n');
		}
		else if (construct == 'C') {
			bst.clean();
			getline(fin, blank, '\n');
		}
	}
}