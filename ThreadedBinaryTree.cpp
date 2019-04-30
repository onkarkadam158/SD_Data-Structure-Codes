#include<iostream>
using namespace std;

struct treeNode
{
	int data;
	treeNode* left;
	treeNode* right;
	bool lthread;
	bool rthread;
};

class Tree
{
	private :
		treeNode* headnode = NULL;
	public :
		Tree()
		{
			headnode = new treeNode();
			headnode->lthread = false;
			headnode->rthread = true;
			headnode->left = headnode->right = headnode;
		}
		void insert(int data)
		{
			treeNode* nn = new treeNode;
			nn->left = NULL;
			nn->right = NULL;
			nn->data = data;
			if(headnode == headnode->left && headnode == headnode->right)
			{
				nn->left = headnode;
				headnode->left = nn;
				nn->lthread = headnode->lthread;
				headnode->lthread = true;
				nn->right = headnode;
			}

			else
			{
				treeNode* current = headnode->left;
				while(true)
				{
					if(current->data > nn->data)
					{
						if(current->lthread == false)
						{
							nn->left = current->left;
							current->left = nn;
							nn->lthread = current->lthread;
							current->lthread = true;
							nn->right = current;
							break;
						}

						else
							current = current->left;
					}

					else
					{
						if(current->rthread == false)
						{
							nn->right = current->right;
							current->right = nn;
							nn->rthread = current->rthread;
							current->rthread = true;
							nn->left = current;
							break;
						}
						else
						{
							current = current->right;
						}
					}

				}

			}

		}

		void inorder()
		{
			treeNode* current = headnode->left;
			while (current->lthread == true)
				current = current->left;

			while (current != headnode)
			{
				cout << current->data;
				if(current->rthread == false)
				{
					current = current->right;
				}
				else
				{
					current = current->right;
					while (current->lthread != false)
					current = current->left;
				}


			}
		}
		void recInorder(treeNode* node)
		{
			if (node != headnode )
			{
				recInorder(node->left);
				cout << node->data << " ";
				recInorder(node->right);
		  	}

		}
		treeNode* getRoot()
		{
			return headnode->left;
		}
}tree;


int main()
{
	char choice='y';
	int ch;
	int data;

	while(choice == 'y')
	{
		cout << "\tMENU" << endl;
		cout << "\t1.insert Binay Search tree node" <<  endl;
		cout << "\t2.Inorder traversal" << endl;
		//cout << "\t3.preorder traversal" << endl;
		//cout << "\t4.postorder traversal" << endl;
		cout << "\tenter your choice" << endl;
		cin >> ch;
		switch(ch)
		{
			case 1:
				cout << "Enter node data: " << endl;
				cin >> data;
				tree.insert(data);
				break;
			case 2 :
				tree.inorder();
				break;
			default :
				cout << "\tINVALID CHOICE" << endl;

		}
		cout << "\tDo you wish to continue" << endl;
		cout << "\tIf yes enter y" << endl;
		cin >> choice;
	}
}

