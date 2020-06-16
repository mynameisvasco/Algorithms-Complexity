//
// Joaquim Madeira, AlgC, June 2020
// João Manuel Rodrigues, AlgC, June 2020
//
// GraphShortestPathsWithQueue - QUEUE algorithm for the Shortest Paths Tree
//

#include "GraphShortestPathsWithQueue.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersStack.h"
#include "IntegersQueue.h"

struct _GraphShortestPathsWithQueue
{
  int *distance;
  int *predecessor;
  Graph *graph;
  unsigned int startVertex;
};

GraphShortestPathsWithQueue *GraphShortestPathsWithQueueExecute(
    Graph *g, unsigned int startVertex)
{
  assert(g != NULL);
  assert(0 <= startVertex && startVertex < GraphGetNumVertices(g));

  GraphShortestPathsWithQueue *ShortestPathsWithQueue =
      (GraphShortestPathsWithQueue *)malloc(
          sizeof(struct _GraphShortestPathsWithQueue));
  assert(ShortestPathsWithQueue != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);

  //
  //
  // CRIAR e INICIALIZAR os campos de ShortestPathsWithQueue
  // ShortestPathsWithQueue->distance
  // ShortestPathsWithQueue->predecessor
  //
  int marked[numVertices];

  ShortestPathsWithQueue->distance = (int *)malloc(numVertices * sizeof(int));
  if (ShortestPathsWithQueue->distance == NULL)
    return NULL;

  ShortestPathsWithQueue->predecessor = (int *)malloc(numVertices * sizeof(int));
  if (ShortestPathsWithQueue->predecessor == NULL)
    return NULL;

  for (int i = 0; i < numVertices; i++)
  {
    marked[i] = 0;
    ShortestPathsWithQueue->predecessor[i] = -1;
    ShortestPathsWithQueue->distance[i] = INT_MAX;
  }

  ShortestPathsWithQueue->distance[startVertex] = 0;

  ShortestPathsWithQueue->graph = g;
  ShortestPathsWithQueue->startVertex = startVertex;

  // EXECUTAR O ALGORITMO

  Queue *queue = QueueCreate(numVertices);

  QueueEnqueue(queue, startVertex);

  while (!QueueIsEmpty(queue))
  {
    startVertex = QueueDequeue(queue);
    int *adj = GraphGetAdjacentsTo(g, startVertex);
    int *wheight = GraphGetDistancesToAdjacents(g, startVertex);
    for (int i = 1; i < adj[0] + 1; i++)
    {
      int adjVertex = adj[i];
      if (ShortestPathsWithQueue->distance[startVertex] + wheight[i] < ShortestPathsWithQueue->distance[adjVertex])
      {
        ShortestPathsWithQueue->distance[adjVertex] = ShortestPathsWithQueue->distance[startVertex] + wheight[i];
        ShortestPathsWithQueue->predecessor[adjVertex] = startVertex;
        if (!marked[adjVertex])
        {
          marked[adjVertex] = 1;
          QueueEnqueue(queue, adjVertex);
        }
      }
    }
  }

  return ShortestPathsWithQueue;
}

void GraphShortestPathsWithQueueDestroy(GraphShortestPathsWithQueue **p)
{
  assert(*p != NULL);

  GraphShortestPathsWithQueue *aux = *p;

  free(aux->distance);
  free(aux->predecessor);

  free(*p);
  *p = NULL;
}

// Getting the result

unsigned int GraphShortestPathsWithQueueHasPathTo(
    const GraphShortestPathsWithQueue *p, unsigned int v)
{
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return (p->distance[v] != INT_MAX);
}

int GraphShortestPathsWithQueueDistanceTo(const GraphShortestPathsWithQueue *p,
                                          unsigned int v)
{
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return p->distance[v];
}

Stack *GraphShortestPathsWithQueuePathTo(const GraphShortestPathsWithQueue *p,
                                         unsigned int v)
{
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack *s = StackCreate(GraphGetNumVertices(p->graph));

  if (p->distance[v] == INT_MAX)
  {
    return s;
  }

  // Store the path
  for (unsigned int current = v; current != p->startVertex;
       current = p->predecessor[current])
  {
    StackPush(s, current);
  }

  StackPush(s, p->startVertex);

  return s;
}

// DISPLAYING on the console

void GraphShortestPathsWithQueueShowPath(const GraphShortestPathsWithQueue *p,
                                         unsigned int v)
{
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack *s = GraphShortestPathsWithQueuePathTo(p, v);

  while (StackIsEmpty(s) == 0)
  {
    printf("%d ", StackPop(s));
  }

  printf(" --- Distance = %d", p->distance[v]);

  StackDestroy(&s);
}

void GraphShortestPathsWithQueueDisplay(const GraphShortestPathsWithQueue *p)
{
  int vertexNum = GraphGetNumVertices(p->graph);
  for (int i = 0; i < vertexNum; i++)
  {
    GraphShortestPathsWithQueueShowPath(p, i);
  }
}
