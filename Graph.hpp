//id:324207935
//email:shbabkoff123@gmail.com
#pragma once
#include <cstddef>
#include <vector>


namespace  ariel
{
class Graph
{
private:
    std::vector<std::vector<int>> adjacenctMat_;
    bool isDirected_;
    size_t verticesNum_;//number of vertices
    size_t edgesNum_;//number of edges
public:

void loadGraph(std::vector<std::vector<int>> g,bool isDirected = true);
void printGraph();
 const std::vector<std::vector<int>>& getAdjacenctMat() const;
 size_t getVerticesNum() const;
 size_t getEdgesNum() const;
 bool isDirected() const;
};    
} // namespace  ariel
