/**
 * Import one instance of a graph,
 * and save it's features in the graph object.
 * Define the import_graph function here.
 * It should create a dynamically allocated object and return it's address
 * You can change this file, as long as it returns what is needed,
 * and does not break the h file, and returns a pointer to your graph.
 * More details about running this in pa09.cpp
 **/

#include "MyGraph.h"


MyGraph * import_graph()
{
    string data;
    int n = 0;
    getline(cin,data);
    for(unsigned int x = 0; x < data.length(); x++)
    {
        if(data[x] == ',')
            n++;
    }
    MyGraph *g_temp = new MyGraph(n);
    

    // Here: Do import on your g object, using public MyGraph functions.
    // You will need to store the graph data and in the MyGraph.
    string name, val_edge;
    int start, end;
    for (int x =0; x<n;x++)
    {
       cin>>name>>val_edge;

       g_temp->set_node_name(x,name);
       for(unsigned int y =0; y < val_edge.length();y++)
       {
           if(val_edge[y] == ')')
                end = y;
       }
       start = 1;
       g_temp->set_bribe(x, std::stof(val_edge.substr(start,end)));
       val_edge = val_edge.substr(end+1);

       int count = 0;
       for(unsigned int y = 0; y < val_edge.length(); y++)
       {
           if(val_edge[y] == ',')
           {
               start = y;
               for(unsigned int z = y+1; z < val_edge.length(); z++)
               {
                   if(z+1 == ',' || z+1 == val_edge.length())
                        end = z;

               }
               g_temp->set_edge(x,count,std::stof(val_edge.substr(start+1,end+1)));
               count++;
           }
       }
    }
    return g_temp;
}


