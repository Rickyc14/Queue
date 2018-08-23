#include <main.h>

int main(void)
{
	circular_queue * queue;
	char buf[16];
	unsigned int f;
	const unsigned int max = 32;
	const unsigned int limit = 16;

    printf("                    // Circular queue implementation & visualization // \n\n");
    printf("|| queue's size won't go over 16 \n");
    printf("|| program stops after the 31st element is inserted \n");
    printf("|| ->> press enter to start <<-\n\n");
    getchar();
	queue = circular_queue_create();

	for(f=0;f < max;f++){
		sprintf(buf, "Item %d", f);
		if(f >= limit){ ///start removing at limit to show the queue doesn't keep growing
			char * data = circular_queue_remove(queue);
			printf("removed %s \n", data);
			free(data);
		}
		printf("inserting %s \n", buf);
		circular_queue_insert(queue, strdup(buf));
	}
	circular_queue_for_each(queue, (circular_queue_forfn)puts);
	printf("\n\n|| queue's size is %d \n",queue->size);
	printf("\n|| %d elements inserted (element zero included) \n",max);
	circular_queue_for_each(queue, free);
	circular_queue_delete(queue);
    printf("\n|| program's over: press enter to quit \n");
    getchar();
	return 0;
}

