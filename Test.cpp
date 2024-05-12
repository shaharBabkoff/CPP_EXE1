//id:324207935
//email:shbabkoff123@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        {0, 7, -10, 3, -5},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}};
    g.loadGraph(graph4, false);
    CHECK(Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2"); // test with regular path

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "-1"); // test with no path at all between the vertices

    vector<vector<int>> graph3 = {
        {0, 0, 0, 4, -5},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {11, 4, 0, 0, 0},
        {0, 0, 0, -5, 0}};

    g.loadGraph(graph3);
    CHECK(Algorithms::shortestPath(g, 0, 1) == "0->4->3->1"); // test with nagitive path

    vector<vector<int>> graph4 = {
        {0, 0, 0, -1},
        {-1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, -1, 4, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "-1"); // test with nagative cycle
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1, false);
    CHECK(Algorithms::isContainsCycle(g) == false); // undirected graph with no cycle

    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 0},
        {1, 0, -5, 0, 0},
        {0, -5, 0, 4, 0},
        {0, 0, 4, 0, 9},
        {0, 0, 0, 9, 0}};
    g.loadGraph(graph2, false);
    CHECK(Algorithms::isContainsCycle(g) == false); // undirected graph with no cycle

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, -5, 0, 0},
        {0, -5, 0, 4, 0},
        {0, 0, 4, 0, 9},
        {0, 0, 0, 9, 0}};
    g.loadGraph(graph3, true);
    CHECK(Algorithms::isContainsCycle(g) == true); // directed graph with cycle
    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isContainsCycle(g) == true); // directed graph with cycle

    vector<vector<int>> graph5 = {
        {0, -5, 0, 0, 0},
        {-5, 0, 0, 0, 0},
        {0, 0, 0, -5, 0},
        {0, 0, -5, 0, -5},
        {0, 0, 0, -5, 0}};
    g.loadGraph(graph5, false);
    CHECK(Algorithms::isContainsCycle(g) == false); // undirected graph with no cycle
    vector<vector<int>> graph6 = {
        {0, -4, 1},
        {0, 0, 0},
        {0, -7, 0}};
    g.loadGraph(graph6);
    CHECK(Algorithms::isContainsCycle(g) == false); // directed graph with no cycle
    vector<vector<int>> graph7 = {
        {0, -4, 1},
        {-4, 0, -7},
        {1, -7, 0}};
    g.loadGraph(graph7, false);
    CHECK(Algorithms::isContainsCycle(g) == true); // undirected graph with cycle
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
    vector<vector<int>> graph4 = {
        {0, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 4, 4},
        {0, 0, 0, 0, -10, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2, 3}, B={4, 5}");
    vector<vector<int>> graph5 = {
        {0, 3, 0, 3},
        {3, 0, 3, 0},
        {3, 0, 0, 3},
        {0, 3, 0, 0}};
    g.loadGraph(graph5);
    CHECK(Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test negativeycle")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, -5, 0, 0, 0},
        {-5, 0, 0, 0, 0},
        {0, 0, 0, -5, 0},
        {0, 0, 0, 0, -5},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::negativeCycle(g) == "0 -> 1 -> 0"); 

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::negativeCycle(g) == "No negative cycle detected."); 

    vector<vector<int>> graph3 = {
        {0, 3, 0},
        {0, 0, -10},
        {-10, 0, 0}};

    g.loadGraph(graph3);
    CHECK(Algorithms::negativeCycle(g) == "1 -> 2 -> 0 -> 1"); 
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph1));

    vector<vector<int>> graph2 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph2));

    vector<vector<int>> graph3 = {//undirected graph not symetric
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 3, 0}};
    CHECK_THROWS(g.loadGraph(graph3, false));

    vector<vector<int>> graph4 = {
        {0, 1, 2, 0, -7},
        {1, 0, 3, 0, 7},
        {2, 3, 0, 4, 4},
        {0, 0, 4, 0, 3},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph4));
}
