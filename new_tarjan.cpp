

//Cette partie du code est prise de GeeksForGeeks
//C'est la déclaration d'un graphe + l'algorithme de parcours DFS
#include <bits/stdc++.h>
#include <stack>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
	//On utilise dans ce qui suit des maps au lieu des vecteurs car le parcours des vecteurs est séquentiel
	//Meme en utilisant l'acces par index
	// On déclare une liste des noeuds visités
	// Elle est de type booléen car soit visité soit non visité
	map<int, bool> visited;
    // On déclare la liste des arcs, une liste d'adjacence de v accessible par la clé primaire v
	map<int, list<int> > adj;

	// Une fonction pour ajouter un arc au graphe
	void addEdge(int v, int w);

	//Parcours en profondeur à partir de v 
	void DFS(int v, stack<int> *st);
	//Une fonction qui retourne tout les composants fortement connectés
	//n est le nombre de noeuds du graphe
	void FindSCC(int n);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v,stack<int> *st)
{
	//Visiter un noeud, en rendant le map de sa valeur a vrai
	visited[v] = true;
	cout << v << " ";
	stack<int> stack; //Une pile qui va contenir 
	//Iterer sur tout les neods adjacents du noeud visité
	list<int>::iterator i;
	//on parcours la map, la matrice d'adjacence de v du début à la fin avec list.begin() et list.end()
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		//Si le noeud n'est pas encore visité on le visite récursivement
		if (!visited[*i])
			DFS(*i,st);
}
void Graph::FindSCC(int n){
	int i;
	for(i = 0; i < n; ++i){
		visited[i] = false	;
	}
}

// Driver's code
int main()
{
	// Create a graph given in the above diagram
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";

	// Appel de la fonction DFS en commençant pas le noeud portant la valeur 2
	stack<int> *st = new stack<int>();
	g.DFS(2, st);
	int n = 10; // le nombre des neods du graphe
	return 0;
}

// improved by Vishnudev C
