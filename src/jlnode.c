typedef struct jlnode
{
	jlnode* next;
	void* value;
} jlnode;

jlnode* jlnode_ctor( void* value )
{
	jlnode* node   = malloc( sizeof( jlnode ) );
	node->next     = NULL;
	node->value    = value;
	return node;
}