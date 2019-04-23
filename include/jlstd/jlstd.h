#ifndef JLSTD_H
#define JLSTD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ISNULL( p ) ( p == NULL )

#define true 1
#define false 0
typedef unsigned char bool;

#include "jlnode.h"
#include "jlstack.h"
#include "jlqueue.h"
#include "jlmap.h"
#include "jlheap.h"
#include "jlbst.h"
#endif // JLSTD_H