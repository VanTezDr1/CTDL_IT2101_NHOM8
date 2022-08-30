#include <iostream>
using namespace std;
#define COUNT 10
//cau1.1: khai bao cau truc NPTK
struct Node {
	int info;
	Node* left;
	Node* right;
};
Node* root;
//Cau1.2 Khoi tao cay rong
void Init()
{
	root == NULL;
}
//Cau 1.3 Them mot phan tu su dung DE QUY
int Insert_Node_Recursive(int x, Node* q)
{
	if (q->info == x)
		return 0;
	else if (q->info > x)
	{
		if (q->left == NULL)
		{
			Node* p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->left = p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x, q->right);
	}
	else
	{
		if (q->right == NULL)
		{
			Node* p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->right = p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x, q->right);
	}
}
void InsertNode(Node*& p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return;
		else if (p->info > x)
			return InsertNode(p->left, x);
		else
			return InsertNode(p->right, x);
	}
}
//1.4 Tim 1 phan tu dung de quy
Node* Search(Node* p, int x)
{
	if (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (x > p->info)
				return Search(p->right, x);
			else
				return Search(p->left, x);
	}
	return NULL;
}
//Cau 1.5 Xoa 1 nut trong cay dung de quy
void SearchStanFor(Node*& p, Node*& q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		SearchStanFor(p, q->left);
}
int Delete(Node*& T, int x)
{
	if (T == NULL) return 0;
	if (T->info == x)
	{
		Node* p = T;
		if (T->left == NULL) //Bac 1
			T = T->right;
		else if (T->right == NULL) // Bac 1
			T = T->left;
		else  //co 2 con
			SearchStanFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x) return Delete(T->right, x);
	if (T->info < x) return Delete(T->left, x);
}
//Cau 1.6 Duyet cay theo NLR dung de quy
void DuyetLNR(Node* p)
{
	if (p != NULL)
	{
		DuyetLNR(p->left);
		cout << p->info << " ";
		DuyetLNR(p->right);
	}
}
//Cau 1.7 Duyet cay theo NLR dung de quy
void DuyetNLR(Node* p)
{
	if (p != NULL)
	{
		DuyetNLR(p->left);
		cout << p->info << " ";
		DuyetNLR(p->right);
	}
}
//Cau 1.8 Duyet cay theo LNR dung de quy
void DuyetLRN(Node* p)
{
	if (p != NULL)
	{
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout << p->info << " ";
	}
}
void print2DUtil(Node* p, int space)
{
	//base case
	if (p == NULL)
		return;
	//Increase distance between levels
	space += COUNT;
	//Process right child firsr
	print2DUtil(p->right, space);
	//Print current node after space
	//cout 
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << "\n";
	//Process left child
	print2DUtil(p->left, space);
}
//Wrapper over print2DUtil()
void Process_Tree()
{
	//Pass initial space count as 0
	print2DUtil(root, 0);
}
int main()
{
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << "=======Bai tap 1, chuong 4, CAY NPTK========\n";
	cout << "1. Khoi tao cay NPTK rong\n";
	cout << "2. Them phan tu vao cay NPTK\n";
	cout << "3.Tim phan tu co gia tri x tron cay NPTK\n";
	cout << "4.Xoa phan tu co gia tri x trong cay NPTK\n";
	cout << "5.Duyet cay NPTK theo LNR\n";
	cout << "6.Duyet cay NPTK theo NLR\n";
	cout << "7. Duyet cay NPTK theo LRN\n";
	cout << "8.Xua cay NPTK\n";
	cout << "9.Thoat\n";
	do
	{
		cout << "Vui long chon so dee thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Init();
			cout << "Ban vua khoi tao cay NPTK thanh cong!\n";
			break;
		case 2:
			cout << "Nhap gia x can them: ";
			cin >> x;
			InsertNode(root, x);
			cout << "Cay NPTK sau khi them la: ";
			Process_Tree();
			break;
		case 3:
			cout << "Nhap gia tri x can tim: ";
			cin >> x;
			p = Search(root, x);
			if (p != NULL)
				cout << "Tim thay x= " << x << "trong cay NPTK" << endl;
			break;
		case 4:
			cout << "Nhap gia tri x can xoa: ";
			cin >> x;
			i = Delete(root, x);
			if (i == 0)
				cout << "Khong tim thya x = " << x << "de xoa " << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu x = " << x << "trong cay NPTK" << endl;
				cout << "Cay NPTK sau khi xoa la: ";
				Process_Tree();
			}
			break;
		case 5:
			cout << "Cay NPTK duyet theo LNR la: ";
			DuyetLNR(root);
			break;
		case 6:
			cout << "Cay NPTK duyet theo NLR la: ";
			DuyetNLR(root);
			break;
		case 7:
			cout << "Cay NPTK duyet theo LRN la: ";
			DuyetLRN(root);
			break;
		case 8:
			cout << "Cay NPTK nhu sau: ";
			Process_Tree();
			break;
		case 9:
			cout << "Goodbye.........!\n";
			break;
		}
	} while (choice != 9);
	system("pause");
	return 0;
}