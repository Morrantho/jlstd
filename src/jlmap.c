typedef struct jlmap
{
	void** table;
	int size;
} jlmap;

jlmap* jlmap_ctor( int size )
{
	if( size < 1 ) return NULL;
	jlmap* map  = malloc( sizeof( jlmap ) );
	map->table  = calloc( size, sizeof( void* ) );
	map->size   = size;
	return map;
}

void jlmap_dtor( jlmap** map )
{
	jlmap* m = *map;
	free( m->table );
	m->table = NULL;
	free( m );
	*map = NULL;
}

int jlmap_hash( char* key )
{
	char* str = key;
	char c    = *str;
	int hash  = 0;

	for( ; c != '\0' ; str++, c = *str )
	{
		hash = (( hash << 5 )-hash) + c;
		hash &= hash;
	}
	return hash;	
}

void jlmap_set( jlmap* map, char* key, void* value )
{
	int hash = jlmap_hash( key );
	map->table[ hash % map->size ] = value;
}

void* jlmap_get( jlmap* map, char* key )
{
	int hash = jlmap_hash( key );
	return map->table[ hash % map->size ];
}