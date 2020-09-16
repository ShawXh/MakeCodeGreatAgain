#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class type>
class  bTree{
	public:
		struct Node{
			type key;
			Node * p = NULL;
			Node * lch = NULL;
			Node * rch = NULL;
		};
	public:
		Node * root;
		bTree(){
			root = new Node;
			root->key = 0;
			root->p = NULL;
			root->lch = NULL;
			root->rch = NULL;
		};
		bTree(type k){
			root = new Node;
			root->key = k;
			root->p = NULL;
			root->lch = NULL;
			root->rch = NULL;
		};
		~bTree() {
			//cout<<"~bTree"<<endl; 
			//remove_subTree(root); 
		}
		void insert( Node * &tmp ,const type k){
			if(tmp != NULL){
				if(k == tmp->key){
					cout <<"ERROR: key "<< k << " existed." << endl;
				}
				else if(k < tmp->key){
					Node * t;
					t = tmp->lch;
					insert( tmp->lch, k);
					if (t == NULL){
						tmp->lch->p = tmp;
					}
				}
				else if(k > tmp->key){
					Node * t;
					t = tmp->rch;
					insert( tmp->rch, k);
					if (t == NULL){
						tmp->rch->p = tmp;
					}
				}
			}
			else if(tmp == NULL){
				Node * new_node = new Node;
				new_node->key = k;
				tmp = new_node;
			}
		};
		
		bool find(const type x){
			Node * tag;
			tag = root;
			while(tag != NULL){
				if(tag->key == x){
					return true;
				}
				else if(x < tag->key){
					tag = tag->lch;
				}
				else if(x > tag->key){
					tag = tag->rch;
				}
			}
			return false;
		};
		void remove_subTree(Node * node){
			if (node == NULL) { 
				cout << "The tree is empty." << endl;
				return; 
			}
			if (node->lch != NULL){
				remove_subTree(node->lch);
			}
			if (node->rch != NULL){
				remove_subTree(node->rch);
			}
			if (node == root){
				
			}
			else if (node->p->lch == node){
				node->p->lch = NULL;
			}
			else if (node->p->rch == node){
				node->p->rch = NULL;
			}
			delete node;
		};
		void remove_element_x(type x){	
		};
		Node* maximum( Node * node){
			if( node == NULL){
				cout <<"ERROR: The input node doesn't exist."<< endl;
				return NULL;
			}
			else{
				Node * tmp;
				tmp = node;
				while( tmp->rch != NULL ){
					tmp = tmp->rch;
				}
				return tmp;
			}
		};
		
		Node* successor(Node * node){
			if( node == NULL){
				cout <<"ERROR: The input node doesn't exist."<< endl;
				return NULL;
			}
			if( node->rch != NULL ){
				return maximum(node);
			}
			else{
				Node* tmp;
				Node* s;
				s = node;
				tmp = node->p;
				if( tmp==NULL ) { cout<<"No successor!"<<endl; return NULL;}
				while(tmp!= NULL && tmp->rch==s){
					s = s->p;
					tmp = tmp->p;
				}
				if(tmp==NULL){ cout<<"No successor!"<<endl; return NULL;}
				else{ return tmp;}
			}
		};
		
		void pre_order_show(const Node * node){
			if (node->lch != NULL){
				pre_order_show(node->lch);
			}
			if (node->rch != NULL){
				pre_order_show(node->rch);
			}
			cout << node->key;
		};
		void mid_order_show(const Node * node){
			if (node->lch != NULL){
				mid_order_show(node->lch);
			}
			cout << node->key;
			if (node->rch != NULL){
				mid_order_show(node->rch);
			}
		};
		void post_order_show(const Node * node){
			cout << node->key;
			if (node->lch != NULL){
				mid_order_show(node->lch);
			}
			if (node->rch != NULL){
				mid_order_show(node->rch);
			}
		};
};

int main(){
	bTree<int> bt(9);
	bt.insert(bt.root,3);
	
	int a[8] = {9,3,5,8,2,7,4,6};
	for(int i=0;i<8;i++){
		bt.insert(bt.root,a[i]);
	}
	/*
	cout << bt.root->key<<endl;
	cout << bt.root->lch->key<<endl;
	cout << bt.root->lch->lch->key << endl;
	cout << bt.root->lch->rch->key << endl;
	cout << bt.root->lch->rch->rch->key << endl; 
	cout << bt.root->lch->rch->lch->key << endl;
	cout << bt.find(5) << endl;
	cout << bt.find(10) << endl;
	*/
	/*
	bt.pre_order_show(bt.root);
	cout << '\n';
	bt.remove_subTree(bt.root->lch->rch);
	bt.mid_order_show(bt.root);
	cout << '\n';
	*/
	/*
	cout << bt.maximum(bt.root->lch)->key << endl;
	bt.mid_order_show(bt.root);
	cout << '\n';
	bt.remove_subTree(bt.root->lch->rch->rch);
	bt.mid_order_show(bt.root);
	cout <<endl<< bt.maximum(bt.root->lch)->key << endl;
	*/
return 0;
}
