#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Queue
{
	int data;
	Queue* next;
};

struct Queue* Init();
int  ListLength(Queue** list);
void AddToBegin(Queue** list, int val);
void AddToEnd(Queue** list, int val);
void PrintList(Queue* list);
void FreeMemory(Queue** list);
void DeleteNode(Queue** list, Queue** node);
void Unpackage(Queue** list, int listLen);


int main()
{
	Queue* begin = NULL;
	AddToBegin(&begin, 2);
	AddToBegin(&begin, 1);
	AddToEnd(&begin, 3);
	AddToEnd(&begin, 4);
	AddToEnd(&begin, 5);
	AddToEnd(&begin, 6);
	AddToEnd(&begin, 7);
	AddToEnd(&begin, 8);
	PrintList(begin);
	Unpackage(&begin, ListLength(&begin));
	PrintList(begin);

	system("PAUSE");
	return 0;
}

struct Queue* Init()
{
	Queue* list;
	list = new Queue;
	list->next = NULL;

	return list;
}

int  ListLength(Queue** list)
{
	Queue* temp = Init();
	temp = *list;
	int len = 0;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return len;
}

void AddToBegin(Queue** list, int val)
{
	Queue* start;
	start = Init();

	start->data = val;
	start->next = *list;
	*list = start;
}

void AddToEnd(Queue** list, int val)
{
	Queue* end;
	end = Init();
	end->data = val;
	end->next = NULL;

	Queue* tail;
	tail = *list;
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = end;
}

void PrintList(Queue* list)
{
	Queue* temp;
	temp = list;
	while (temp)
	{
		cout << temp->data << " ---> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

void FreeMemory(Queue** list)
{
	if (*list == NULL)
		return;

	Queue* temp = *list;
	Queue* temp1;

	while (temp)
	{
		temp1 = temp;
		temp = temp->next;
		delete temp1;
	}

	*list = NULL;
}

void DeleteNode(Queue** list, Queue** node)
{

	if ((*node)->next == NULL) {
		Queue* temp = *list;
		Queue* head = temp;

		while (temp->next != *node) {
			temp = temp->next;
		}
		temp->next = NULL;
		*list = head;
		return;
	}
	Queue* temp = *node;
	Queue* nxt = temp->next;
	temp->data = nxt->data;
	temp->next = nxt->next;
}

void Unpackage(Queue** list, int listLen)
{
	Queue *head;
	head = *list;
	Queue *repack = Init();
	while (listLen) {

		if (listLen == 1) {
			AddToEnd(&repack, head->data);
			*list = repack->next;
			return;
		}

		if (listLen == 2) {
			AddToEnd(&repack, head->data);
			head = head->next;
			AddToEnd(&repack, head->data);
			*list = repack->next;
			return;
		}

		AddToEnd(&repack, head->data);
		DeleteNode(list, &head);
		head = *list;
		listLen--;

		while (head->next != 0) {
			head = head->next;
		}

		AddToEnd(&repack, head->data);
		DeleteNode(list, &head);
		head = *list;
		listLen--;

	}
}
