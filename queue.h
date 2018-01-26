// queue

struct qnode
{
    int data;
    struct qnode *next;
};

struct qnode *HEAD = NULL;
struct qnode *REAR = NULL;

int qSize = 0;

void Qpush(int d)
{
    struct qnode *newNode = (struct qnode *) malloc(sizeof(struct qnode));
    newNode->data = d;
    newNode->next = NULL;

    if(!HEAD)
        HEAD = newNode;
    else
        REAR->next = newNode;

    REAR = newNode;
    ++qSize;
}

int Qpop()
{
    if(!HEAD)
        return -1;

    int d = HEAD->data;

    struct qnode *tmp = HEAD->next;
    free(HEAD);

    HEAD = tmp;

    --qSize;
    return d;
}

int Qsize()
{
    return qSize;
}
