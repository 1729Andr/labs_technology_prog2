#include <iostream>
#include <ctime>
#include "List.h"

using namespace std;

List::List() {
	count = 0;
	front = NULL;
	rear = NULL;
}

//добавить элемент в конец списка(addToBack);
void List::addToBack(int value) {
	Node *ptr = new Node();
	ptr->data = value;
	ptr->next = NULL;
	count++;

	if (front == NULL) {
		front = ptr;
		rear = ptr;
	}
	else
	{
		rear->next = ptr;
		rear = ptr;
	}
}

//добавить элемент в начало списка(addToBack);
void List::addToFront(int value) {
	Node *ptr = new Node();
	ptr->data = value;
	ptr->next = NULL;
	count++;

	if (front == NULL) {
		front = ptr;
		rear = ptr;
	}
	else
	{
		ptr->next = front;
		front = ptr;
	}
}

//извлечь первый элемент из списка(removeFromFront);
int List::removeFromFront() {
	setlocale(LC_ALL, "ru");
	int res;
	if (count == 0) {
		cout << "Список пустой\n";
	}
	else
	{
		if (count == 1) {
			Node *ptr = front;
			res = ptr->data;
			free(ptr);
			front = NULL;
			rear = NULL;
		}
		else
		{
			Node *ptr = front;
			res = ptr->data;
			front = ptr->next;
			free(ptr);
		}
		count--;
		return res;
	}
}

//извлечь последний элемент из списка(removeFromBack);
int List::removeFromBack() {
	setlocale(LC_ALL, "ru");
	int res;
	if (count == 0) {
		cout << "Список пустой\n";
	}
	else
	{
		if (count == 1) {
			Node *ptr = front;
			res = ptr->data;
			free(ptr);
			front = NULL;
			rear = NULL;
		}
		else
		{
			Node *ptr = front;
			for (int i = 1; i < count - 1; i++)
			{
				ptr = ptr->next;
			}
			res = ptr->next->data;
			rear = ptr;
			free(ptr->next);
			ptr->next = NULL;
		}
		count--;
		return res;
	}
}

void List::print() {
	setlocale(LC_ALL, "ru");
	if (count == 0) {
		cout << "Список пустой\n";
	}
	else {
		Node *ptr = front;
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << " " << endl;
	}
}

//очистка
void List::clearList() {
	while (front != NULL) {
		removeFromFront();
	}
}

List::List(const List& src) {
	count = 0;
	front = NULL;
	rear = NULL;
	Node *ptr = src.front;
	int tmp;
	for (int i = 0; i < src.count; i++)
	{
		tmp = ptr->data;
		this->addToBack(tmp);
		ptr = ptr->next;
	}
}

List::~List() {
	count = 0;
	front = NULL;
	rear = NULL;
}

//++а добавление элемента в конец
List &List::operator ++() {
	int res;
	cin >> res;
	this->addToBack(res);
	return *this;
}

//--а удаление элемента с конца
List &List::operator --() {
	this->removeFromBack();
	return *this;
}

//а++ добавление в начало случ число 0-10
List operator ++(List &l, int a) {
	srand(time(0));
	int rnd = rand() % 11;
	List lst = l;
	lst.addToFront(rnd);
	return lst;
}

//а-- удаление элемента из начала
List operator --(List &l, int a) {
	List lst = l;
	lst.removeFromFront();
	return lst;
}