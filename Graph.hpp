#include <vector>
namespace  ariel
{
class Graph
{
private:
    std::vector<std::vector<int>> graph_;
public:
void loadGraph(vector<vector<int>> g);
void printGraph();
};    
} // namespace  ariel
