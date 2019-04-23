#include <jlstd/jlstd.h>

void iter( jlbst* node )
{
	printf( "%d\n", jlbst_value( node ) );
}

int main( int argc, char** argv )
{
	int a = 20, b = 15, c = 25, d = 5, e = 10;
	jlbst* bst = jlbst_ctor( a );
	jlbst_add( bst, b );
	jlbst_add( bst, c );
	jlbst_add( bst, d );
	jlbst_add( bst, e );

	jlbst_inorder( bst, iter );

	jlbst_dtor( &bst );
	return 0;
}