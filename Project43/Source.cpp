#include"Library.h"
//Написати програму обліку книг у бібліотеці.Дані  про  книги  містять :
//прізвище  й  ініціали  автора, назву, рік  видання, кількість  примірників 
//даної  книги  в  бібліотеці.Програма  повинна забезпечувати  вибір  за  допомогою  
//меню  і  виконання однієї  з  наступних функцій :
//додавання даних про книги, що тільки надходять у бібліотеку;
//видалення даних про книги, що списуються; 
//видача даних про всі книги, впорядкованих за прізвищами авторів;
//видача даних про всі книги, впорядкованих за роками видання.
//Збереження даних організувати з застосуванням контейнерного класу vector.


int main() {
	Library lib;
	Book tmp;
	int pos;
	int action;
	do {
		system("cls");
		cout << "Enter action:\n1.Add book\n2.Delete book\n3.Show by name\n4.Show by author\n5.Show by year\n0.Exit\n";
		cin >> action;
		system("cls");
		switch (action) {
		case 1:
			cin >> tmp;
			lib.AddBook(tmp);
			break;
		case 2:
			lib.ShowByName();
			cout << "\nEnter position of book: ";
			cin >> pos;
			lib.RemoveBook(pos);
			break;
		case 3:
			lib.ShowByName();
			system("pause");
			break;
		case 4:
			lib.ShowByAuthor();
			system("pause");
			break;
		case 5:
			lib.ShowByYear();
			system("pause");
			break;
		case 0:
			cout << "Bye!";
			break;
		default:
			cout << "Invalid value.";
		}
	} while (action != 0);
	return 0;
}