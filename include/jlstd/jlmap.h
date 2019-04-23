#ifndef JLMAP_H
#define JLMAP_H
typedef struct jlmap jlmap;
jlmap* jlmap_ctor( int size );
void jlmap_dtor( jlmap** map );
int jlmap_hash( char* key );
void jlmap_set( jlmap* map, char* key, void* value );
void* jlmap_get( jlmap* map, char* key );
#endif // JLMAP_H