/*
��ũ�� ����Ʈ�� stack�� ���� 
=> ����Ʈ�� �����ϸ� ������ ũ�Ⱑ ���������� �ʰ� �������� �þ �� �ִٴ� ������ ����
stack�� �� �� �������� �����͸� �ְ� �� �� �ִ� ��������
�������� ���� �����Ͱ� ���� ������ LIFO����
queue�� �ٸ��� prev ��带 ����Ű�� �����Ͱ� �ʿ�!

(template ������� �ʰ� ������ => template�� ����ϸ� �ð��� ���� �ɸ��ٰ� ��)
*/

#include <iostream>

using namespace std;

class Node {
	friend class List;
private : 
	int val;
	Node *prev_node;
public : 
	Node(int = 0, Node* = NULL);
	int retval();
	Node *prev();
};

class List {
private : 
	int cnt;
	Node *head;
	Node *tail;
public : 
	List();
	bool empty(); // => O(1)
	int stack_size(); // => O(1)
	int top(); // => O(1)
	void push_val(int); // => O(1)
	void pop_val(); // => O(1)
	~List();
};

Node::Node(int v, Node *n) : val(v), prev_node(n) {

}
int Node::retval() {
	return val;
}
Node* Node::prev() {
	return prev_node;
}
List::List() : head(NULL), tail(NULL), cnt(0) {

}
bool List::empty() {
	if (cnt == 0)
		return true;
	return false;
}
int List::stack_size() {
	return cnt;
}
int List::top() {
	return tail->retval();
}
void List::push_val(int v) {
	Node *tmp = new Node(v);
	if (cnt == 0) {
		head = tmp;
		tail = tmp;
	}
	else {
		tmp->prev_node = tail;
		tail = tmp;
	}
	cnt++;
}
void List::pop_val() {
	Node *tmp = tail;
	if (head == tail) {
		head = NULL;
		tail = NULL;
	}
	else {
		tail = tmp->prev();
	}
	delete tmp;	
	cnt--;
}
List::~List() {

}

int main() {
	List *_stack = new List();
	_stack->push_val(1);
	_stack->push_val(2);
	_stack->push_val(3);
	cout << _stack->top() << '\n';
	_stack->pop_val();
	cout << _stack->top() << '\n';
	_stack->pop_val();
	cout << _stack->stack_size() << '\n';
	cout << _stack->empty() << '\n';
	_stack->pop_val();
	cout << _stack->empty() << '\n';

	return 0;
}