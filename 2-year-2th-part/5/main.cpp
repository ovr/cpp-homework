#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

template <class T> class BinaryTree {
public:
	struct Node {
		Node *left, *right;
		T data;

		Node () : left(NULL), right(NULL) {}
		Node (T x) : left(NULL), right(NULL), data(x) {}
	};
private:
	Node *root;
	size_t size = 0;

	void p_add (Node*& cur, T x);
	bool p_find (Node* cur, T x);
public:
	void add (T x);
	bool find (T x);
	size_t getSize () { return size; }

	void toArray(Node* tree, T a[]);
	void sort(T a[], int elem_total);
};

template <class T> void BinaryTree <T> :: p_add (Node*& cur, T x) {
	if (!cur) {
		cur = new Node (x);
		return;
	}
	if (x < cur->data) {
		if (!cur->left)
			cur->left = new Node (x);
		else
			p_add (cur->left, x);
	}
	else if (x > cur->data) {
		if (!cur->right)
			cur->right = new Node (x);
		else
			p_add (cur->right, x);
	}
}

template <class T> bool BinaryTree <T> :: p_find (Node* cur, T x) {
	if (!cur) {
		return false;
	}

	if (x < cur->data) {
		if (!cur->left) {
			return false;
		}

		return p_find (cur->left, x);
	} else if (x > cur->data) {
		if (!cur->right) {
			return false;
		}

		return p_find (cur->right, x);
	}

	return true;
}

template <class T> void BinaryTree <T> :: add (T x) {
	size++;
	p_add (root, x);
}

template <class T> bool BinaryTree <T> :: find (T x) {
	return p_find (root, x);
}

template <class T> void BinaryTree <T> :: toArray(Node* tree, T a[]) {
	static int max2 = 0;                 // счетчик элементов нового массива

	if (tree == NULL) {
		return;
	}

	toArray(tree->left, a);       // обход левого поддерева
	a[max2++] = tree->data;
	toArray(tree->right, a);      // обход правого поддерева
}

template <class T> void BinaryTree <T> :: sort(T a[], int count) {
	Node *root = NULL;

	for (size_t i = 0; i < count; i++) {        // проход массива и заполнение дерева
		p_add(root, a[i]);
		this->size++;
	}
	toArray(root, a);             // заполнение массива
}

int main () {
	BinaryTree <int> btree = BinaryTree<int>();

	int a[6]= {
		12,
		4,
		55,
		2,
		1,
		5
	};

	btree.sort(a, 6);

	cout << "Sorted array of int variables: " << endl;
	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}

	cout << endl;

	return 0;
}