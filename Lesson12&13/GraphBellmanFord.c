//
// Joaquim Madeira, AlgC, June 2020
// João Manuel Rodrigues, AlgC, June 2020
//
// GraphBellmanFord - Bellman-Ford Alg. for the Shortest Paths Tree
//

#include "GraphBellmanFord.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "IntegersStack.h"

struct _GraphBellmanFord
{
  int *distance;
  int *predecessor;
  Graph *graph;
  unsigned int startVertex;
};

GraphBellmanFord *GraphBellmanFordExecute(Graph *g, unsigned int startVertex)
{
  assert(g != NULL);
  assert(0 <= startVertex && startVertex < GraphGetNumVertices(g));
  GraphBellmanFord *result =
      (GraphBellmanFord *)malloc(sizeof(struct _GraphBellmanFord));
  assert(result != NULL);

  unsigned int numVertices = GraphGetNumVertices(g);
  result->graph = g;
  result->startVertex = startVertex;
  result->distance = (int *)malloc(sizeof(int) * (numVertices));
  result->predecessor = (int *)malloc(sizeof(int) * (numVertices));
  for (int i = 0; i < numVertices; i++)
  {
    result->distance[i] = INT_MAX / 2;
  }
  result->distance[result->startVertex] = 0;
  for (int n = 0; n < numVertices; n++)
  {
    for (int i = 0; i < numVertices; i++)
    {
      unsigned int *vertex = GraphGetAdjacentsTo(result->graph, i);
      int *weights = GraphGetDistancesToAdjacents(result->graph, i);
      for (int j = 1; j < vertex[0] + 1; j++)
      {
        if (result->distance[i] + weights[j] < result->distance[vertex[j]])
        {
          result->distance[vertex[j]] = result->distance[i] + weights[j];
          result->predecessor[vertex[j]] = i;
        }
      }
    }
  }

  return result;
}

void GraphBellmanFordDestroy(GraphBellmanFord **p)
{
  assert(*p != NULL);

  GraphBellmanFord *aux = *p;

  free(aux->distance);
  free(aux->predecessor);

  free(*p);
  *p = NULL;
}

// Getting the result

unsigned int GraphBellmanFordHasPathTo(const GraphBellmanFord *p,
                                       unsigned int v)
{
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return (p->distance[v] != INT_MAX);
}

int GraphBellmanFordDistanceTo(const GraphBellmanFord *p, unsigned int v)
{
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  return p->distance[v];
}

Stack *GraphBellmanFordPathTo(const GraphBellmanFord *p, unsigned int v)
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

void GraphBellmanFordShowPath(const GraphBellmanFord *p, unsigned int v)
{
  assert(0 <= v && v < GraphGetNumVertices(p->graph));

  Stack *s = GraphBellmanFordPathTo(p, v);

  while (StackIsEmpty(s) == 0)
  {
    printf("%d ", StackPop(s));
  }

  printf(" --- Distance = %d", p->distance[v]);

  StackDestroy(&s);
}

void GraphBellmanFordDisplay(const GraphBellmanFord *p)
{
  int vertexNum = GraphGetNumVertices(p->graph);
  for (int i = 0; i < vertexNum; i++)
  {
    GraphBellmanFordShowPath(p, i);
  }
}
