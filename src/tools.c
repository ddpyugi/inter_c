#include "tools.h"

//
//mandatory functions
//

//init variables
void init_global_context()
{

}
//free variables
void free_global_context()
{

}

//
//vital functions
//

/* declare a new variable
 * return if success (already declare or bad type)
 */
int declare (char *name, type_t type)
{

}

/* affect a variable with string value
 * return 1 if success
 * 0 for unknow variable
 * -1 for unvalid variable type
 */
int affect_s (char *name, char *value)
{

}

/* affect a variable with integer value
 * return 1 if success
 * 0 for unknow variable
 * -1 for unvalid variable type
 */
int affect_i (char *name, int i)
{

}

/* return integer value for variable in param
 * /!\ no error code
 * see "is_assigned" before for safe context
 */
int get_value_i (char *name)
{

}

/* return string value for variable in param
 * /!\ no error code
 * see "is_assigned" before for safe context
 */
char* get_value_s (char *name)
{

}

// return variable's type
type_t get_type(char *name)
{

}

/* return if a variable is defined
 * -1 : unknow variable
 *  0 : non assigned
 *  1 : ok
 */
int is_assigned(char *name)
{

}

/* declare new context (defined by { in C)
 * return if success
 */
int declare_context()
{

}

/* end of context ( } in C)
 * return if success
 */
int destroy_context()
{

}

//return number of context
int get_nb_Context()
{

}




