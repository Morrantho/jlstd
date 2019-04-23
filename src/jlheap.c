typedef struct jlheap
{
	int* data;
	int size;
	jlheap_type type;
} jlheap;

jlheap* jlheap_ctor( jlheap_type type )
{
	jlheap* heap = malloc( sizeof( jlheap ) );
	heap->data   = malloc( sizeof( int ) );
	heap->size   = 1;
	heap->type   = type;
	return heap;
}

void jlheap_dtor( jlheap** heap )
{
	jlheap* h = *heap;
	free(h->data);
	h->data = NULL;
	free(h);
	h->size = 0;
	*heap = NULL;
}

int jlheap_size( jlheap* heap )
{
	return heap->size;
}

void jlheap_doinsert( jlheap* heap, int value, int child )
{
	if( child <= 1 ) return;
	int parent = ( child / 2 ) << 0;

	if( 
		( heap->type == JL_HEAP_MIN && ( heap->data[ child ] < heap->data[ parent ] || heap->data[ parent ] == 0 ) ) ||
		( heap->type == JL_HEAP_MAX && ( heap->data[ child ] > heap->data[ parent ] || heap->data[ parent ] == 0 ) )
	)
	{

		int t = heap->data[ child ];
		heap->data[ child ]  = heap->data[ parent ];
		heap->data[ parent ] = t;
		jlheap_doinsert( heap, t, parent );
	}
}

void jlheap_insert( jlheap* heap, int value )
{
	heap->data = realloc( heap->data, heap->size++ );
	heap->data[ heap->size-1 ] = value;
	jlheap_doinsert( heap, value, heap->size-1 );
}

void jlheap_doextract( jlheap* heap, int child )
{
	int left  = child * 2, right = child * 2 + 1;
	if( left > heap->size-1 || right > heap->size-1 ) return;
	int side  = heap->data[ left ] <= heap->data[ right ] ? left : right;
	if( heap->type == JL_HEAP_MAX ) side = heap->data[ left ] > heap->data[ right ] ? left : right;
	heap->data[ child ] = heap->data[ side ];
	jlheap_doextract( heap, side );
}

int jlheap_extract( jlheap* heap )
{
	if( heap->size <= 1 ) return 0;
	int value = heap->data[ 1 ];
	jlheap_doextract( heap, 1 );
	heap->data = realloc( heap->data, heap->size-- );
	return value;
}

int jlheap_peek( jlheap* heap, int index )
{
	if( heap->data[ index ] != 0 )
		return heap->data[ index ];
	else
		return 0;
}