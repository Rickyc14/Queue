#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct circular_queue {
	unsigned int head;
	unsigned int tail;
	unsigned int is_full;
	void ** entries;
	unsigned int size;
}circular_queue;

typedef void (*circular_queue_forfn)(void*);

circular_queue * circular_queue_create(void);
void circular_queue_delete(circular_queue * queue);
unsigned int circular_queue_insert (circular_queue * queue, void * data);
void * crique_remove(circular_queue * queue);
void * circular_queue_peek(const circular_queue * queue);
unsigned int circular_queue_get_count(const circular_queue * queue);
void circular_queue_for_each(const circular_queue * queue, circular_queue_forfn fun);


/// a __static variable__ inside a function keeps its value between invocations
/// a __static global variable__ or a __function__ is "seen" only in the file it's declared in
///
/// widely used as an "access control" feature -- if you have a .c file implementing some functionality,
/// it usually exposes only a few "public" functions to users. The rest of its functions should be made static,
/// so that the user won't be able to access them ("good practice")
///
///
/// if a variable is declared as constant using _const_ keyword,then changing it's value is illegal
/// we cannot change value of this variable by assignment operator
/// int main(void){
/// const int a = 10;
/// a = 20; <-X illegal
/// ...}

/// A _const_ is a promise that you will not try to modify the value once set.
/// A _static_ variable means that the object's lifetime is the entire execution of the program and it's value is initialized
/// only once before the program startup. All statics are initialized if you do not explicitly set a value to them. The manner
/// and timing of static initialization is unspecified.
