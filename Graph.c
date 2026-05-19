/*
 * ============================================================
 *  GRAPH in C  �  Adjacency List representation
 *  Features:
 *    - Add vertex / Add edge (directed or undirected)
 *    - Search: BFS  (breadth-first  � explores level by level)
 *    - Search: DFS  (depth-first    � dives deep before backtracking)
 *    - Insert edge at a specific position (after a searched vertex)
 *    - Delete edge
 *    - Delete vertex (removes vertex + all incident edges)
 *    - Print graph
 *    - Free graph
 * PLEASE NOTE THAT I HAVE MADE THIS WITH THE USE OF CLAUDE IT IS ONLY FOR EXPERIMENTATION PURPUSES *

 * ============================================================
 */

 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct AdjNode {
    int dest;
    int weight;
    struct AdjNode *next;
} AdjNode;

typedef struct Vertex {
    int   id;
    char  label[64];
    AdjNode *head;
} Vertex;

typedef struct Graph {
    int      capacity;
    int      numVertices;
    bool     directed;
    Vertex **vertices;
} Graph;

typedef struct Queue {
    int  *data;
    int   front, rear, size, capacity;
} Queue;

Queue *createQueue(int cap) {
    Queue *q = malloc(sizeof(Queue));
    q->data     = malloc(cap * sizeof(int));
    q->front    = q->rear = q->size = 0;
    q->capacity = cap;
    return q;
}

