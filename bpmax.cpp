#include <iostream>
#include <string.h>

using namespace std;

bool isMatching(bool **graph, int t, bool visited[], int assigned[],int n) {

	for (int p = 0; p < n; p++) {

		if (graph[t][p] && visited[p] != true) {

			visited[p] = true;

			if (assigned[p] == -99 || isMatching(graph, assigned[p], visited, assigned,n)) {

				assigned[p] = t;

				return true;
			}
		}
	}
	return false;
}


// this function returns the maximum number of matches that can be made in a bipartite graph
int maximumMatching(bool**graph,int n) {

	int a[n], t= 0;

	bool visited[n];

	for (int p= 0; p< n; p++)
		a[p] = -99;

	for (int q= 0; q< n; q++) {

		for (int p = 0; p < n; p++)
			visited[p] = false;

		if (isMatching(graph, q, visited, a,n) == true)
			t++;
	}

	return t;
}

// main code
int main()
{
    cout<<"Enter the number of vertices\n";
    int t;
    cin>>t;
    const int n=t;
	bool **graph;
	graph=new bool*[n];
	cout<<"Enter the bipartite graph:\n";
	for(int i=0;i<n;i++){
        graph[i]=new bool[n];
        for(int j=0;j<n;j++)
        cin>>graph[i][j];
	}


	cout << "The maximum cover possible is:"<< maximumMatching(graph,n)/2<<endl;

	return 0;
}

