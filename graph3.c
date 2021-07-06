#include <stdio.h>
#include <conio.h>

#define infinity 9999
#define max 10

int vertexNo, edgeNo;

void dijkstra(int G[max][max], int vertexNo, int startnode);

void createAdjMatrix(int Adj[vertexNo + 1][vertexNo + 1], int arr[][3])
{
  for (int i = 0; i < vertexNo + 1; i++)
  {
    for (int j = 0; j < vertexNo + 1; j++)
    {
      Adj[i][j] = 0;
    }
  }

  // Traversing the edge array
  for (int i = 0; i < edgeNo; i++)
  {
    Adj[arr[i][0]][arr[i][1]] = arr[i][2]; // edge direction and weight update
    Adj[arr[i][1]][arr[i][0]] = arr[i][2];
  }
}

void printAdjMatrix(int Adj[][vertexNo + 1])
{
  for (int i = 1; i < vertexNo + 1; i++)
  {
    for (int j = 1; j < vertexNo + 1; j++)
    {
      printf("%d\t", Adj[i][j]);
    }
    printf("\n");
  }
}

/* 
1 2 10
2 3 50
3 4 20
4 5 60
5 1 100
3 5 10
1 4 30 

Adj:
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60 
100 0 10 60 0
*/

int main()
{
  int Adj[max][max], i, j, u;
  printf("How many vertices? ");
  fflush(stdin);
  scanf("%d", &vertexNo);
  printf("How many edges? ");
  fflush(stdin);
  scanf("%d", &edgeNo);
  printf("\nEnter the adjacency matrix:\n");
  for (i = 0; i < vertexNo; i++)
    for (j = 0; j < vertexNo; j++)
      scanf("%d", &Adj[i][j]);
  /* int edgeArr[max][3];
  printf("Enter edge details, from to weight: \n");
  for (int i = 0; i < edgeNo; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      scanf("%d", &edgeArr[i][j]);
    }
  }
  //createAdjMatrix(Adj, edgeArr);
  //printAdjMatrix(Adj);

  for (int i = 0; i < vertexNo + 1; i++)
  {
    for (int j = 0; j < vertexNo + 1; j++)
    {
      Adj[i][j] = 0;
    }
  }

  // Traversing the edge array
  for (int i = 0; i < edgeNo; i++)
  {
    Adj[edgeArr[i][0]][edgeArr[i][1]] = edgeArr[i][2]; // edge direction and weight update
    Adj[edgeArr[i][1]][edgeArr[i][0]] = edgeArr[i][2];
  }

  for (int i = 1; i < vertexNo + 1; i++)
  {
    for (int j = 1; j < vertexNo + 1; j++)
    {
      printf("%d\t", Adj[i][j]);
    }
    printf("\n");
  } */

  printf("\nEnter the starting node:");
  fflush(stdin);
  scanf("%d", &u);
  dijkstra(Adj, vertexNo, u);
  return 0;
}

void dijkstra(int G[max][max], int n, int startnode)
{

  int cost[max][max], distance[max], pred[max];
  int visited[max], count, mindistance, nextnode, i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (G[i][j] == 0)
        cost[i][j] = infinity;
      else
        cost[i][j] = G[i][j];
  for (i = 0; i < n; i++)
  {
    distance[i] = cost[startnode][i];
    pred[i] = startnode;
    visited[i] = 0;
  }
  distance[startnode] = 0;
  visited[startnode] = 1;
  count = 1;
  while (count < n - 1)
  {
    mindistance = infinity;
    //nextnode gives the node at minimum distance
    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i])
      {
        mindistance = distance[i];
        nextnode = i;
      }
    //check if a better path exists through nextnode
    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i])
        {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  //print the path and distance of each node
  for (i = 0; i < n; i++)
    if (i != startnode)
    {
      printf("\nDistance of node%d=%d", i, distance[i]);
      printf("\nPath=%d", i);
      j = i;
      do {
        j = pred[j];
        printf("<-%d", j);
      } while (j != startnode);
    }
}