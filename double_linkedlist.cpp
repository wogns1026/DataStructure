/*
double linked list�� single linked list�� �ٸ��� �ϳ��� ��尡
���� ���� ���� ��带 ����Ű�� �����͸� ��� ������ ����
(������ ������ 2��)
�������� single linked list�� ����
*/

#include <iostream>

using namespace std;

class Node {
	friend class List;
private : 
	int val;
	Node *next_node;
	Node *prev_node;
public : 
	Node(int = 0, Node * = NULL, Node * = NULL);
	int retval();
	Node *next();
	Node *prev();
};

class List {
private : 
	Node *head;
	Node *tail;
	int cnt;
public : 
	List();
	bool empty(); // O(1)
	int front(); // O(1)
	int back(); // O(1)
	int list_size(); // O(1)
	void push_front(int); // O(1)
	void push_back(int); // O(1)
	void pop_front(); // O(1)
	void pop_back(); // O(1) => ���� ���� ����Ʈ������ O(n)�� �ɷ����� 
					// ���� ���� ����Ʈ������ ��尡 ���� ����� �ּҸ� �˰� �����Ƿ� O(1)�� �ɸ�
	~List();
};

Node::Node(int v, Node *n, Node *p) : val(v), next_node(n), prev_node(p) {

}
int Node::retval() {
	return val;
}
Node *Node::next() {
	return next_node;
}
Node *Node::prev() {
	return prev_node;
}

List::List() : head(NULL), tail(NULL), cnt(0) {

}
bool List::empty() {
	if (cnt == 0)
		return true;
	return false;
}
int List::front() {
	return head->retval();
}
int List::back() {
	return tail->retval();
}
int List::list_size() {
	return cnt;
}
void List::push_front(int v) {
	Node *tmp = new Node(v);
	if (cnt == 0) {
		head = tmp;
		tail = tmp;
	}
	else {
		tmp->next_node = head;
		head->prev_node = tmp;
		head = tmp;
	}
	cnt++;
}
void List::push_back(int v) {
	Node *tmp = new Node(v);
	if (cnt == 0) {
		head = tmp;
		tail = tmp;
	}
	else {
		tmp->prev_node = tail;
		tail->next_node = tmp;
		tail = tmp;
	}
	cnt++;
}
void List::pop_front() {
	Node *tmp = head;
	if (head == tail) {
		head = NULL;
		tail = NULL;
	}
	else {
		head->next_node->prev_node = NULL;
		head = tmp->next();
	}
	delete tmp;
	cnt--;
}
void List::pop_back() {
	Node *tmp = tail;
	if (head == tail) {
		head = NULL;
		tail = NULL;
	}
	else {
		tail->prev_node->next_node = NULL;
		tail = tmp->prev();
	}
	delete tmp;
	cnt--;
}
List::~List() {

}

int main() {
	List *list = new List();
	list->push_front(5);
	list->push_back(4);
	cout << list->front() << '\n';
	cout << list->back() << '\n';
	cout << list->list_size() << '\n';
	list->pop_back();
	cout << list->back() << '\n';
	cout << list->empty() << '\n';
	list->pop_back();
	cout << list->empty() << '\n';


	return 0;
}