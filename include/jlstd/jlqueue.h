#ifndef JLQUEUE_H
#define JLQUEUE_H
typedef struct jlqueue jlqueue;
jlqueue* jlqueue_ctor();
void jlqueue_dtor( jlqueue* queue );
void jlqueue_enqueue( jlqueue* queue, void* value );
void* jlqueue_dequeue( jlqueue* queue );
bool jlqueue_isempty( jlqueue* queue );
void* jlqueue_front( jlqueue* queue );
void* jlqueue_back( jlqueue* queue );
#endif // JLQUEUE_H