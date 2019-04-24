typedef struct jlbst
{
	jlbst* left;
	jlbst* right;
	int value;
} jlbst;
jlbst* jlbst_ctor( int value )
{
	jlbst* bst = malloc( sizeof( bst ) );
	bst->value = value;
	bst->left  = NULL;
	bst->right = NULL;
	return bst;
}
void jlbst_delete( jlbst* node )
{
	if( !ISNULL( node->left ) ) jlbst_delete( node->left );
	if( !ISNULL( node->right ) ) jlbst_delete( node->right );
	free(node);
}
void jlbst_dtor( jlbst** bst )
{
	jlbst* n = *bst;
	jlbst_delete( n );
	free( *bst );
	*bst = NULL;
}
void jlbst_add( jlbst* bst, int value )
{
	if( value < bst->value && !ISNULL( bst->left ) ) jlbst_add( bst->left, value );
	else if( value > bst->value && !ISNULL( bst->right ) ) jlbst_add( bst->right, value );
	else if( value < bst->value && ISNULL( bst->left ) ) bst->left = jlbst_ctor( value );
	else if( value > bst->value && ISNULL( bst->right ) ) bst->right = jlbst_ctor( value );
}
int jlbst_min( jlbst* bst )
{
	if( !ISNULL( bst->left ) ) return jlbst_min( bst->left );
	return bst->value;
}
int jlbst_max( jlbst* bst )
{
	if( !ISNULL( bst->right ) ) return jlbst_max( bst->right );
	return bst->value;
}
int jlbst_value( jlbst* node )
{
	return node->value;
}
bool jlbst_contains( jlbst* bst, int value )
{
	if( !ISNULL( bst ) && bst->value == value ) return true;
	else if( value < bst->value && !ISNULL( bst->left ) ) return jlbst_contains( bst->left, value );
	else if( value > bst->value && !ISNULL( bst->right ) ) return jlbst_contains( bst->right, value );
	else return false;
}
void jlbst_inorder( jlbst* bst, void (*cb)( jlbst* node ) )
{
	if( ISNULL( bst ) ) return;
	jlbst_inorder( bst->left, cb );
	cb( bst );
	jlbst_inorder( bst->right, cb );
}
void jlbst_preorder( jlbst* bst, void (*cb)( jlbst* node ) )
{
	if( ISNULL( bst ) ) return;
	cb( bst );
	jlbst_preorder( bst->left, cb );
	jlbst_preorder( bst->right, cb );
}
void jlbst_postorder( jlbst* bst, void (*cb)( jlbst* node ) )
{
	if( ISNULL( bst ) ) return;
	jlbst_postorder( bst->left, cb );
	jlbst_postorder( bst->right, cb );
	cb( bst );
}