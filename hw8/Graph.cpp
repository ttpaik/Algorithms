#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include "Graph.h"
using namespace std;

Graph::Graph() {

}

int Graph::addVertex() {
	int nVer = getNumVertices();
	vertices.insert(nVer);
	return nVer;
}

void Graph::addEdge(directedEdge newEdge, int weight) {
	if (isEdge(newEdge) == false) {
		edges.insert({ newEdge.first, newEdge.second });
		weights[{newEdge.first, newEdge.second}] = weight;
	}
}

int Graph::getNumVertices() {
	int v;
	v = vertices.size();
	return v;
}

int Graph::getWeight(directedEdge edge) {
	int w;
	w = weights[{edge.first, edge.second}];
	return w;
}

bool Graph::isEdge(directedEdge newEdge) {
	if (edges.find(newEdge) != edges.end()) {
		return true;
	}

	else {
		return false;
	}
}

void Graph::print() {
	itv it_prt;
	ite it_prt2;

	for (it_prt = vertices.begin(); it_prt != vertices.end(); ++it_prt) {
		cout << *it_prt << ": ";
		for (it_prt2 = edges.begin(); it_prt2 != edges.end(); ++it_prt2) {
			if (*it_prt == (*it_prt2).first) {
				cout << (*it_prt2).second << " " << "(" << getWeight(*it_prt2) << ")" << " ";
			}
		}
		cout << endl;
	}
}

void Graph::generateGraph(string fileName) {
	ifstream Grp;
	string Vl, arr[3];
	int nw, nv, nl= 0;
	directedEdge addedEdge;

	Grp.open(fileName);
	if (Grp.is_open()) {
		for (int nl = 0; getline(Grp, Vl); nl++) {
			if (nl == 0) {
				nv = Vl[0] - '0';

				while (nv != 0) {
					addVertex();
					nv--;
				}
			}

			else if (nl > 0) {
				stringstream ssin(Vl);

				if (ssin.good()) {
					ssin >> arr[0] >> arr[1] >> arr[2];
				}

				addedEdge.first = atoi(arr[0].c_str());
				addedEdge.second = atoi(arr[1].c_str());
				nw = atoi(arr[2].c_str());
				addEdge(addedEdge, nw);
			}
		}
	}
}

// Initializing all vertices to infinity, and then setting the source vertices to zero is the first step.
// Create a temporary vector and do the same, we can compare the weights/distance by calling either .first or .second of the pair.
// While extracting minimum distance from the temp, assign extracted vertex as a new variable.
// Then we can loop through adjacent of the extracted to find the path to the destination.
// If shorter than the previous iteration, then select that distance as the shortest path.
void Graph::modifiedDijkstra(int source) {
	vector<int> nd, imsi, shortp;
	set<int> ps;
	int Vrn;
	ite it_ite;

	for (int init = 0; init < getNumVertices(); init++) {
		shortp.push_back(0);
		nd.push_back(INT_MAX);
		imsi.push_back(INT_MAX);
	}

	nd[source] = 0;
	imsi[source] = 0;

	while (imsi.empty() != true) {
		for (int iso = 0; iso < nd.size(); iso++) {
			if (*min_element(imsi.begin(), imsi.end()) == nd[iso]) {
				Vrn = iso;
			}
		}

		for (it_ite = edges.begin(); it_ite != edges.end(); it_ite++) {
			
			if (!(ps.end() != ps.find(Vrn)) && (*it_ite).first == Vrn) {

				if ((abs(getWeight(*it_ite) + nd[Vrn])) == abs(nd[(*it_ite).second])) {
					shortp[(*it_ite).second]++;
				}

				else if ((abs(getWeight(*it_ite) + nd[Vrn])) < abs(nd[(*it_ite).second]) && nd[Vrn] != INT_MAX) {
					nd[(*it_ite).second] = (getWeight(*it_ite) + nd[Vrn]);
					shortp[(*it_ite).second]++;
					imsi.push_back(nd[(*it_ite).second]);
				}

				
				

			}
		}
		ps.insert(Vrn);
		imsi.erase(remove(imsi.begin(), imsi.end(), *min_element(imsi.begin(), imsi.end())), imsi.end());
	}

	cout << endl << "Shortest paths from node " << source << ":" << endl;
	for (int path = 0; path < getNumVertices(); path++) {
		if (!(source == path) && abs(nd[path]) < INT_MAX) {
			cout << "Distance to vertex " << path << " is " << nd[path] << " " << "and there are " << shortp[path] << " shortest paths" << endl;
		}

		else if (!(source == path)) {
			cout << "Distance to vertex " << path << " is " << nd[path] << " " << "and there are " << 0 << " shortest paths" << endl;
		}
	}
}