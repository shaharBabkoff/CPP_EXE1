#include <iostream>
#include <stdexcept>
#include <vector>
#include "Graph.hpp"
using namespace std;
namespace ariel
{
   void Graph::loadGraph(vector<vector<int>> g){
        graph_ = g;
    }
void Graph::printGraph(){
    for (vector<int> row : graph_){
        for (int value : row)
        {
            cout << value <<" "<<endl;
        }

    }
}
    
} // namespace ariel

