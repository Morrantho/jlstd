typedef struct jlqueue
{
	jlnode* head;
	jlnode* tail;
} jlqueue;

jlqueue* jlqueue_ctor()
{
	jlqueue* queue = malloc( sizeof( jlqueue ) );
	queue->head    = NULL;
	queue->tail    = NULL;
	return queue;
}

void jlqueue_enqueue( jlqueue* queue, void* value )
{
	if( queue->head == 0 )
	{
		queue->head = jlnode_ctor( value );
		queue->tail = queue->head;
		return;
	}
	queue->tail->next = jlnode_ctor( value );
	queue->tail = queue->tail->next;
}

void* jlqueue_dequeue( jlqueue* queue )
{
	jlnode* head = queue->head;
	void* value  = head->value;

	queue->head  = queue->head->next;
	if( head != NULL ) free( head );
	return value;
}

bool jlqueue_isempty( jlqueue* queue )
{
	return queue->head == NULL;
}

void* jlqueue_front( jlqueue* queue )
{
	jlnode* head = queue->head;
	return head->value;
}

void* jlqueue_back( jlqueue* queue )
{
	jlnode* tail = queue->tail;
	return tail->value;
}

void jlqueue_dtor( jlqueue* queue )
{
	while( !jlqueue_isempty( queue ) )
		jlqueue_dequeue( queue );
}