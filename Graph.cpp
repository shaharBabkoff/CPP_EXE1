//id:324207935
//email:shbabkoff123@gmail.com
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Graph.hpp"
using namespace std;
namespace ariel
{
    void Graph::loadGraph(vector<vector<int>> g, bool isDirected)
    {
        isDirected_ = isDirected;
        verticesNum_ = g.size();
        adjacenctMat_ = g;
        size_t edgeCounter = 0;
        

        for (vector<int> i : adjacenctMat_)//checking valid input(square matrix)
        {
            if (i.size() != verticesNum_)
            {
                std::invalid_argument dimensions("Invalid graph: The graph is not a square matrix.");
                throw (dimensions);
            }
        } 
        
        if (!isDirected_)//if the graph is undirected, cheking if the matrix is symetric
        {
            for (size_t i =0; i < verticesNum_; i++)
            {
                for (size_t j = 0; j < verticesNum_; j++)
                {
                    if (adjacenctMat_[i][j] != adjacenctMat_[j][i])
                    {
                            invalid_argument symetry("Invalid graph: the graph is not directed however not symetric");
                            throw (symetry);
                    }
                }
            }
        }

        for (vector<int> row : adjacenctMat_)
        {
            for (int value : row)
            {
                if (value != 0)
                {
                    edgeCounter++;
                }
            }
        }
        if (isDirected_ == false)
        {
            edgesNum_ = edgeCounter / 2;
        }
        else
        {
            edgesNum_ = edgeCounter;
        }
    }
    void Graph::printGraph()
    {

        for (vector<int> row : adjacenctMat_)
        {
            for (int value : row)
            {
                cout << value << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "Graph with " << verticesNum_ << " vertices and " << edgesNum_ << " edges." << endl;
    }

  const vector<vector<int>>& Graph :: getAdjacenctMat() const {
        return adjacenctMat_;
    }
    size_t Graph::getVerticesNum() const
    {
        return verticesNum_;
    }
     size_t Graph::getEdgesNum() const
    {
        return edgesNum_;
    }
    bool Graph::isDirected() const{
        return isDirected_;
    }
} // namespace ariel
