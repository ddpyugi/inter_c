#ifndef UTILS_DEFINED
#define UTILS_DEFINED

typedef enum {
	UNKNOW = 0,
	INTEGER = 1,
	STRING = 2
} type_t;

typedef struct variable_t {
	char *name;
	type_t type;
	void *value;
	int assigned;
} variable_t;


typedef struct node_variable_t {
	variable_t *var;
	node_variable_t *next;
} node_variable_t;


typedef struct context_t {
	node_variable_t *vars;
	struct context_t *prev;
	struct context_t *next;
} context_t;

/* last context
 * NULL if not initialize
 */
context_t * current_context;

//
//mandatory functions
//

//init variables
void init_contexts();
//free variables
void free_contexts();

//
//vital functions
//

/* declare a new variable
 * return if success (already declare or bad type)
 */
int declare (char *name, type_t type);

/* affect a variable with string value
 * return 1 if success
 * 0 for unknow variable
 * -1 for unvalid variable type
 */
int affect_s (char *name, char *value);

/* affect a variable with integer value
 * return 1 if success
 * 0 for unknow variable
 * -1 for unvalid variable type
 */
int affect_i (char *name, int i);

/* return integer value for variable in param
 * /!\ no error code
 * see "is_assigned" before for safe context
 */
int get_value_i (char *name);

/* return string value for variable in param
 * /!\ no error code
 * see "is_assigned" before for safe context
 */
char* get_value_s (char *name);

// return variable's type
type_t get_type(char *name);

/* return if a variable is defined
 * -1 : unknow variable
 *  0 : non assigned
 *  1 : ok
 */
int is_assigned(char *name);

/* declare new context (defined by { in C)
 * return if success
 */
int declare_context();

/* end of context ( } in C)
 * return if success
 */
int destroy_context();

//return number of context
int get_nb_Context();

#endif //UTILS_DEFINED




