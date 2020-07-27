#include "Library.h"
ostream& operator<<(ostream& out, const Book& book) {
	out << "Aunthor: " << book.author << "\nName: " << book.name << "\nYear: " << book.year << "\nNumber books: " << book.numberBooks << endl;
	return out;
}
istream& operator>>(istream& in, Book& book) {
	in.ignore(12233, '\n');
	system("cls");
	cout << "Enter author: ";
	getline(in, book.author);
	system("cls");
	cout << "Enter name: ";
	getline(in, book.name);
	do {
		system("cls");
		cout << "Enter year: ";
		in >> book.year;
	} while (book.year < 0);
	do {
		system("cls");
		cout << "Enter number of books: ";
		in >> book.numberBooks;
	} while (book.numberBooks < 0);
	return in;
}

bool Library::isValidPos(size_t pos) {
	return pos >= 1 && pos <= books.size();
}

void Library::AddBook(const Book& book) {
	books.push_back(book);
}

void Library::RemoveBook(int pos) {
	if (isValidPos(pos))
		books.erase(books.begin() + pos - 1);

}

void Library::ShowByAuthor() {
	sort(books.begin(), books.end(), SortByName());
	for (size_t i = 0; i < books.size(); i++) {
		cout << i + 1 << "." << books[i] << endl;
	}
}

void Library::ShowByName() {
	sort(books.begin(), books.end(), SortByName());
	for (size_t i = 0; i < books.size(); i++) {
		cout << i + 1 << "." << books[i] << endl;
	}
}

void Library::ShowByYear() {
	sort(books.begin(), books.end(), SortByYear());
	for (size_t i = 0; i < books.size(); i++) {
		cout << i + 1 << "." << books[i] << endl;
	}
}

Book::Book(string author, string name, int year, int numberBooks)
	:author(author), name(name), year(year), numberBooks(numberBooks) {}