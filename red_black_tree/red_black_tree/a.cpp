#include<iostream>
#include<stdio.h>
#define BLACK 0
#define RED 1

using namespace std;

//template class red black tree
template<class valueType>
struct R_B_NODE
{
	valueType data;
	int color;
	R_B_NODE<valueType> *left;
	R_B_NODE<valueType> *right;
	R_B_NODE<valueType> *parent;
	R_B_NODE()
	{   color = BLACK;   }
	R_B_NODE(valueType key){   
		//default color RED
		/*
		 *when insert node in red_black_tree, 
		 *node should use red in order to keep  
		 *other node balance above the current 
		 *node
		 * */
		color = RED;   
		data = key;
}
};

template<class valueType>
class R_B_TREE
{
	public:
		R_B_TREE();
		~R_B_TREE();
		//inorder traversal
		void mid_out(R_B_NODE<valueType> *node);
		void insert_data(valueType key);
		void delete_data(valueType key);
		R_B_NODE<valueType> *root;
		R_B_NODE<valueType> *NIL;
	
	private:
		R_B_NODE<valueType> *find(valueType key);
		R_B_NODE<valueType> *finsucce(R_B_NODE<valueType> *key);
		//rotation function
		void lefrot(R_B_NODE<valueType> *node);
		void rigrot(R_B_NODE<valueType> *node);
		//destroy tree root
		void desno_tre(R_B_NODE<valueType> *root);
		
		void insert_b(R_B_NODE<valueType> *node);
   		void Era_b(R_B_NODE<valueType> *node);		
};

template<class valueType>
R_B_TREE<valueType>:: R_B_TREE()
{
	NIL = new R_B_NODE<valueType>();
	root = NIL;
}

template<class valueType>
R_B_TREE<valueType>:: ~R_B_TREE()
{
	if(NIL != root)
	{
		desno_tre(root);
	}
	delete NIL;
}

template<class valueType>
void R_B_TREE<valueType>::desno_tre(R_B_NODE<valueType> *root)
{
	if(NIL != root->left)
		desno_tre(root->left);
	if(NIL != root->right)
		desno_tre(root->right);
	delete root;
}

template<class valueType>
R_B_NODE<valueType>* R_B_TREE<valueType>:: finsucce(R_B_NODE<valueType> *key)
{
	if (NIL == key->right)
	{
		R_B_NODE<valueType> *parent = key->parent;
		while(parent != NIL && key == parent->right)
			{
				parent = key;
				key = key->parent;
			}
	}	
	else
	{
		key = key->right;
		while (NIL != key->left)
		{
			key = key->left;
		}
	}
	return key;
}

//inorder
template<class valueType>
void R_B_TREE<valueType>::mid_out(R_B_NODE<valueType> *node)
{
	if(NIL != node)
	{
		mid_out(node->left);
		cout<< node->data <<endl;
		mid_out(node->right);
	}
}

template<class valueType>
void R_B_TREE<valueType>::lefrot(R_B_NODE<valueType> *node)
{
	R_B_NODE<valueType> *temp = node->right;
	node->right = temp->left;
	if(NIL != temp->left)
	{
		temp->left->parent = node;
	}
	temp->parent = node->parent;
	if (temp->parent == NIL)
	{
		root = temp;  
	}
	else if(node == node->parent->left)
	{
		node->parent->left = temp;
	}
	else
	{
		node->parent->right = temp;
	}
	temp->left = node;
	node->parent = temp;
}

template<class valueType>
void R_B_TREE<valueType>::rigrot(R_B_NODE<valueType> *node)
{
	R_B_NODE<valueType> *temp = node->left;
	node -> left = temp -> right; 
	if(NIL != node -> left)
	{
		node -> left -> parent = node;
	}
	temp->parent = node->parent;
	if(node->parent == NIL)//node can be changed by the temp
	{
		root = temp;
	}
	else if(node->parent->left == node )
	{
		node->parent->left = temp;
	}
	else
	{
		node->parent->right = temp;
	}
	//complete child and father connection
	temp->right = node;
	node->parnet = temp;
}

template<class valueType>
R_B_NODE<valueType>* R_B_TREE<valueType>::find(valueType key)
{
	R_B_NODE<valueType>* ROOT = root;
	while(ROOT != NIL)
	{
		if(key == ROOT->data)
		{
			break;
			// return ROOT;
		}
		else if(key < ROOT->data)
		{
			ROOT = ROOT->left;
		}

		else
		{
			ROOT = ROOT->right;
		}
	}
	return ROOT;
	//NULL
}

