#pragma once
class List
{
	friend List operator ++(List &, int);			//�++ ���������� � ������ ���� ����� 0-10
	friend List operator --(List &, int);			//�-- �������� �������� �� ������

	struct Node {
		int data;
		Node *next;		//������ �� ���� �������
	};
private:
	Node *front;	//������ �� ������ �������
	Node *rear;		//������ �� ��������� �������

	int removeFromFront();			//������� ������ ������� �� ������(removeFromFront);
	int removeFromBack();			//������� ��������� ������� �� ������(removeFromBack);
	void addToBack(int value);		//�������� ������� � ����� ������(addToBack);
	void addToFront(int value);		//�������� ������� � ������ ������(addToFront);

protected:
	int count;

public:
	explicit List();
	List(const List &);
	~List();

	void clearList();			//�������
	void print();				//�����
	
	List& operator ++();		//++� ���������� �������� � �����
	List& operator --();		//--� �������� �������� � �����

};