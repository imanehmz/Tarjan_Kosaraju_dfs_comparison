#include <bits/stdc++.h>
#include <ctime>
#include <chrono>


#define MAX_N 20001
#define ll long long int
using namespace std;
int n, m;

struct Node {
  vector < int > adj; //vecteur d'adjacence
  vector < int > rev_adj; //vecteur d'adjacence inverse
};

Node g[MAX_N];

stack < int > S; //pile ou nous allons garder les sommets visités par DFS
bool visited[MAX_N];

int component[MAX_N];
vector < int > components[MAX_N];
int numComponents;

void dfs_1(int x) {
  visited[x] = true;
  for (int i = 0; i < g[x].adj.size(); i++) {
    if (!visited[g[x].adj[i]]) //premier parcours DFS
     dfs_1(g[x].adj[i]);
  }
  S.push(x); //on empile les sommets
}

void dfs_2(int x) {
  printf("%d ", x);
  component[x] = numComponents;
  components[numComponents].push_back(x);  
  visited[x] = true;
  for (int i = 0; i < g[x].rev_adj.size(); i++) {
    if (!visited[g[x].rev_adj[i]]) 
    dfs_2(g[x].rev_adj[i]); //deuxieme parcours DFS
  }
}

void Kosaraju() {
  for (int i = 0; i < n; i++)
    if (!visited[i]) dfs_1(i); //premier parcours DFS du graphe

  for (int i = 0; i < n; i++)
    visited[i] = false;  //remettre visité a faux pour faire le deuxieme parcours DFS

  while (!S.empty()) {
    int v = S.top(); //On depile et si le noeud est non visité, on fait le deuxieme parcous DFS
    S.pop();
    if (!visited[v]) {
      printf("Component %d: ", numComponents);
      dfs_2(v);
      numComponents++;
      printf("\n");
    }
  }
}

int main() {
  cout << "Veuillez copier et coller un des graphes dans les fichiers test.txt\n";
  cin >> n >> m; //Saisir le nombre de sommets et le nombre d'aretes
  int a, b;  
  while (m--) {
    cin >> a >> b; //saisir les arc par ex 1 2 (arc entre sommet 1 et sommet 2)
    g[a].adj.push_back(b);
    g[b].rev_adj.push_back(a);
  }
  auto start = std::chrono::system_clock::now();
    // Some computation here
  Kosaraju();
  printf("Total number of components: %d\n", numComponents);
  auto end = std::chrono::system_clock::now();
 
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  std::cout << "finished computation at " << std::ctime(&end_time)
            << "elapsed time: " << elapsed_seconds.count() << "s"
            << std::endl;
  return 0;
}