template<class valueType>
void R_B_TREE<valueType>::insert_data(valueType key)
{
	//if find exist same value,return
	if (NIL != find(key))
	{
		return;
	}

	//define two temporary vairable
	R_B_NODE<valueType> *pre = NIL;
	R_B_NODE<valueType> *cur = root;
	R_B_NODE<valueType> *newnode = new R_B_NODE<valueType>(key);
	
	while(cur != NIL)
	{
		pre = cur;
		//go to left based on bin_search_tree attribute
		if(cur->data > key)
		{
			cur = cur->left;
		}
		//go to right
		else
		{
			cur = cur->right;
		}	
		newnode->parent = pre;
	}

	if(NIL==pre)
	{
		//build a tree
		root = newnode;
	}

	//choose the newnode attribute left child or right child
	else if(key < pre->data)
	{
		pre->left = newnode;
	}
	else
	{
		pre->right = newnode;
	}
	newnode->left = NIL;
	newnode->right = NIL;

	//balance operation
	insert_b(newnode);
}

template<class valueType>
void R_B_TREE<valueType>::insert_b(R_B_NODE<valueType>* node)
{
	while(node->parent->color == RED)
	{
		R_B_NODE<valueType>* u;
		if(node->parent == node->parent->parent->left)
		{
			u = node->parent->parent->right;
			if (RED == u->color)
			{
				node->parent->color = BLACK;
				u->color = BLACK;
				node->parent->parent->color = RED;
			}
			else
			{
				//left rotation?
				if(node == node->parent->right)
				{
					node = node->parent;
					lefrot(node);
				}	
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				rigrot(node->parent->parent);	
			}		
		}	
		else
		{
			u = node->parent->parent->left;
			if(RED == u->color)
			{
				node->parent->color = BLACK;
				u->color = BLACK;
				node->parent->parent->color = RED;
			}
			else
			{
				if(node == node->parent->left)
				{
					node = node->parent;
					rigrot(node);
				}
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				lefrot(node);
			}
		}
	}
}

template<class valueType>
void R_B_TREE<valueType>::delete_data(valueType key)
{
	R_B_NODE<valueType>* del_node;
	R_B_NODE<valueType>* del_node_child;
	R_B_NODE<valueType>* target = find(key);

	//no key
	if(NIL == target)
	{
		return ;
	}

	if(NIL == target->left || NIL == target->right)
	{
		del_node = target;
	}
	else
	{
		del_node = finsucce(target);
	}

	if(NIL == del_node->left)
	{
		del_node_child = del_node->right;
	}
	else
	{
		del_node_child = del_node->left;
	}

	del_node_child->parent = del_node->parent;
	if(NIL == del_node->parent)
	{
		root = del_node_child;
	}
	else if(del_node == del_node->parent->left)
	{
		del_node->parent->left = del_node_child;
	}
	else
	{
		del_node->parent->right = del_node_child;
	}

	if(del_node != target)
	{
		target->data = del_node->data;
	}
	if(BLACK == del_node->color)
	{
   		Era_b(del_node);			
	}
	delete del_node;
}

template<class valueType>
void R_B_TREE<valueType>::Era_b(R_B_NODE<valueType> *node)
{
	R_B_NODE<valueType> *brother;
	while (node != root && node->color != BLACK)
	{
		if(node == node->parent->left)
		{
			brother = node->parent->right;

			if(brother->color == RED)
			{
				brother->color = BLACK;
				node->parent->color = RED;
				lefrot(node->parent);
				brother = node->parent->right;
			}
		
			if(BLACK == brother->left->color && BLACK == brother->right->color)
			{
				brother->color = RED;
				node =node->parent;	
			}
			else if(BLACK == brother->right->color)
			{
				brother->left->color = BLACK;
				brother->color = RED;
				rigrot(brother);
				brother = node->parent->right;
			}
			else
			{
				brother->color = node->parent->color;
				node->parent->color = BLACK;
				brother->right->color = BLACK;
				lefrot(node->parent);
				node = root;
			}
			
		}
		else
		{
			brother = node->parent->left;
		    
			if(RED == brother->color)
			{
				brother->color = BLACK;
				node->parent->color =  RED;
				rigrot(node->parent);
				brother = node->parent->left;
			}
		    if(BLACK == brother->left->color && BLACK == brother->right->color)
			{
				brother->color = RED;
				node = node->parent;
			}	
			else if(BLACK == brother->left->color)
			{
				brother->right->color = BLACK;
				brother->color = RED;
				lefrot(brother);
				brother = node->parent->left
			}
			else
			{
				brother->color = node->parent->color;
				node->parent->color =BLACK;
				brother->left->color = BLACK;
				rigrot(node->parent);
				node = root;
			}
		}
	}
	node->color = BLACK;
}


