/*
C++第三次作業
作者:張語航、吳彥誠
時間:2015/04/27
基本上都寫完了inorder輸出跟big5輸出沒寫(我懶得寫了...)
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
	char construct;								//I=輸入		?=搜尋		D=刪除 P依照InOrder順序將目前樹中的書籍資料列印出來	B依照InOrder順序將目前樹中的書籍資料列印出來 但是列印出 BIG5內碼
	char type;									//比較方式     1 bookName BIG5內碼大小結果 BIG5內碼包含兩個位元組	   2 authors BIG5內碼大小結果    3 price 
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