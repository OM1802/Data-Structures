#include <iostream>
using namespace std;

#define COUNT 7

/* A structure representing a node of a tree.*/
struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* create(int);
Node* insertion(Node* , int);
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);
void Search(Node*, int);
void printBST(Node* , int);

int main()
{
  Node* root = NULL;
  int n, element;
  char ch;
  int choice=0;
    cout<<"\n********* Binary Search Tree operations *********\n";

    while(choice != 7)
    {
        cout<<"\n********************************************\n";
        cout<<"\n\nChose one from the below options...\n";
        cout<<"\n1.Insert an element into BST\n2.Search an element in BST\n3.Inorder Traversal of BST\n4.Preorder Traversal of BST\n5.Postorder Traversal of BST\n6.Display BST\n7.Exit\n";
        cout<<"\n********************************************\n";
        cout<<"\n Enter your choice \n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter element to Insert into BST :\t";
                cin>>element;
                root = insertion(root, element);
                cout<<"\nElement Successfully Inserted...\n";
                break;
            }
            case 2:
            {
                cout<<"\nEnter the Element to be searched: ";
                cin>>n;
                Search(root, n);
                break;
            }
            case 3:
            {
                cout<<"\n The In-order traversal of the given binary search tree is - \n\n";
                inorder(root);
                cout<<"\n\n";
                break;
            }
            case 4:
            {
                cout<<"\n The Pre-order traversal of the given binary search tree is - \n\n";
                preorder(root);
                cout<<"\n\n";
                break;
            }
            case 5:
            {
                cout<<"\n The Post-order traversal of the given binary search tree is - \n\n";
                postorder(root);
                cout<<"\n\n";
                break;
            }
            case 6:
            {
                cout<<"\nGenerated Binary Search Tree is as follows: \n\n";
                printBST(root, 2);
                break;
            }
            case 7:
            {
                cout<<"\nProgram Terminating... Thank you.\n";
                break;
            }
            default:
            {
                cout<<"\nPlease Enter valid choice??\n";
            }
        }
    }

 /* {45, 30, 50, 25, 35, 46, 60, 4} */

  return 0;
}


/* A function creating new node of the tree and assigning the data. */
Node* create(int item)
{
    Node* newnode = new Node;
    newnode->data = item;
    newnode->left = newnode->right = NULL;

    return newnode;
}

/* A function creating binary search tree. */
Node* insertion(Node* root, int item)
{
    if (root == NULL)
        return create(item); /*return new node if tree is empty*/
    if (item < root->data)
        root->left = insertion(root->left, item);
    else
        root->right = insertion(root->right, item);

    return root;
}

/* A Function to print In-order traversal of the tree formed*/
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left); /* traverse left subtree */

    cout<< root->data << "   "; /*traverse root node */

    inorder(root->right); /* traverse right subtree */
}

/* A Function to print Pre-order traversal of the tree formed*/
void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout<< root->data << "   "; /*traverse root node */
    preorder(root->left); /* traverse left subtree */
    preorder(root->right); /* traverse right subtree */
}

/* A Function to print Post-order traversal of the tree formed*/
void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left); /* traverse left subtree */
    postorder(root->right); /* traverse right subtree */
    cout<< root->data << "   "; /*traverse root node */

}

/* A function to search item in given BST. */
void Search(Node *root, int item)
{
	int depth = 0;
	Node *temp = new Node;
	temp = root;
	/* Run the loop until temp points to a NULL pointer. */
	while(temp != NULL)
	{
		depth++;
		if(temp->data == item)
		{
			cout<<"\n Item found at depth: "<<depth<<endl;
			return;
		}
		/* Shift pointer to left child. Start Search in left subtree */
		else if(temp->data > item)
			temp = temp->left;
		/* Shift pointer to right child. Start Search in right subtree */
		else
			temp = temp->right;
	}

	cout<<"\n Item not found in given BST...\n";
}

/* A function to display generated BST. */
void printBST(Node* root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    printBST(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    // Process left child
    printBST(root->left, space);
}
