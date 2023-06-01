#include "tp6.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;

void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
{
	/**
	  * Make a graph from a matrix
	  * first create all nodes, add it to the graph then connect them
      * this->appendNewNode
      * this->nodes[i]->appendNewEdge
      */
    for(int i = 0; i<nodeCount; i++){
        this->appendNewNode(new GraphNode(i));
    }

    for(int i = 0; i<nodeCount; i++){
        for(int j = 0; j<nodeCount; j++){
            if(adjacencies[i][j]>=1){
                this->nodes[i]->appendNewEdge(this->nodes[j], adjacencies[i][j]);
            }
        }
    }
}

void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	  * Fill nodes array by travelling graph starting from first and using recursivity
      */
    int value = first->value;

    visited[value] = true;

    nodes[nodesSize]=first;
    nodesSize++;

    Edge* newEdge = first->edges;
    while(newEdge != nullptr)
    {
        GraphNode* dest = newEdge->destination;
        if (!visited[dest->value]) {
            this->deepTravel(dest, nodes, nodesSize, visited);
        }
        newEdge = newEdge->next;
    }
}

void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	 * Fill nodes array by travelling graph starting from first and using queue
	 * nodeQueue.push(a_node)
	 * nodeQueue.front() -> first node of the queue
	 * nodeQueue.pop() -> remove first node of the queue
	 * nodeQueue.size() -> size of the queue
	 */
	std::queue<GraphNode*> nodeQueue;
	nodeQueue.push(first);

    while(!nodeQueue.empty()){
        GraphNode* firstNode = nodeQueue.front();
        nodeQueue.pop();
        visited[firstNode->value] = true;
        nodes[nodesSize]=first;
        nodesSize++;

        Edge* newEdge = first->edges;
        while(newEdge != nullptr)
        {
            GraphNode* dest = newEdge->destination;
            if (!visited[dest->value]) {
                visited[dest->value] = true;
                nodeQueue.push(newEdge->destination);
                nodes[nodesSize]=dest;
                nodesSize++;
            }

            newEdge = newEdge->next;
        }
    }

}

bool Graph::detectCycle(GraphNode *first, bool visited[])
{
	/**
	  Detect if there is cycle when starting from first
	  (the first may not be in the cycle)
	  Think about what's happen when you get an already visited node
	**/
    std::queue<GraphNode*> nodeQueue;
    nodeQueue.push(first);

    while(!nodeQueue.empty()){
        GraphNode* firstNode = nodeQueue.front();
        nodeQueue.pop();
        visited[firstNode->value] = true;

        Edge* newEdge = first->edges;
        while(newEdge != nullptr)
        {
            if(visited[newEdge->destination->value==false]){
                nodeQueue.push(newEdge->destination);
                newEdge = newEdge->next;
            }else if(newEdge->destination == first){
                return true;
            }

        }
    }

    return false;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 150;
	w = new GraphWindow();
	w->show();

	return a.exec();
}
