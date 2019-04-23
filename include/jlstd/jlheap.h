#ifndef JLHEAP_H
#define JLHEAP_H
typedef enum jlheap_type
{
	JL_HEAP_MIN = 10,
	JL_HEAP_MAX = 20
} jlheap_type;

typedef struct jlheap jlheap;
jlheap* jlheap_ctor( jlheap_type type );
void jlheap_dtor( jlheap** heap );
int jlheap_size( jlheap* heap );
void jlheap_insert( jlheap* heap, int value );
int jlheap_extract( jlheap* heap );
int jlheap_peek( jlheap* heap, int index );
#endif // JLHEAP_H