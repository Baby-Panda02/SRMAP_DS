#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// create Node structure
struct Node
{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
};

// Queue for inserting element in each level
struct Queue
{
    struct Node *arr[100];
    int front, rear;
};

// initial queue
void initQueue(struct Queue *q)
{
    q->front = q->rear = -1;
}

// queue empty
int isEmpty(struct Queue *q)
{
    return q->front == -1;
}

// insert elements
void enqueue(struct Queue *q, struct Node *node)
{
    if (q->rear == 99)
        return;
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = node;
}

// delete elements frm queue and add to tree
struct Node *dequeue(struct Queue *q)
{
    if (isEmpty(q))
        return NULL;
    struct Node *temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// Create node
struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->leftChild = n->rightChild = NULL;
    return n;
}

// 🔹 Display proper tree with edges
void printTree(struct Node *root, int depth)
{
    if (!root)
        return;

    struct Node *level[100];
    int front = 0, rear = 0;

    level[rear++] = root;

    for (int d = 0; d < depth; d++)
    {
        int count = rear - front;

        int space = pow(2, depth - d);

        // print nodes
        for (int i = 0; i < count; i++)
        {
            for (int s = 0; s < space; s++)
                printf(" ");

            struct Node *temp = level[front++];
            if (temp != NULL)
            {
                printf("%d", temp->data);
                level[rear++] = temp->leftChild;
                level[rear++] = temp->rightChild;
            }
            else
            {
                printf(" ");
                level[rear++] = NULL;
                level[rear++] = NULL;
            }

            for (int s = 0; s < space; s++)
                printf(" ");
        }
        printf("\n");

        // print edges
        for (int i = 0; i < count; i++)
        {
            for (int s = 0; s < space; s++)
                printf(" ");

            struct Node *temp = level[front - count + i];

            if (temp != NULL)
            {
                if (temp->leftChild)
                    printf("/");
                else
                    printf(" ");

                printf(" ");

                if (temp->rightChild)
                    printf("\\");
                else
                    printf(" ");
            }

            for (int s = 0; s < space; s++)
                printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    struct Queue q;
    initQueue(&q);

    int depth, rootData;

    printf("Enter depth of tree: ");
    scanf("%d", &depth);

    printf("Enter root data: ");
    scanf("%d", &rootData);

    struct Node *root = createNode(rootData);
    enqueue(&q, root);

    int currentLevel = 1;

    // Build tree (max 2 children)
    while (!isEmpty(&q) && currentLevel < depth)
    {                                    // condition for stop untill queue empty or reach the depth
        int size = q.rear - q.front + 1; // count the elements in the level

        printf("\n--- Level %d ---\n", currentLevel);

        for (int i = 0; i < size; i++)
        {
            struct Node *parent = dequeue(&q); // take one as parent and add its child nodes

            int leftData, rightData;

            printf("Enter left child of %d (-1 for no node): ", parent->data);
            scanf("%d", &leftData);

            if (leftData != -1)
            {
                parent->leftChild = createNode(leftData);
                enqueue(&q, parent->leftChild);
            }

            printf("Enter right child of %d (-1 for no node): ", parent->data);
            scanf("%d", &rightData);

            if (rightData != -1)
            {
                parent->rightChild = createNode(rightData);
                enqueue(&q, parent->rightChild);
            }
        }
        currentLevel++;
    }

    printf("\n\nTree Structure:\n\n");
    printTree(root, depth);

    return 0;
}