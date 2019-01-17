/*
리스트를 구현할 때 보통 new를 사용하여 동적으로 메모리 할당을 해주었다.
근데 이 동적으로 메모리를 할당해 주는 것이 시간이 오래 걸린다고 한다.
그래서 정적으로 메모리를 할당해놓고 그것을 가져다가 리스트를 생성하는 방식을 배우게 되었다.
(시간은 빠르지만 메모리는 많이 사용함)
그리고 구조체로 구현해보는 법을 연습하기 위해 구조체를 사용하여 구현해보았다.
*/

#include <iostream>
#include <string>

using namespace std;

struct Node {
	int val;
	Node *next_node;
	Node *prev_node;
};

int nodecnt = 0;
Node nodepool[600005]; // 필요한 노드의 개수를 계산해서 미리 할당해 놓는다.
Node *newNode() {
	return &nodepool[nodecnt++]; // 할당해놓은 노드 중에서 현재 위치 주소를 리턴하고 nodecnt++ 함
}

struct List {
	Node *head;
	Node *tail;
	int cnt;
	List() : head(NULL), tail(NULL), cnt(0) {

	}
	void push_val(int v) {
		Node *tmp = newNode(); // 동적으로 노드를 생성하지 않고 할당되어 있는 노드의 주소를 가져옴
		tmp->val = v;
		if (cnt == 0) {
			head = tmp;
			tail = tmp;
		}
		else {
			tail->next_node = tmp;
			tmp->prev_node = tail;
			tail = tmp;
		}
		cnt++;
	}
	void pop_val() {
		if (head == tail) {
			head = NULL;
			tail = NULL;
		}
		else {
			head->next_node->prev_node = NULL;
			head = head->next_node;
		}
		cnt--;
	}
	int list_size() {
		return cnt;
	}
	bool empty() {
		if (cnt == 0)
			return true;
		return false;
	}
	int front() {
		return head->val;
	}
	int back() {
		return tail->val;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, num = 0;
	cin >> n;
	string s;
	List q;
	while (n--) {
		cin >> s;
		if (s == "push") {
			cin >> num;
			q.push_val(num);
		}
		else if (s == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop_val();
			}
		}
		else if (s == "size") {
			cout << q.list_size() << '\n';
		}
		else if (s == "empty") {
			cout << q.empty() << '\n';
		}
		else if (s == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}

	return 0;
}