// Accept a directed weighted graph from user and represent it with Adjacency Matrix 
// and find a shortest distance from source to destination using Dijkstra’s algorithm.

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define infinity 9999
#define max 10

int vertexNo, edgeNo, Adj[max][max];

/* void createAdjMatrix(int *Adj, int arr[][3])
{
    for (int i = 0; i < vertexNo + 1; i++) {
        for (int j = 0; j < vertexNo + 1; j++) {
            *((Adj + i*vertexNo) + j) = 0;
        }
    }
  
    // Traversing the edge array
    for (int i = 0; i < edgeNo; i++) {
        int x = arr[i][0];
        int y = arr[i][1];

        *((Adj + x*vertexNo) + y) = arr[i][2];      // edge weight update
        *((Adj + y*vertexNo) + x) = arr[i][2];      
    }
} */

void createAdjMatrix(int Adj[][vertexNo], int arr[][3])
{
    for (int i = 0; i < vertexNo + 1; i++) {
        for (int j = 0; j < vertexNo + 1; j++) {
            Adj[i][j] = 0;
        }
    }
  
    // Traversing the edge array
    for (int i = 0; i < edgeNo; i++) {
        int x = arr[i][0];
        int y = arr[i][1];

        Adj[x][y] = arr[i][2];      // edge weight update
        Adj[y][x] = arr[i][2];      
    }
}

/* void printAdjMatrix(int *Adj)
{
    for (int i = 1; i < vertexNo + 1; i++) {
        for (int j = 1; j < vertexNo + 1; j++) { 
            printf("%d\t", *((Adj + i*vertexNo) + j));
        }
        printf("\n");
    }
} */

void printAdjMatrix(int Adj[][vertexNo])
{
    for (int i = 1; i < vertexNo + 1; i++) {
        for (int j = 1; j < vertexNo + 1; j++) { 
            printf("%d\t", Adj[i][j]);
        }
        printf("\n");
    }
}

int minDistance(int dist[], int visited[]) {
    int min = 9999, min_index;
    for (int v = 0; v < vertexNo; v++)
    if (visited[v] == 0 && dist[v] <= min){
        min = dist[v];
        min_index = v;
    }
        
   return min_index;
}

int printSolution(int dist[], int end) {
   int answer;
   printf("Vertex \tDistance from Source\n");
   for (int i = 0; i < vertexNo; i++){
        printf("%d \t %d\n", i, dist[i]);
        if(i == end)
            answer = dist[i];
    }
    printf("\nAnswer = %d", answer);
      
}

void dijkstra(int Adj[vertexNo][vertexNo], int src, int dest) {
    int dist[vertexNo];
    int visited[vertexNo];
    for (int i = 0; i < vertexNo; i++){
        dist[i] = 9999;
        visited[i] = 0;
    }
    dist[src] = 0;
    
    for (int count = 0; count < vertexNo - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        for (int v = 0; v < vertexNo; v++){
            if (visited[v] != 1 && Adj[u][v] && dist[u] != 9999 && dist[u] + Adj[u][v] < dist[v]) 
                dist[v] = dist[u] + Adj[u][v];
        }
            
    }
    printSolution(dist, dest);
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

int main(){

    printf("How many vertices? ");
    scanf("%d", &vertexNo);
    printf("How many edges? ");
    scanf("%d", &edgeNo);

    
    int edgeArr[edgeNo][3];
    //{{1,4,2}, {4,2,15}, {2,5,8}, {3,5,6}, {3,4,5}, {3,1,10}}
    // 1,2,2   1,3,4   2,3,1   2,4,7   3,5,3   5,4,2   4,6,1   5,6,5
    // 1,2,6   1,8,8   2,3,8   2,8,13  3,4,7   3,6,6   3,9,2   4,5,9   4,6,14   5,6,10   6,7,2   7,8,1   7,9,6   8,9,7

    printf("Enter details for edge (from vertex, to vertex, weight): ");
    for(int i = 0; i < edgeNo; ++i){
        for(int j = 0; j < 3; ++j)
            scanf("%d", &edgeArr[i][j]);
    }

    createAdjMatrix(Adj, edgeArr);
    printAdjMatrix(Adj);

    int startVertex, endVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);
    printf("Enter the end vertex: ");
    scanf("%d", &endVertex);

    dijkstra(Adj, startVertex, endVertex);

    return 0;
}

