#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void dfs(const int &k, vector<bool> &adj, vector<vector <int>> &adjacency_list);

void Connectivity(string test, string rezult)
{
	vector<vector <int>> adjacency_list;
	ifstream fInput;
	fInput.open(test);
	string row;
		while (getline(fInput, row))
		{
		stringstream vertices(row);
		string vert;
		vector<int> adjacent_vertices;
		while (getline(vertices, vert, ' '))
			adjacent_vertices.push_back(stoi(vert));
		adjacency_list.push_back(adjacent_vertices);
		}

	vector<bool> adj(adjacency_list.size(), false);
	/*adj[0] = true;
	for (int i = 0; i < adj.size(); i++)
	{
		for (int k = 0; k < adj.size(); k++)
		{
			if (adj[k] == true)
				for (int j : adjacency_list[k])
					adj[j - 1] = true;		

		}
	}*/
	dfs(0, adj, adjacency_list);

	ofstream fOutput;
	fOutput.open(rezult);
	for (bool element : adj)
		if (element == false) 
		{
			fOutput << "Disonnected graph.";
			fOutput.close();
		}
	fOutput << "Сonnected graph.";
	fOutput.close();

}
void dfs(const int& k, vector<bool>& adj, vector<vector <int>>& adjacency_list)
{
	adj[k] = true;
	for (int j : adjacency_list[k])
	{
		if (!adj[j - 1])
			dfs(j - 1, adj, adjacency_list);
	}
}

int main()
{
	Connectivity("test1.txt", "rezult1.txt");
	Connectivity("test2.txt", "rezult2.txt");
	Connectivity("test3.txt", "rezult3.txt");
	Connectivity("test4.txt", "rezult4.txt");
	Connectivity("test5.txt", "rezult5.txt");
}


