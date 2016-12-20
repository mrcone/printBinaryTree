#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;

class Node{
public:
	Node *Right;
	Node *Left;
	int data;
	Node(int dat, Node *lft, Node *rght){
		this->data=dat;
		this->Left=lft;
		this->Right=rght;
	}
};

class Tree{
public:
	int sizeTree(Node *node) const {
	    return (node == NULL)? 0 : sizeTree(node->Left) + sizeTree(node->Right) + 1;
	}

	void printTree(Node *root, int factorHeight=1){
	    std::queue<Node *> queueNode;
	    int ceilSize=log2(sizeTree(root)+1);
	    queueNode.push(root);
	    int pot=0;
	    while(queueNode.size() > 0){
	      int levels = queueNode.size();
		      while(levels > 0){
		        Node *nodeAux = queueNode.front(); 
		        queueNode.pop();
		        cout <<setw( (levels==pow(2,pot))?pow(2, (ceilSize-pot+factorHeight)):pow(2, (ceilSize-pot+factorHeight+1)));
		        cout<< nodeAux->data;
		        if(nodeAux->Left != NULL) queueNode.push(nodeAux->Left);
		        if(nodeAux->Right != NULL) queueNode.push(nodeAux->Right);
		        levels--;
		      }
		      pot++;
		      cout << endl;
	    }
  	}
};

int
main(int argc, char **argv){
	Tree *abb=new Tree();
	//Tree left
	Node *node10=new Node(10, NULL, NULL);
	Node *node30=new Node(30, NULL, NULL);
	Node *node20=new Node(20, node10, node30);
	Node *node39=new Node(39, NULL, NULL);
	Node *node49=new Node(49, NULL, NULL);
	Node *node45=new Node(45, node39, node49);
	Node *node40=new Node(40, node20, node45);

	//Tree right
	Node *node60=new Node(60, NULL, NULL);
	Node *node69=new Node(69, NULL, NULL);
	Node *node65=new Node(65, node60, node69);
	Node *node80=new Node(80, NULL, NULL);
	Node *node100=new Node(100, NULL, NULL);
	Node *node90=new Node(90, node80, node100);
	Node *node70=new Node(70, node65, node90);	

	//Raiz
	Node *node50=new Node(50, node40, node70);

	abb->printTree(node50);
}
