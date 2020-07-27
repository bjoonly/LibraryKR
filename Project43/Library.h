#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct  Book {
	string author;
	string name;
	int year;
	int numberBooks;

	Book(string author = "Unknown", string name = "Unknown", int year = 0, int numberBooks = 0);
	friend ostream& operator<<(ostream& out, const Book& book);
	friend istream& operator>>(istream& in, Book& book);
};

class Library {
	struct SortByAuthor {
		bool operator()(const Book& b1, const Book& b2) {
			return b1.author < b2.author;
		}
	};
	struct SortByYear {
		bool operator()(const Book& b1, const Book& b2) {
			return b1.year < b2.year;
		}
	};
	struct SortByName {
		bool operator()(const Book& b1, const Book& b2) {
			return b1.name < b2.name;
		}
	};

	vector<Book>books;
	bool isValidPos(size_t pos);
public:

	void AddBook(const Book& book);
	void RemoveBook(int pos);
	void ShowByAuthor();
	void ShowByName();
	void ShowByYear();
};