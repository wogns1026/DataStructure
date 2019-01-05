/*
single linked list�� �� ��尡 �����Ϳ� �����͸� ������ 
���ٷ� ����Ǿ� �ִ� ������� �����͸� �����ϴ� �ڷᱸ��
�����ʹ� ���� ��� or ���� ������ ������ �����

���� : �迭���� �ٸ��� �߰��� ����� ����, ������ ����****
	=> �ð����⵵�� O(n), ��尡 �� ��(head), �� ��(tail) �κп� ����, ������ ���� O(1)�� ����
���� : Ž������ O(n)�� �ɷ� ������.

Ž���� �幰�� �߰�, ����, ������ ���� ���� ����ϱ� ����
*/

#include <iostream>

using namespace std;

// ���
class Node {
	friend class List; // List�� Node�� private�� ������ �� �ֵ��� �����
private : 
	int value; // ������ ��
	Node *next_node; // ���� ��带 ����Ű�� ������
public : 
	Node(int = 0, Node* = 0); // ������, value�� next_node ������ �� �ʱ�ȭ
	Node *next(); // ���� ����� �ּ� ����
	int retval(); // ����� ������ �� ����
};

// ����Ʈ
class List {
private : 
	int cnt; // list�� �ε���
	Node *head; // list�� head
	Node *tail; // list�� tail
public : 
	List(); // ������, head�� tail�� NULL�� �ʱ�ȭ
	bool empty(); // List�� ����ִ��� Ȯ�� => O(1)
	int front(); // head�� ������ �� ���� => O(1)
	int back(); // tail�� ������ �� ���� => O(1)
	bool find(int); // ���� ���� ������ ������ ������ ��尡 �ִ��� Ȯ�� => O(n)
	int size(); // list�� ũ�⸦ ���� => O(1)
	void push_front(int); // �� �տ� ��� �߰� => O(1)
	void push_back(int); // �� �ڿ� ��� �߰� => O(1)
	void push_idx(int, int); // �߰� �ش� �ε����� ��� �߰� => O(n)
	void pop_front(); // �� �� ��� ���� => O(1)
	void pop_back(); // �� �� ��� ���� => O(n)
	void pop_idx(int); // �ε����� �ش��ϴ� ��带 ���� => O(n)
	void modify(int, int); // ù��° ���� ���� �ε����� ������ ����� ���� �ι�° ���� ������ ������ => O(n)
	void print(); // List�� ��� ����� ������ �� ���� => O(n)
	~List(); // �Ҹ���
};

Node::Node(int v, Node *n) : value(v), next_node(n) {

}
Node *Node::next() {
	return next_node;
}
int Node::retval() {
	return value;
}

List::List() : head(NULL), tail(NULL), cnt(0) {

}
bool List::empty() {
	if (head == NULL)
		return true;
	else
		return false;
}
int List::front() {
	return head->retval();
}
int List::back() {
	return tail->retval();
}
bool List::find(int val) {
	for (Node *ptr = head; ptr != tail->next(); ptr = ptr->next()) {
		if (ptr->retval() == val) {
			return true;
		}
	}
	return false;
}
int List::size() {
	return cnt;
}
void List::push_front(int val) {
	Node *ptr = new Node(val);
	if (head == NULL) {
		head = ptr;
		tail = ptr;
	}
	else {
		ptr->next_node = head;
		head = ptr;
	}
	cnt++;
}
void List::push_back(int val) {
	Node *ptr = new Node(val);
	if (tail == NULL) {
		head = ptr;
		tail = ptr;
	}
	else {
		tail->next_node = ptr;
		tail = ptr;
	}
	cnt++;
}
void List::push_idx(int idx, int val) {
	Node *ptr = new Node(val);
	int num = 0;
	if (idx == 0) {
		push_front(val);
	}
	else if (idx == cnt) {
		push_back(val);
	}
	else {
		for (Node *ptl = head; ptl != tail->next(); ptl = ptl->next()) {
			if (num + 1 == idx) {
				ptr->next_node = ptl->next();
				ptl->next_node = ptr;
				break;
			}
			num++;
		}
		cnt++;
	}
}
void List::pop_front() {
	Node *ptr = head;
	if (head == NULL) {
		cout << "List is empty!\n";
	}
	else {
		head = ptr->next();
		delete ptr;
		cnt--;
	}
}
void List::pop_back() {
	Node *ptr;
	if (tail == NULL) {
		cout << "List is empty\n";
	}
	else if (head == tail) {
		head = NULL;
		tail = NULL;
		cnt--;
	}
	else {
		for (ptr = head; ptr != tail->next(); ptr = ptr->next()) {
			if (ptr->next() == tail) {
				ptr->next_node = NULL;
				tail = ptr;
				break;
			}
		}
		cnt--;
	}
}
void List::pop_idx(int idx) {
	if (idx == 0)
		pop_front();
	else if (idx == cnt - 1)
		pop_back();
	else {
		int num = 0;
		for (Node *ptl = head; ptl != tail->next(); ptl = ptl->next()) {
			if (num + 1 == idx) {
				Node *ptr = ptl->next();
				ptl->next_node = ptr->next();
				delete ptr;
				break;
			}
			num++;
		}
		cnt--;
	}
}
void List::modify(int idx, int newval) {
	int n = 0;
	for (Node *ptr = head; ptr != tail->next(); ptr = ptr->next()) {
		if (n == idx) {
			ptr->value = newval;
			return;
		}
		n++;
	}
	cout << "The value can't be found!\n";
}
void List::print() {
	if (head != NULL) {
		for (Node *ptr = head; ptr != tail->next(); ptr = ptr->next()) {
			cout << ptr->retval() << ' ';
		}
		cout << '\n';
	}
	else {
		cout << "list is empty!\n";
	}
}
List::~List() {

}

int main() {
	List *list = new List();
	list->print();
	list->push_front(3);
	list->print();
	list->push_back(5);
	list->print();
	cout << list->front() << ' ' << list->back() << '\n';
	list->push_idx(1, 4);
	list->print();
	cout << list->find(7) << '\n';
	cout << list->find(4) << '\n';
	cout << list->size() << '\n';
	list->modify(1, 7);
	list->print();
	list->pop_idx(1);
	list->print();
	cout << list->empty() << '\n';
	list->pop_back();
	list->print();
	list->pop_front();
	list->print();

	return 0;
}