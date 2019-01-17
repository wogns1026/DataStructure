/*
����Ʈ�� ������ �� ���� new�� ����Ͽ� �������� �޸� �Ҵ��� ���־���.
�ٵ� �� �������� �޸𸮸� �Ҵ��� �ִ� ���� �ð��� ���� �ɸ��ٰ� �Ѵ�.
�׷��� �������� �޸𸮸� �Ҵ��س��� �װ��� �����ٰ� ����Ʈ�� �����ϴ� ����� ���� �Ǿ���.
(�ð��� �������� �޸𸮴� ���� �����)
�׸��� ����ü�� �����غ��� ���� �����ϱ� ���� ����ü�� ����Ͽ� �����غ��Ҵ�.
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
Node nodepool[600005]; // �ʿ��� ����� ������ ����ؼ� �̸� �Ҵ��� ���´�.
Node *newNode() {
	return &nodepool[nodecnt++]; // �Ҵ��س��� ��� �߿��� ���� ��ġ �ּҸ� �����ϰ� nodecnt++ ��
}

struct List {
	Node *head;
	Node *tail;
	int cnt;
	List() : head(NULL), tail(NULL), cnt(0) {

	}
	void push_val(int v) {
		Node *tmp = newNode(); // �������� ��带 �������� �ʰ� �Ҵ�Ǿ� �ִ� ����� �ּҸ� ������
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