void enqueue(Queue *q, int val) {
    if (q->size == q->capacity) return;
    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

int dequeue(Queue *q) {
    if (q->size == 0) return -1;
    int val  = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

bool queueEmpty(Queue *q) { return q->size == 0; }

void freeQueue(Queue *q) { free(q->data); free(q); }

Graph *createGraph(bool directed) {
    Graph *g        = malloc(sizeof(Graph));
    g->capacity     = 16;
    g->numVertices  = 0;
    g->directed     = directed;
    g->vertices     = calloc(g->capacity, sizeof(Vertex *));
    return g;
}

int findVertexIndex(Graph *g, int id) {
    for (int i = 0; i < g->numVertices; i++)
        if (g->vertices[i]->id == id) return i;
    return -1;
}

int findVertexByLabel(Graph *g, const char *label) {
    for (int i = 0; i < g->numVertices; i++)
        if (strcmp(g->vertices[i]->label, label) == 0) return i;
    return -1;
}

AdjNode *createAdjNode(int dest, int weight) {
    AdjNode *n = malloc(sizeof(AdjNode));
    n->dest   = dest;
    n->weight = weight;
    n->next   = NULL;
    return n;
}

int addVertex(Graph *g, int id, const char *label) {
    if (findVertexIndex(g, id) != -1) {
        printf("[WARN] Vertex %d already exists.\n", id);
        return -1;
    }
    if (g->numVertices == g->capacity) {
        g->capacity *= 2;
        g->vertices  = realloc(g->vertices, g->capacity * sizeof(Vertex *));
    }
    Vertex *v = malloc(sizeof(Vertex));
    v->id   = id;
    strncpy(v->label, label, 63);
    v->label[63] = '\0';
    v->head = NULL;
    g->vertices[g->numVertices++] = v;
    printf("[ADD VERTEX] id=%d  label=\"%s\"\n", id, label);
    return 0;
}

int addEdge(Graph *g, int srcId, int destId, int weight) {
    int si = findVertexIndex(g, srcId);
    int di = findVertexIndex(g, destId);
    if (si == -1 || di == -1) {
        printf("[ERROR] addEdge: vertex %d or %d not found.\n", srcId, destId);
        return -1;
    }
    AdjNode *node = createAdjNode(destId, weight);
    AdjNode **cur = &g->vertices[si]->head;
    while (*cur) cur = &(*cur)->next;
    *cur = node;

    if (!g->directed) {
        AdjNode *rev = createAdjNode(srcId, weight);
        AdjNode **rc = &g->vertices[di]->head;
        while (*rc) rc = &(*rc)->next;
        *rc = rev;
    }
    printf("[ADD EDGE]  %d --%s--> %d  (weight=%d)\n",
           srcId, g->directed ? "" : "--", destId, weight);
    return 0;
}

int bfsSearch(Graph *g, int startId, int targetId) {
    int si = findVertexIndex(g, startId);
    if (si == -1) { printf("[BFS] Start vertex %d not found.\n", startId); return -1; }

    bool *visited = calloc(g->numVertices, sizeof(bool));
    Queue *q      = createQueue(g->numVertices);
    int result    = -1;

    visited[si] = true;
    enqueue(q, si);
    printf("[BFS] Traversal from vertex %d: ", startId);

    while (!queueEmpty(q)) {
        int ci = dequeue(q);
        Vertex *v = g->vertices[ci];
        printf("%d(\"%s\") ", v->id, v->label);

        if (v->id == targetId) { result = ci; }

        for (AdjNode *a = v->head; a; a = a->next) {
            int ni = findVertexIndex(g, a->dest);
            if (ni != -1 && !visited[ni]) {
                visited[ni] = true;
                enqueue(q, ni);
            }
        }
    }
    printf("\n");
    if (result == -1) printf("[BFS] Vertex %d NOT found.\n", targetId);
    else              printf("[BFS] Vertex %d FOUND (index %d).\n", targetId, result);

    free(visited);
    freeQueue(q);
    return result;
}

void dfsHelper(Graph *g, int ci, int targetId, bool *visited, int *result) {
    visited[ci] = true;
    Vertex *v   = g->vertices[ci];
    printf("%d(\"%s\") ", v->id, v->label);

    if (v->id == targetId) *result = ci;

    for (AdjNode *a = v->head; a; a = a->next) {
        int ni = findVertexIndex(g, a->dest);
        if (ni != -1 && !visited[ni])
            dfsHelper(g, ni, targetId, visited, result);
    }
}

int dfsSearch(Graph *g, int startId, int targetId) {
    int si = findVertexIndex(g, startId);
    if (si == -1) { printf("[DFS] Start vertex %d not found.\n", startId); return -1; }

    bool *visited = calloc(g->numVertices, sizeof(bool));
    int result    = -1;

    printf("[DFS] Traversal from vertex %d: ", startId);
    dfsHelper(g, si, targetId, visited, &result);
    printf("\n");

    if (result == -1) printf("[DFS] Vertex %d NOT found.\n", targetId);
    else              printf("[DFS] Vertex %d FOUND (index %d).\n", targetId, result);

    free(visited);
    return result;
}

int insertEdgeAt(Graph *g, int startId, int srcId, int destId,
                 int weight, int pos, bool useBFS) {
    printf("\n[INSERT-AT] Searching for src vertex %d using %s...\n",
           srcId, useBFS ? "BFS" : "DFS");

    int si = useBFS ? bfsSearch(g, startId, srcId)
                    : dfsSearch(g, startId, srcId);
    if (si == -1) {
        printf("[INSERT-AT] Source vertex %d not found - aborting.\n", srcId);
        return -1;
    }
    int di = findVertexIndex(g, destId);
    if (di == -1) {
        printf("[INSERT-AT] Destination vertex %d not found - aborting.\n", destId);
        return -1;
    }

    AdjNode *newNode = createAdjNode(destId, weight);

    AdjNode **cur = &g->vertices[si]->head;
    int idx = 0;
    while (*cur && idx < pos) { cur = &(*cur)->next; idx++; }
    newNode->next = *cur;
    *cur = newNode;

    printf("[INSERT-AT] Edge %d->%d (w=%d) inserted at position %d in adj list.\n",
           srcId, destId, weight, pos);

    if (!g->directed) {
        AdjNode *rev = createAdjNode(srcId, weight);
        AdjNode **rc = &g->vertices[di]->head;
        while (*rc) rc = &(*rc)->next;
        *rc = rev;
    }
    return 0;
}

int deleteEdge(Graph *g, int srcId, int destId) {
    int si = findVertexIndex(g, srcId);
    int di = findVertexIndex(g, destId);
    if (si == -1 || di == -1) {
        printf("[DELETE EDGE] Vertex %d or %d not found.\n", srcId, destId);
        return -1;
    }

    AdjNode **cur = &g->vertices[si]->head;
    bool removed  = false;
    while (*cur) {
        if ((*cur)->dest == destId) {
            AdjNode *tmp = *cur;
            *cur = (*cur)->next;
            free(tmp);
            removed = true;
            break;
        }
        cur = &(*cur)->next;
    }

    if (!removed) {
        printf("[DELETE EDGE] Edge %d->%d not found.\n", srcId, destId);
        return -1;
    }

    if (!g->directed) {
        AdjNode **rc = &g->vertices[di]->head;
        while (*rc) {
            if ((*rc)->dest == srcId) {
                AdjNode *tmp = *rc;
                *rc = (*rc)->next;
                free(tmp);
                break;
            }
            rc = &(*rc)->next;
        }
    }

    printf("[DELETE EDGE] Edge %d <-> %d removed.\n", srcId, destId);
    return 0;
}

int deleteVertex(Graph *g, int id) {
    int vi = findVertexIndex(g, id);
    if (vi == -1) {
        printf("[DELETE VERTEX] Vertex %d not found.\n", id);
        return -1;
    }

    AdjNode *cur = g->vertices[vi]->head;
    while (cur) { AdjNode *tmp = cur; cur = cur->next; free(tmp); }

    for (int i = 0; i < g->numVertices; i++) {
        if (i == vi) continue;
        AdjNode **pc = &g->vertices[i]->head;
        while (*pc) {
            if ((*pc)->dest == id) {
                AdjNode *tmp = *pc;
                *pc = (*pc)->next;
                free(tmp);
            } else {
                pc = &(*pc)->next;
            }
        }
    }

    free(g->vertices[vi]);
    for (int i = vi; i < g->numVertices - 1; i++)
        g->vertices[i] = g->vertices[i + 1];
    g->vertices[--g->numVertices] = NULL;

    printf("[DELETE VERTEX] Vertex %d and all its edges removed.\n", id);
    return 0;
}

void printGraph(Graph *g) {
    printf("\n======================================\n");
    printf("  GRAPH  (%s, %d vertices)\n",
           g->directed ? "directed" : "undirected", g->numVertices);
    printf("======================================\n");
    for (int i = 0; i < g->numVertices; i++) {
        Vertex *v = g->vertices[i];
        printf("  [%d] \"%s\"  ->  ", v->id, v->label);
        if (!v->head) { printf("(no edges)\n"); continue; }
        for (AdjNode *a = v->head; a; a = a->next)
            printf("%d(w=%d)%s", a->dest, a->weight, a->next ? " -> " : "");
        printf("\n");
    }
    printf("======================================\n\n");
}

void freeGraph(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        AdjNode *cur = g->vertices[i]->head;
        while (cur) { AdjNode *tmp = cur; cur = cur->next; free(tmp); }
        free(g->vertices[i]);
    }
    free(g->vertices);
    free(g);
}

int main(void) {
    printf("======================================\n");
    printf("     GRAPH DEMO - Adjacency List      \n");
    printf("======================================\n\n");

    Graph *g = createGraph(false);

    addVertex(g, 0, "A");
    addVertex(g, 1, "B");
    addVertex(g, 2, "C");
    addVertex(g, 3, "D");
    addVertex(g, 4, "E");
    addVertex(g, 5, "F");

    addEdge(g, 0, 1, 4);
    addEdge(g, 0, 2, 3);
    addEdge(g, 1, 2, 1);
    addEdge(g, 1, 3, 2);
    addEdge(g, 2, 4, 5);
    addEdge(g, 3, 4, 2);
    addEdge(g, 4, 5, 6);

    printGraph(g);

    printf("--- BFS Search (start=0, target=5) ---\n");
    bfsSearch(g, 0, 5);

    printf("\n--- DFS Search (start=0, target=5) ---\n");
    dfsSearch(g, 0, 5);

    printf("\n--- Insert Edge 1->5 (w=9) at position 0 via BFS ---\n");
    insertEdgeAt(g, 0, 1, 5, 9, 0, true);
    printGraph(g);

    printf("--- Insert Edge 3->5 (w=7) at position 1 via DFS ---\n");
    insertEdgeAt(g, 0, 3, 5, 7, 1, false);
    printGraph(g);

    printf("--- Delete Edge 1 <-> 5 ---\n");
    deleteEdge(g, 1, 5);
    printGraph(g);

    printf("--- Delete Vertex 4 (E) ---\n");
    deleteVertex(g, 4);
    printGraph(g);

    printf("--- DFS after deletion (start=0, target=5) ---\n");
    dfsSearch(g, 0, 5);
    printf("\n--- BFS after deletion (start=0, target=5) ---\n");
    bfsSearch(g, 0, 5);

    freeGraph(g);
    printf("\n[INFO] Graph freed. Done.\n");
    return 0;
}
