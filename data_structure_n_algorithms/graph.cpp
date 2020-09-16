#include <cstring>
#include <iostream>
#include <stdlib.h>

const int MAXSIZE = 15;
using namespace std;

class graph{
	public:
		struct vertex{
			string name;
			string color;
			int d;
		};
		struct element_in_table{
			element_in_table* prev = NULL;
			vertex* key = NULL;
			element_in_table* next = NULL;
		};
		vertex *V[MAXSIZE];
		element_in_table *T[MAXSIZE];
		struct queue_type{
			vertex *Q[MAXSIZE];
			int head;
			int tail;
		};
		queue_type Queue;
	public:
		graph(){
			for(int i=0;i<MAXSIZE;i++){
				V[i] = NULL;
				T[i] = NULL;
				Queue.Q[i] = NULL;
			}
			Queue.head = Queue.tail = 0;
		};
		void create_vertex_by_name( string k){
			vertex *v = new vertex;
			v->name = k;
			element_in_table *t = new element_in_table;
			t->k`ey = v;
			for(int i=0;i<MAXSIZE;i++){
				if(V[i] == NULL){
					//cout << i << endl;
					V[i] = v;
					T[i] = t;
					break;
				}
			}
		};
		int get_vertex_index_by_name( string k){
			int i;
			i = 0;
			while(V[i] != NULL){
				if(V[i]->name == k){
					return i;
				}
				i++;
				if(i>=MAXSIZE){
					cerr << "ERROR: Space for vertex isn't enough."
						 << endl;
					return -1;
				}
			}
			cerr << "ERROR: The vertex doesn't exist."
				 << endl;
			return -1;
		}
		vertex * get_vertex_by_index( int i){
			if(i>=0){
				return V[i];
			}
			else{
				cerr << "ERROR: The index doesn't exist."
					 << endl;
				return NULL;
			}
		}
		void create_edge( string a, string b){
			cout << "Building edge between "
				 << "vertex " << a << " and " << b << " ..."
				 << endl;
			int i1, i2;
			i1 = get_vertex_index_by_name( a);
			cout << "vertex " << a << " index: " << i1 << endl;
			i2 = get_vertex_index_by_name( b);
			cout << "vertex " << b << " index: " << i2 << endl;
			element_in_table *t1 = new element_in_table;
			element_in_table *t2 = new element_in_table;
			element_in_table *tmp;
			tmp = T[i1];
			while(tmp->next!=NULL){
				tmp = tmp->next;
			}
			t1->key = V[i2];
			t1->prev = tmp;
			tmp->next = t1;
			cout << "Edge " << a << "->" << b 
				 << " has been built." << endl;
			tmp = T[i2];
			while(tmp->next!=NULL){
				tmp = tmp->next;
			}
			t2->key = V[i1];
			t2->prev = tmp;
			tmp->next = t2;
			cout << "Edge " << b << "->" << a
				 << " has been built." << endl;
		}
		void enqueue( vertex *v){
			if( (Queue.tail+1) == MAXSIZE){
				Queue.Q[Queue.tail] = v;
				Queue.tail = 0 ;
			}
			else{
				Queue.Q[Queue.tail] = v;
				Queue.tail = Queue.tail + 1;
			}
		}
		vertex* dequeue(){
			vertex *tmp;
			tmp = Queue.Q[Queue.head];
			Queue.Q[Queue.head] = NULL;
			if( (Queue.head+1) == MAXSIZE){
				Queue.head = 0;
			}
			else{
				Queue.head += 1;
			}
			return tmp;
		}
		bool queue_is_empty(queue_type q){
			return( q.head == q.tail);
		}
		void reset_color_and_distance_all(){
			int i;
			i = 0;
			while(V[i]!=NULL && i<MAXSIZE){
				V[i]->color = "white";
				V[i]->d = 0xffff;
				i++;
			}
		}
		void BFS( string s){
			reset_color_and_distance_all();
			int i;
			i = get_vertex_index_by_name( s);
			vertex *v;
			v = V[i];
			v->color = "gray";
			v->d = 0;
			enqueue(v);
			vertex *u;
			while(!queue_is_empty(Queue)){
				u = dequeue();
				u->color = "black";
				i = get_vertex_index_by_name( u->name);
				// i is u's index in the table;
				element_in_table *tmp;
				tmp = T[i];
				// tmp is vertex u of table form;
				while(tmp->next!=NULL){
					tmp = tmp->next;
					if(tmp->key->color == "white"){
						tmp->key->color = "gray";
						tmp->key->d = u->d + 1;
						enqueue(tmp->key);
					}
				}
			}
		}
		void print_BFS_route( string s, string o){
			int oi,tmpi,tmpd;
			oi = get_vertex_index_by_name( o);
			BFS( s);
			element_in_table *tmp;
			tmp = T[oi];
			tmpd = tmp->key->d;
			cout << "The route: ";
			while(tmpd != 0){
				cout << tmp->key->name << "<<";
				while(tmp->key->d != (tmpd-1)){
					tmp = tmp->next;
				}
				tmpi = get_vertex_index_by_name( tmp->key->name);
				tmp = T[tmpi];
				tmpd = tmp->key->d;
			}
			cout << tmp->key->name << endl;
		}
};


int main(){
	graph G;	//it is a ordinary triangle.
	G.create_vertex_by_name("a");
	//cout << G.T[0]->key->name << endl;
	G.create_vertex_by_name("b");
	//cout << G.T[1]->key->name << endl;
	G.create_vertex_by_name("c");
	G.create_vertex_by_name("d");
	G.create_vertex_by_name("e");
	G.create_vertex_by_name("f");
	G.create_edge("a","b");
	//cout << G.T[0]->next->key->name << endl;
	//cout << G.T[1]->key->name << endl;
	//cout << G.T[1]->next->key->name << endl;
	G.create_edge("b","c");
	G.create_edge("c","e");
	//G.create_edge("b","e");
	//G.create_edge("d","e");
	G.create_edge("a","d");
	G.create_edge("d","f");
	G.create_edge("e","f");
	//G.create_edge("a","b");
	/*
	G.BFS("f");
	cout << G.V[0]->d << endl;
	cout << G.V[1]->d << endl;
	cout << G.V[2]->d << endl;
	cout << G.V[3]->d << endl;
	cout << G.V[4]->d << endl;
	cout << G.V[5]->d << endl;
	*/
	G.print_BFS_route("f","b");
return 0;
}
