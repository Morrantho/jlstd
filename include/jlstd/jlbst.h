#ifndef JLBST_H
#define JLBST_H
typedef struct jlbst jlbst;
jlbst* jlbst_ctor();
void jlbst_dtor( jlbst** bst );
void jlbst_add( jlbst* bst, int value );
int jlbst_min( jlbst* bst );
int jlbst_max( jlbst* bst );
int jlbst_value( jlbst* node );
bool jlbst_contains( jlbst* bst, int value );
void jlbst_inorder( jlbst* bst, void (*cb)( jlbst* node ) );
void jlbst_preorder( jlbst* bst, void (*cb)( jlbst* node ) );
void jlbst_postorder( jlbst* bst, void (*cb)( jlbst* node ) );
#endif // JLBST_H