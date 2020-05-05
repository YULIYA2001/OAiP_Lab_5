#ifndef QueueH
#define QueueH

struct Node
{
	int x;
    Node *Next, *Prev;
};

class Queue
{
	public:
	Node *Head, *Tail;
	Queue() : Head(NULL), Tail(NULL){}  //�����������
	~Queue();                           //���������� (������� �������)
	void Show(TListBox*);				//��������
	void Add(int);						//���������� �������� � �����
	void Delete(TEdit*);				//�������� �������� �� ������
	void IsEmpty(TEdit*);				//�������� �� �������
};


#endif
