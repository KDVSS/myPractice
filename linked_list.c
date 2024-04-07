#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void createLinkedList(int data, struct Node** headRef){
    struct Node* ptrs;
    ptrs = (struct Node*) malloc(sizeof (struct Node));
    if(ptrs == NULL){
        printf("NULL Pointer\n");
        exit(1);
    }
    else{
        printf("Its Not a Null Pointer\n");
    }
    ptrs->data = data;
    printf("data: %d\n", ptrs->data);
    ptrs->next = *headRef;
    *headRef = ptrs;
}

int getMiddleNodeData(struct Node** headref){
    struct Node* fast_ptr = *headref;
    struct Node* slow_ptr = *headref;

    if(fast_ptr == NULL && slow_ptr == NULL){
        printf("MiddleNode() NULL Pointer\n");
        exit(1);
    }
    while(fast_ptr != NULL && fast_ptr->next != NULL){
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr->data;
}

struct Node* getMiddleNode(struct Node** headref){
    struct Node* fast_ptr = *headref;
    struct Node* slow_ptr = *headref;

    if(fast_ptr == NULL && slow_ptr == NULL){
        printf("MiddleNode() NULL Pointer\n");
        exit(1);
    }
    while(fast_ptr != NULL && fast_ptr->next != NULL){
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr;
}

int main(){
    struct Node* headRef = NULL;
    for(int i = 9; i>0; i--){
        createLinkedList(i , &headRef);
    }
    //int b = getMiddleNode(&headRef);
    printf("MiddleNodeData is: %d\n", getMiddleNodeData(&headRef));

    struct Node* resultRef = getMiddleNode(&headRef);
    printf("MiddleNode is: %d\n", resultRef->data);

    printf("\n\n");
}