#include "main.h"

int main(int argc, const char * argv[]) {
    int i;
    Queue q;
    char end;

    printf("// Queue visualization //\n\n");
    printf("|| hold enter to watch queue representation \n");

    initQueue(&q);

    for (i = 0; i < QUEUE_CAPACITY; ++i)
    {
        debug_print(&q);
        puts("");
        enqueue(&q, (void*) i);
    }

    for (i = QUEUE_CAPACITY; i < 3 * QUEUE_CAPACITY; ++i)
    {
        debug_print(&q);
        puts("");
        dequeue(&q);
        enqueue(&q, (void*) i);
    }

    for (i = 0; i < QUEUE_CAPACITY; ++i)
    {
        debug_print(&q);
        puts("");
        dequeue(&q);
    }

    while (!isEmpty(&q))
    {
        debug_print(&q);
        dequeue(&q);
    }

    debug_print(&q);

    printf("\n\n|| representation's over: press 'q' & hit enter\n");

    do{
        scanf(" %c", &end);
    }while(end != 'q');


    return 0;
}
