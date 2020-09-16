#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

template <class etp>
class ln_tb{
	public:
		struct elem{
			etp m_key;
			elem* m_lf;
			elem* m_rt;
		};
		elem* tag;
		elem* head;
	public:
		ln_tb(){
			elem tag_e;
			tag = &tag_e;
			head = &tag_e;
			tag->m_key = 0;
			tag->m_lf = NULL;
			tag->m_rt = NULL;
		};
		ln_tb(etp key){
			elem * tag_e = new elem;
			tag_e->m_lf = NULL;
			tag_e->m_rt = NULL;
			tag_e->m_key = key;
			tag = tag_e;
			head = tag;
		};
		~ln_tb() {clear_all(head);}
		void add_elem(etp key){
			elem * tag_e = new elem;
			tag_e->m_key = key;
			tag_e->m_lf = tag;
			tag_e->m_rt = NULL;
			tag->m_rt = tag_e;
			tag = tag_e;
		}
		void delete_elem(){
			elem * tmp;
			tmp = tag;
			if(tag->m_lf != NULL)
			{
				tag = tag->m_lf;
				tag->m_rt = NULL;
				delete tmp;
				cout << "DELETE successfully!" << endl;
			}
			else {cout << "DELETE ERROR: Can't delete the Head." << endl;}
		}
		int length(){
			elem * c;
			c = head;
			int count = 1;
			while(c->m_rt!=NULL){
				count++;
				c = c->m_rt;
			}
			return count;
		}
	private:
		void clear_all(elem* E){
			if(E->m_rt != NULL) { clear_all(E->m_rt); };
			delete E;
			cout << "delete one of the elements successfully..." << endl;
		}
};


int main()
{
	ln_tb<int> linear_table(1);
	for (int i=2;i<=4;i++)
		{
			linear_table.add_elem(i);
			//cout << linear_table.tag->m_key << endl;
		}
	cout << linear_table.length() << endl;
	/*
	cout << linear_table.tag->m_lf->m_key << endl;
	cout << linear_table.tag->m_lf->m_lf->m_key << endl;
	cout << linear_table.tag->m_lf->m_lf->m_lf->m_key << endl;
	*/
	cout << linear_table.head->m_key << endl;
	
	cout << linear_table.head->m_rt->m_key<< endl;
	for(int i=1;i<=4;i++)
	{linear_table.delete_elem();}
	/*
	cout << linear_table.tag->m_key << endl;
	linear_table.delete_elem();
	cout << linear_table.tag->m_key << endl;
	*/
	//cout << linear_table.head->m_lf->m_key << endl;
	//for (int i=1;i<=4;i++)
	//	{cout << linear_table.tag->key;
	return 0;
}
