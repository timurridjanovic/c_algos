#include <stdio.h>
#include <stdlib.h>


typedef struct node NODE;
struct node {
    int value;
    struct node* next;
};

NODE* head = NULL;
NODE* curr = NULL;

NODE* append(int val) {
    NODE* ptr = (NODE*)malloc(sizeof(NODE));
    if (ptr == NULL) {
        printf("node creation failed\n");
        return NULL;
    } 
    ptr->value = val;
    ptr->next = NULL;
    
    if (head == NULL) {
        head = curr = ptr;
        return curr;
    }
    
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    curr->next = ptr;
    curr = ptr;
    return curr;
}

void print_list() {
    if (curr == NULL) {
        printf("list is empty\n");
        return;
    }
    
    int first;
    first = 1;
    curr = head;
    
    while (curr != NULL) {
        if (!first) 
            printf("%s", ", ");
        else
            printf("%s", "[");
            first = 0;
            
        printf("%d", curr->value);
        curr = curr->next;
    }
    
    printf("%s", "]\n");
}

int main()
{
    append(5);
    append(10);
    append(100);
    append(1000);
    append(3);

    //should print [5, 10, 100, 1000, 3]
    print_list();
    
    return 0;
}
