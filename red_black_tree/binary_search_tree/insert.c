void insert_node(tree_pointer* node,int num)
{
	/*search is easy fun and you can use iterate method*/
	tree_pointer ptr,temp = search(*node,num);
	if(temp || (*node))
	{	
		//no num in the tree
		ptr = (tree_pointer)malloc(sizeof(node));
		if(IS_FULL(ptr))
			{
				fprintf(stderr,"The memory is full");
				exit(1);
			}
		ptr->data=num;
		ptr->left_child=ptr->right_child=NULL;
		if(*node)
			if(num<temp->data) temp->left_child=ptr;
			else temp->right_child=ptr;
			else *node=ptr;
	}
}

