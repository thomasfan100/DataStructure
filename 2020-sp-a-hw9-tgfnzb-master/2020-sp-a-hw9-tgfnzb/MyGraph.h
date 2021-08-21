#ifndef MYGRAPH_H
#define MYGRAPH_H

#include "graph.h"

#define UNVISITED 0
#define VISITED 1

// Define your MyGraph class
// Inherit the abstract Graph class with public demotion.
// You can use whatever backend you like (hash tables, matrices, linked lists, etc.,).
// You can add as many functions as you like.
// You don't need a cpp/hpp file for this, and can just define everything in the h.

class MyGraph: public Graph
{
    private:
        int numNode, numEdge;
        float **matrix;
        float *cost;
        string *names;
        int *mark;
    public:
        void printinfo()
        {
            cout<< "NAMES"<<endl;
            for(int x = 0 ; x < numNode; x++)
                cout<<names[x]<<" | ";
            cout<<endl;
            cout<<"COSTS"<<endl;
            for(int x = 0; x < numNode; x++)
                cout<<cost[x]<<" | ";
            cout<<endl;
            cout<<"MATRIX"<<endl;
            for(int x = 0; x < numNode; x++)
            {
                for(int y = 0 ; y < numNode; y++)
                {
                    cout<<matrix[x][y]<<" ";
                }
                cout<<endl;
            }
            cout<< "MARK"<<endl;
            for(int x = 0; x < numNode; x++)
                cout<<mark[x]<<" | ";

            cout<<endl;
            return;
        }
        //Constructor
        MyGraph(int num_of_nodes)
        {
            int i;
            numNode = num_of_nodes;
            numEdge = 0;
            mark = new int[num_of_nodes];

            for(i = 0; i < numNode; i++)
                mark[i] = UNVISITED;

            matrix = new float *[numNode];
            for(i = 0; i < numNode; i++)
                matrix[i] = new float[numNode]{0};
            for(i = 0; i< numNode; i++)
                for(int j = 0; j < numNode; j++)
                    matrix[i][j] = 0;

            cost = new float [numNode]{0};
            names = new string [numNode]{""};
        }
        //Destructor
        ~MyGraph()
        {
            for(int i = 0; i< numNode; i++)
                delete[] matrix[i];
            delete[] matrix;
            delete[] mark;
            delete[] cost;
            delete[] names;
        }
        int getMark(int v)
        {
            return mark[v];
        }
        void setMark(int v, int val)
        {
            mark[v] = val;
        }
        int getNumNodes()
        {
            return numNode;
        }
        int getNumEdges()
        {
            return numEdge;
        }
        float weight(int v1, int v2)
        {
            return matrix[v1][v2];
        }
        //...................................................................//
        // Get's index of the first neighbor of a node (indexing starts at 0)
        int get_first_neighbor(int vert)
        {
            for(int i = 0; i < numNode; i++)
                if(matrix[vert][i] != 0)
                    return i;
            return numNode;
        }

        // When there are no more neighbors after prev_neigh, return n (number of nodes in the graph)
        int get_next_neighbor(int vert, int prev_neigh)
        {
            for(int i = prev_neigh+1; i < numNode; i++)
                if(matrix[vert][i] != 0)
                    return i;
            return numNode;
        }
        // Returns the number of nodes
        int n_nodes()
        {
            return numNode;
        }
        // Returns the number of edges
        int n_edges()
        {
            return numEdge;
        }
        // Sets the weight of an edge
        void set_edge(int v1, int v2, float wght)
        {
            //Assert(wt > 0, "Illegal weight value");
            if(matrix[v1][v2] == 0)
                numEdge++;
            matrix[v1][v2] = wght;
        }
        // Sets edge weight to 0
        void del_edge(int v1, int v2)
        {
            if(matrix[v1][v2] != 0)
                numEdge--;
            else
                cout << "Edge did not exist"<<endl;
            matrix[v1][v2] = 0;
        }
        // Get's the edge weight
        float get_edge(int v1, int v2)
        {
            return matrix[v1][v2];
        }
        // Set a node's (v) bribe cost
        void set_bribe(int v, float bribe)
        {
            cost[v] = bribe;
            return;
        }
        // Get's a node's (v) bribe cost
        float get_bribe(int v)
        {
            return cost[v];
        }
        // Set a node (v) name
        void set_node_name(int v, string name)
        {
            names[v] = name;
            return;
        }
        // Get's a nodes (v) name
        string get_node_name(int v)
        {
            return names[v];
        }
};

#endif

