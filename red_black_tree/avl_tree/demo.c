//avl tree insert and use LEFT and RIGHT ROTATION
#define IS_FULL(ptr) (!(ptr))
#define FALSE 0
#define TRUE 1
//left_rotation_function
void left_rotation(tree_pointer *parent,int *unbalanced);
//right_rotation_function
void right_rotation(tree_pointer *parent,int *unbalanced);
typedef struct{
	int key;
}element;

typedef struct tree_node *tree_pointer;
		struct tree_node{
			tree_pointer left_child;
			element data;
			short int bf;
			tree_pointer right_child;
		}
int unblanced = FALSE;
tree_pointer root = NULL;

void avl_insert(tree_pointer *parent,element x,int *unbalanced)
{
	if (!*parent)
	{
		//insert in null_tree is equal to CREATING a new tree
		*unbalanced = TRUE;
		*parent = (tree_pointer)malloc(sizeof(tree_ndoe));
	   if(IS_FULL(*parent))	
	   {
	   		fprintf(stderr,"memory is full");
			exit(1);
	   }
	   (*parent)->left_child=(*parent)->right_child=NULL;
	   (*parent)->bf=0
	   (*parent)->data=x;
	}
	else if(x.key < (*parent)->data.key)
	{
		avl-insert(&(*parent)->left_child,x,unbalanced);
		if(unbalanced)
			switch((*parent)->bf)
			{	
				case -1:
					(*parent)->bf = 0;
					*unbalanced = FALSE;
					break;
			
				case 0:
					(*parent) ->bf = 1; break;

				case 1:
					left_rotation(parent,unbalanced);
			}
		
	}

	else if(x.key>(*parent)->data.key)
	{
		avl_insert(&(*parent)->right_child,x,unbalanced);
		if(unbalanced)
			switch((*parent)->bf)
			{	
				case -1:
					(*parent)->bf = 0;
					*unbalanced = FALSE;
					break;
			
				case 0:
					(*parent)->bf = 1; break;

				case 1:
					right_rotation(parent,unbalanced);
			}	
	}

	else
	{
		*unbalanced = FALSE;
		printf("duplicate in the avl_tree")
	}
}

