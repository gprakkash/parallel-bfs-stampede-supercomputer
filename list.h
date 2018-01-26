// list
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;

typedef struct list
{
    int size;
    struct node *head;
    struct node *rear;
}list;

int exists_in_list(list *lst, int d){
    struct node *cur = lst->head;
    while(cur != NULL){
        if(cur->data == d)
            return 1;
        cur = cur->next;
    }
    return 0;
}

void print_list(list *lst){
    struct node *cur = lst->head;
    while(cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int *array_from_list(list *lst){
    if(lst->size == 0){
        free(lst);
        return NULL;
    }
    int i = 0;
    int *arr = (int *)malloc(sizeof(int) * lst->size);
    struct node *cur = lst->head;
    struct node *garbage;
    while(cur != NULL){
        arr[i] = cur->data;
        garbage = cur;
        cur = cur->next;
        free(garbage);
    }
    free(lst);
    return arr;
}

void destroy_list(list *lst){
    struct node *garbage = lst->head;
    while(lst->head != NULL){
        lst->head = lst->head->next;
        free(garbage);
        garbage = lst->head;
    }
    free(lst);
}

list *create_list(){
    struct list *lst = (list *)malloc(sizeof(list));
    lst->head = NULL;
    lst->rear = NULL;
    lst->size = 0;
    
    return lst;
}

void push(list *lst, int d)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = d;
    new_node->next = NULL;
    new_node->prev = lst->rear;

    if(!lst->rear){
        lst->head = new_node;
        lst->rear = new_node;
    }
    else
        lst->rear->next = new_node;

    lst->rear = new_node;
    lst->size += 1;
}

int pop(list *lst)
{
    if(!lst->rear)
        return -1;

    int d = lst->rear->data;

    struct node *tmp = lst->rear->prev;
    free(lst->rear);

    lst->rear = tmp;

    lst->size--;
    
    if(lst->size == 0)
        lst->head = NULL;

    return d;
}

int len(list *lst)
{
    if(lst)
        return lst->size;
    else
        return 0;
}
