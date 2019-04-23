typedef struct jlstack
{
	jlstack* next;
	void* value;
} jlstack;

jlstack* jlstack_ctor( void* value, jlstack* node )
{
	jlstack* stack = malloc( sizeof( jlstack ) );
	stack->next    = node;
	stack->value   = value;
	return stack;
}

void jlstack_dtor( jlstack** stack )
{
	jlstack* cur = *stack;

	for( ; *stack != NULL; )
	{
		*stack = cur->next;
		free( cur );
		cur = *stack;
	}
}

void jlstack_push( jlstack** stack, void* value )
{
	jlstack* node = jlstack_ctor( value, *stack );
	*stack = node;
}

void* jlstack_pop( jlstack** stack )
{
	jlstack* head = *stack;
	void* value = head->value;
	*stack = head->next;
	free( head );
	return value;
}

void* jlstack_top( jlstack** stack )
{
	jlstack* head = *stack;
	return head->value;
}

void jlstack_map( jlstack* stack, void (*cb)( void* value ) )
{
	if( stack->next != NULL ) jlstack_map( stack->next, cb );
	cb( stack->value );
}