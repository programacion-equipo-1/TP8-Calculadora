#include <stdio.h>
#include "general.h"
#include "manejo_de_arreglos.h"

static char operators [MAX];
static int (*actions[MAX])(float,float,float*);

