#ifndef JLSTD_H
#define JLSTD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ISNULL( p ) ( p == NULL )
#define EQ( a, b ) ( a == b )

#define true 1
#define false 0

typedef unsigned char bool;
typedef unsigned char UC8;
typedef short int SI16;
typedef unsigned int UI32;

#include "jlnode.h"
#include "jlstack.h"
#include "jlqueue.h"
#include "jlmap.h"
#include "jlheap.h"
#include "jlbst.h"
#endif // JLSTD_H