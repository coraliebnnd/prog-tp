#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct SearchTreeNode : public Node
{    
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;

    void initNode(int value)
    {
        // init initial node without children
        this->left = nullptr;
        this->right = nullptr;
        this->value = value;
    }

	void insertNumber(int value) {
        // create a new node and insert it in right or left child
        if(value < this->value){
            if(this->left == nullptr){
                this->left = new SearchTreeNode(value);
            }else{
               this->left->insertNumber(value);
            }
        }else{
            if(this->right == nullptr){
                this->right = new SearchTreeNode(value);
            }else{
                this->right->insertNumber(value);
            }
        }
    }

	uint height() const	{
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        int heightLeft = 0;
        int heightRight = 0;

        if(this->left != nullptr){
           heightLeft = this->left->height();
        }

        if(this->right != nullptr){
            heightRight = this->right->height();;
        }

        if(heightLeft < heightRight){
            return heightRight+1;
        }else{
            return heightLeft+1;
        }
    }

	uint nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1

        int sumLeft = 0;
        int sumRight = 0;

        if(this->left != nullptr){
           sumLeft = this->left->nodesCount();
        }

        if(this->right != nullptr){
            sumRight = this->right->nodesCount();
        }

        return sumRight+sumLeft+1;
	}

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        if(this->left == nullptr && this->right == nullptr){
            return true;
        }else{
            return false;
        }
	}

	void allLeaves(Node* leaves[], uint& leavesCount) {
        // fill leaves array with all leaves of this tree
        if(this->isLeaf()){
            leaves[leavesCount] = this;
            leavesCount++;
        }else{
            if(this->left != nullptr){
                this->left->allLeaves(leaves, leavesCount);
            }

            if(this->right != nullptr){
                this->right->allLeaves(leaves, leavesCount);
            }
        }
	}

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel
        if(this->left != nullptr){
            this->left->inorderTravel(nodes, nodesCount);
        }

        nodes[nodesCount] = this;
        nodesCount++;

        if(this->right != nullptr){
            this->right->inorderTravel(nodes, nodesCount);
        }
	}

	void preorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel
        nodes[nodesCount] = this;
        nodesCount++;

        if(this->left != nullptr){
            this->left->preorderTravel(nodes, nodesCount);
        }

        if(this->right != nullptr){
            this->right->preorderTravel(nodes, nodesCount);
        }
	}

	void postorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel
        if(this->left != nullptr){
            this->left->postorderTravel(nodes, nodesCount);
        }

        if(this->right != nullptr){
            this->right->postorderTravel(nodes, nodesCount);
        }

        nodes[nodesCount] = this;
        nodesCount++;
	}

	Node* find(int value) {
        // find the node containing value
        if(this->value == value){
            return this;
        }else{
            if(this->left != nullptr){
                return this->left->find(value);
            }

            if(this->right != nullptr){
                return this->right->find(value);
            }
        }

        return nullptr;
	}

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    SearchTreeNode(int value) : Node(value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new SearchTreeNode(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<SearchTreeNode>();
	w->show();

	return a.exec();
}
