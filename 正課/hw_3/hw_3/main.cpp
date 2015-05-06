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
	char type;									//比較方式     1 bookName BIG5內碼大小結果 BIG5內碼包含兩個位元組	   2 authors BIG5內碼大小結果    3 price 
	bst bst;
	while (getline(fin, read, ' ')){
		switch (read[0]){
		case 'I':										//input function
			getline(fin, num, ' ');						//type to input
			type = num[0];
			type -= '0';
			getline(fin, blank, '"');
			getline(fin, bookname, '"');				//get bookname				
			getline(fin, blank, '"');
			getline(fin, authors, '"');					//get author's name
			getline(fin, blank, ' ');
			getline(fin, price_num, ' ');				//get price
			bst.insert(type, bookname, authors, price_num);//do insert
			getline(fin, blank, '\n');
			break;
		case '?':										//search function
			getline(fin, num, ' ');						//type to search
			type = num[0] - '0';
			switch (type){
			case 1:									//type 1---seach by booknams
				getline(fin, blank, '"');
				getline(fin, bookname, '"');
				bst.search(type, bookname);
				break;
			case 2:									//type 2---search by author's name
				getline(fin, blank, '"');
				getline(fin, authors, '"');
				bst.search(type, authors);
				break;
			case 3:									//type 3---seach by price
				getline(fin, price_num, ' ');
				bst.search(type, price_num);
				break;
			}
			getline(fin, blank, '\n');
			break;
		case 'D':										//delete book
			getline(fin, num, ' ');
			type = num[0] - '0';								//type for search book to delete
			switch (type){
			case 1:									//delete book by bookname
				getline(fin, blank, '"');
				getline(fin, bookname, '"');
				bst.del(type, bookname);
				break;
			case 2:									//delete book by author's name
				getline(fin, blank, '"');
				getline(fin, authors, '"');
				bst.del(type, authors);
				break;
			case 3:									//delete book by price
				getline(fin, price_num, ' ');
				bst.del(type, price_num);
				break;
			}
			getline(fin, blank, '\n');
			break;
		case 'B':										//print BIG-5
			bst.print_tree_big5();
			getline(fin, blank, '\n');
			break;
		case 'P':										//print books
			bst.print_tree();
			getline(fin, blank, '\n');
			break;
		case 'C':										//Clean all books
			bst.clean();
			getline(fin, blank, '\n');
			break;
		default:
			cout << "error" << endl;
			getline(fin, blank, '\n');
			break;
		}
	}
}
	/*
	while (getline(fin, read, ' ')) {
		construct = read[0];
		if (construct == 'I') {                   //input function inputs
			getline(fin, num, ' ');
			type = num[0];
			type -= '0';
			getline(fin, blank, '"');
			getline(fin, bookname, '"');				//get bookname				
			getline(fin, blank, '"');
			getline(fin, authors, '"');					//get author's name
			getline(fin, blank, ' ');
			getline(fin, price_num, ' ');				//get price
			bst.insert(type, bookname, authors, price_num);//do insert
		}
		else if (construct == '?') {                    //search function inputs
			getline(fin, num, ' ');						//get type to search
			type = num[0];
			type -= '0';
			if (type == 1) {							//type 1 seach by booknams
				getline(fin, blank, '"');
				getline(fin, bookname, '"');
				bst.search(type, bookname);

			}
			else if (type == 2) {						//type 2 search by author's name
				getline(fin, blank, '"');
				getline(fin, authors, '"');
				bst.search(type, authors);
			}
			else if (type == 3) {						//type 3 seach by price

				getline(fin, price_num, ' ');
				bst.search(type, price_num);
			}
		}
		else if (construct == 'D') {                    //delete function
			getline(fin, num, ' ');
			type = num[0];
			type -= '0';
			if (type == 1) {							//delete book by bookname
				getline(fin, blank, '"');				
				getline(fin, bookname, '"');
				bst.del(type, bookname);
			}
			else if (type == 2) {						//delete book by author's name
				getline(fin, blank, '"');				
				getline(fin, authors, '"');	
				bst.del(type, authors);
			}
			else if (type == 3) {						//delete book by price
				getline(fin, price_num, ' ');
				bst.del(type, price_num);
			}
		}
		else if (construct == 'P') {					//print books
			bst.print_tree();		
		}
		else if (construct == 'B') {					//print by BIG-5
			bst.print_tree_big5();
		}
		else if (construct == 'C') {					//Clean all books
			bst.clean();
		}
		getline(fin, blank, '\n');
	}
}
*/