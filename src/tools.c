#include "tools.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//function used in free_contexts
void free_context(context_t *);

//
//mandatory functions
//

//init variables
void init_contexts()
{
	current_context = malloc(sizeof(context_t));

	current_context->lower = NULL;
	current_context->upper = NULL;
	current_context->vars = NULL;
}

//free variables
void free_contexts()
{
	context_t *tmp, *context = current_context;
	while(context != NULL) {
		tmp = context->upper;
		free_context(context);
		context = tmp;
	}
	current_context = NULL;
}

//
//vital functions
//

/* declare a new variable
 * return if success (already declare or bad type)
 */
int declare (char *name, type_t type)
{
	variable_t **current = &current_context->vars, *prev = NULL;
	while(*current != NULL) {
		//a variable with same name already exists
		if(strcmp((*current)->name, name)==0)
			return 0;
		prev = *current;
		current = &((*current)->next);
	}
	*current = malloc(sizeof(variable_t));
	(*current)->next = NULL;

	//affect name
	(*current)->name = malloc(sizeof(char)*strlen(name));
	strcpy((*current)->name, name);
	//and type
	(*current)->type = type;
	(*current)->assigned = 0;
	(*current)->value = NULL;

	//not forget link new variable with others
	if(prev!=NULL)
		prev->next = *current;
	return 1;
}

/* affect a variable with string value
 * return 1 if success
 * 0 for unknow variable
 * -1 for unvalid variable type
 */
int affect_s (char *name, char *value)
{
	context_t *context = current_context;
	variable_t *node;
	while(context != NULL) {
		//search in this context
		node = context->vars;
		while(node != NULL && strcmp(node->name, name)!=0) {
			//get next variable
			node = node->next;
		}
		if(node == NULL)
			//var not found, search in upper context
			if(context->upper != NULL)
				context = context->upper;
			else
				return 0;
		else //variable found
			if(node->type == STRING) {
				//affect null value
				if(value == NULL) {
					if(node->value != NULL)
						free(node->value);
					node->value = NULL;
					node->assigned = 1;
				} else if(node->assigned && node->value != NULL) {
					int length = strlen(value);
					//just replace ?
					if(strlen(node->value) < length) {
						//realloc memory 
						free(node->value);
						node->value = malloc(sizeof(char) * length);
					}
					strcpy(node->value, value);
				} else {//assigned
					//new variable
					node->value = malloc(sizeof(char) * strlen(value));
					strcpy(node->value, value);
					node->assigned = 1;
				}
				return 1;
			} else
				return -1;
		//here if var not found && next context NOT NULL
	}
	//never here
	fprintf(stderr,
		"ERROR in affect_s: logical error in %s:%d for value %s and name %s\n",
		__FILE__, __LINE__, value, name);
	exit(-1);
}

/* affect a variable with integer value
 * return 1 if success
 * 0 for unknow variable
 * -1 for unvalid variable type
 */
int affect_i (char *name, int value)
{
	context_t *context = current_context;
	variable_t *node;
	while(context != NULL) {
		//search in this context
		node = context->vars;
		while(node != NULL && strcmp(node->name, name)!=0) {
			//get next variable
			node = node->next;
		}
		if(node == NULL)
			//var not found, search in upper context
			if(context->upper != NULL)
				context = context->upper;
			else
				return 0;
		else //variable found
			if(node->type == INTEGER) {
				if(node->assigned && node->value != NULL) {
					//simple affectation
					*((int*)node->value) = value;
				} else {//assigned
					//new variable
					node->value = malloc(sizeof(int));
					*((int*)node->value) = value;
					node->assigned = 1;
				}
				return 1;
			} else
				return -1;
		//here if var not found && next context NOT NULL
	}
	//never here
	fprintf(stderr,
		"ERROR in affect_i: logical error in %s:%d for value %d and name %s\n",
		__FILE__, __LINE__, value, name);
	exit(-1);
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

void free_variable(variable_t *var)
{
	if(var->name!=NULL)
		free(var->name);
	if(var->value!=NULL)
		free(var->value);
	free(var);
}

// utils function : free a context
void free_context(context_t *context)
{
	variable_t *var = context->vars, *tmp;
	while(var!=NULL) {
		tmp = var->next;
		free_variable(var);
		var = tmp;
	}
	//security but never used, always free upper context (so lower context==NULL)
	if(context->lower != NULL && context->upper != NULL) {
		context->lower->upper = context->upper;
		context->upper->lower = context->lower;
	}
	free(context);
}





