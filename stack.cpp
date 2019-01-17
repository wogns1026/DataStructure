/*
링크드 리스트로 stack을 구현 
=> 리스트로 구현하면 스택의 크기가 정해져있지 않고 동적으로 늘어날 수 있다는 장점이 있음
stack은 한 쪽 끝에서만 데이터를 넣고 뺄 수 있는 선형구조
마지막에 넣은 데이터가 먼저 나오는 LIFO구조
queue와 다르게 prev 노드를 가르키는 포인터가 필요!

(template 사용하지 않고 구현함 => template을 사용하면 시간이 오래 걸린다고 함)
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