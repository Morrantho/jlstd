#ifndef JLSTACK_H
#define JLSTACK_H
typedef struct jlstack jlstack;
jlstack* jlstack_ctor( void* value, jlstack* node );
void jlstack_dtor( jlstack** stack );
void jlstack_push( jlstack** stack, void* value );
void* jlstack_pop( jlstack** stack );
void* jlstack_top( jlstack** stack );
void jlstack_map( jlstack* stack, void (*cb)( void* value ) );
#endif // JLSTACK_H