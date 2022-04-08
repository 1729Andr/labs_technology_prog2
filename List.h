#pragma once
class List
{
	friend List operator ++(List &, int);			//а++ добавление в начало случ число 0-10
	friend List operator --(List &, int);			//а-- удаление элемента из начала

	struct Node {
		int data;
		Node *next;		//ссылка на след элемент
	};
private:
	Node *front;	//ссылка на первый элемент
	Node *rear;		//ссылка на последний элемент

	int removeFromFront();			//извлечь первый элемент из списка(removeFromFront);
	int removeFromBack();			//извлечь последний элемент из списка(removeFromBack);
	void addToBack(int value);		//добавить элемент в конец списка(addToBack);
	void addToFront(int value);		//добавить элемент в начало списка(addToFront);

protected:
	int count;

public:
	explicit List();
	List(const List &);
	~List();

	void clearList();			//очистка
	void print();				//вывод
	
	List& operator ++();		//++а добавление элемента в конец
	List& operator --();		//--а удаление элемента с конца

};