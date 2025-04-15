//  Project: Mumbai Western Line Local Train Route Planner    
//  Author: Parmeet Kaur Randhawa
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define INF 99999
#define MAX 50
#define TRAVEL_TIME_PER_STATION 10 // Approx. takes 10 minutes between per station 
void printPath(vector<int>& parent, int j, string stations[])
{
    if (j == -1) return;
    printPath(parent, parent[j], stations);
    cout << stations[j];
    if (parent[j] != -1) cout << " → ";
}
int minDistance(int dist[], bool visited[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void dijkstra(int graph[MAX][MAX], string stations[], int V, int src, int dest)
{
    int dist[V];
    bool visited[V];
    vector<int> parent(V, -1);
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
  {
        int u = minDistance(dist, visited, V);
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    if (dist[dest] == INF)
    {
        cout << "\n No available route from " << stations[src] << " to " << stations[dest] << ".\n";
        return;
    }
    cout << "\n Shortest route from " << stations[src] << " to " << stations[dest] << ":\n";
    cout << " ";
    printPath(parent, dest, stations);
    cout << "\n Total stations: " << dist[dest];
    cout << "\n Estimated travel time: " << dist[dest] * TRAVEL_TIME_PER_STATION << " minutes\n";
}
int main()
{
    int V = 18;
    string stations[] = {  "Churchgate", "Marine Lines", "Charni Road", "Grant Road", "Mumbai Central", "Dadar", "Bandra", "Andheri", "Borivali", "Vasai Road", "Virar","Vaitarna","Saphale","Kelve Road","Palghar","Boisar","Vangaon","Dahanu Road" };
    int graph[MAX][MAX] = {0};
    for (int i = 0; i < V - 1; i++)
    {
        graph[i][i + 1] = 1;
        graph[i + 1][i] = 1;
    }
    cout << "\n Mumbai Western Line - Route Planner\n";
    cout << "---------------------------------------\n";
    for (int i = 0; i < V; i++) 
    {
        cout << "[" << i << "] " << stations[i] << "\n";
    }
    int src, dest;
    cout << "\nEnter source station index: ";
    cin >> src;
    cout << "Enter destination station index: ";
    cin >> dest;
    if (src < 0 || src >= V || dest < 0 || dest >= V)
    {
        cout << "Invalid station index. Please try again.\n";
        return 1;
    }
    dijkstra(graph, stations, V, src, dest);
    return 0;
}
