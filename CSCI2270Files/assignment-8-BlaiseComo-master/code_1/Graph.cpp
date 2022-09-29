#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;


void Graph::addVertex(string name){
    //TODO
    for (long unsigned int i = 0; i < vertices.size(); i++) {
        if (vertices[i]->name == name) {
            cout << name << " found." << endl;
            return;
        }
    }
    vertex* newVertex = new vertex;
    newVertex->name = name;
    vertices.push_back(newVertex);
}

void Graph::addEdge(string v1, string v2){
    //TODO
    vertex* v1Vertex;
    bool v1Bool = false;
    vertex* v2Vertex;
    bool v2Bool = false;
    for (long unsigned int i = 0; i < vertices.size(); i++) {
        if (vertices[i]->name == v1) {
            v1Vertex = vertices[i];
            v1Bool = true;
        }
        else if (vertices[i]->name == v2) {
            v2Vertex = vertices[i];
            v2Bool = true;
        }
    }
    if (v1Bool == true && v2Bool == true) {
        adjVertex v1AdjVertex;
        v1AdjVertex.v = v2Vertex;
        v1Vertex->adj.push_back(v1AdjVertex);
        adjVertex v2AdjVertex;
        v2AdjVertex.v = v1Vertex;
        v2Vertex->adj.push_back(v2AdjVertex);
    }
}

void Graph::displayEdges(){
    //TODO
    for (long unsigned int i = 0; i < vertices.size(); i++) {
        cout << vertices[i]->name << " -->";
        for (long unsigned int x = 0; x < vertices[i]->adj.size(); x++) {
            cout << " " << vertices[i]->adj[x].v->name;
        }
        cout << " " << endl;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex){
    //TODO
    vertex* source;
    bool found = false;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i]->name == sourceVertex) {
            source = vertices[i];
            found = true;
            break;
        }
    }

    if (found == true) {

        cout << "Starting vertex (root): " << source->name << "-> ";
        source->visited = true;

        queue<vertex*> importantQueue;

        importantQueue.push(source);

        int count = 0;

        while (!importantQueue.empty()) {

            vertex* temp = importantQueue.front();
            importantQueue.pop();
            
            if (count > 0) {
                cout << temp->name << "(" << temp->distance << ") ";
            }

            count++;

            for (int i = 0; i < temp->adj.size(); i++) {

                if (temp->adj[i].v->visited == false) {
                    temp->adj[i].v->visited = true;
                    importantQueue.push(temp->adj[i].v);
                    temp->adj[i].v->distance = temp->distance+1;
                }

            }

        }

        cout << endl << endl;

    }

    for (int i = 0; i < vertices.size(); i++) {
        vertices[i]->visited = false;
        vertices[i]->distance = 0;
    }
}

void shortestPathPrintHelper(int importantInt, string source, vertex* destinationVertex) {

    bool flag = false;

    while (!flag && destinationVertex->previous != NULL) {

        cout << destinationVertex->name << endl;

        if (destinationVertex->name == source) {
            flag = true;
            break;
        }
        
        destinationVertex = destinationVertex->previous;

    }

}

int Graph::findShortestPathBetweenBuildings(string source, string dest) {
    //TODO
    
    vertex* traverser;
    bool found = false;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i]->name == source) {
            traverser = vertices[i];
            found = true;
        }  
    }
    

    if (found == true) {

        queue<vertex*> importantQueue;

        importantQueue.push(traverser);

        int count = 0;

        while (!importantQueue.empty()) {

            vertex* temp = importantQueue.front();
            importantQueue.pop();


            for (int i = 0; i < temp->adj.size(); i++) {

                if (temp->adj[i].v->visited == false) {
                    temp->adj[i].v->previous = temp;
                    temp->adj[i].v->visited = true;
                    importantQueue.push(temp->adj[i].v);
                    temp->adj[i].v->distance = temp->distance+1;
                }

                if (temp->adj[i].v->name == dest) {
                    int importantInt = temp->adj[i].v->distance;
                    vertex* destinationVertex = temp->adj[i].v;
                    shortestPathPrintHelper(importantInt, source, destinationVertex);
                    cout << "Shortest Path Distance: " << temp->adj[i].v->distance << endl;
                    return temp->adj[i].v->distance;
                }

            }

        }

    }

    
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i]->visited = false;
        vertices[i]->distance = 0;
    }
    
    return 0;
}

