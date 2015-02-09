void iter_inorder(node)
{
	//use stack
	STACK stack[MAX];
	for(;;)
	{
		for(;node;node->left)
			stack_add(&stack,node);
		node a = pop(&stack)
		if(stack.empty())
			break;
		output;
		node=node->right;
	}
}

//compare with recursive method

//层序遍历
void level_order(tree_pointer ptr)
{
	int front = rear = 0;
	tree_pointer queue[MAX];
	//if empty tree
	if(!ptr) return;
	addq(fron,&rear,ptr);
	while(1)
	{
		ptr = deleteq(&&front,rear);
		if(ptr)
		{
			printf("%d",ptr->data);
			if(ptr->left_child)
			{
				addq(front,&rear,ptr->left_child);
			}
			if(ptr->right_child)	
			{
				addq(front,&rear,ptr->right_child);
			}
			else break;
		}
	}


}
