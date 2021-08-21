#include "dijkstra.h"
#include "MyHeap.h"

// Simple class to represent objects to be stored in the priority queue
// Store a vertex and its best known distance
class DijkElem
{
    public:
        int vertex;
        float distance;

        DijkElem()
        {
            vertex = -1;
            distance = -1;
        }

        DijkElem(int v, float d)
        {
            vertex = v;
            distance = d;
        }
};

// Implement dikstra function in the corresponding h file.

string dijkstra(MyGraph * graph, std::string question)
{
    string startcurr = "", endcurr = "", temp;
    int startpos, endpos;
    float exchange_cost = 0, bribe_cost = 0; 
    //What is the shortest path from Pesos to Euros?
    for(unsigned int x =0 ; x < question.length(); x++)
    {
        if(question[x] == ' ' || question[x] == '?')
        {
            if(temp[temp.length()-1] == 's')
                temp.pop_back();
            for(int y = 0; y < graph->getNumNodes(); y++)
            {
                if(temp == graph->get_node_name(y) && startcurr == "")
                {
                    startcurr = temp;
                    startpos = y;
                    y = graph->getNumNodes();
                }
                else if (temp == graph->get_node_name(y) && startcurr != "")
                {
                    endcurr = temp;
                    endpos = y;
                    y = graph->getNumNodes();
                }
            }
            temp = "";
        }
        else if(question[x] != '?')
        {
            temp+= question[x];
        }
    }

    //IMPLEMENTING DIJKSTRA
    string solution_path = "";
    float D[graph->getNumNodes()];
    int P[graph->getNumNodes()]; //Previous Vertex
    int order[graph->getNumNodes()];
        
    // Initialize
    for(int i = 0; i < graph->getNumNodes(); i++)
    {
        D[i] = 9999;
        P[i] = -1;
        order[i] = -1;
    }

    int v;            // v is current vertex

    D[startpos] = 0; // set current nodes distance to 0

    DijkElem temp2;
    temp2.distance = 0;
    temp2.vertex = startpos;

    DijkElem E[graph->getNumEdges()];     // array with lots of space (for heap)
    E[0] = temp2;            // Initialize heap array

    MyHeap<DijkElem> H(E, 1); // Create heap

    bool exit = false;
    for(int i = 0; i < graph->getNumNodes(); i++)
    {
        do
        {
            if(H.size() == 0)
            {
                exit = true;
                break; // Nothing to remove
            }
            
            temp2 = H.pop();
            v = temp2.vertex;
        }
        while(graph->getMark(v) == 1 /*VISITED*/);

        if(exit == true)
        {
            exit = false;
            break;
        }
        
        graph->setMark(v, 1/*VISITED*/);

        //need to edit
        if(D[v] == 9999)
            break;    // Unreachable vertices

        for(int w = graph->get_first_neighbor(v); w < graph->getNumNodes(); w = graph->get_next_neighbor(v, w))
        {
            if((D[v] + graph->weight(v, w)) <= D[w])
            {
                //if w is the end vertex meaning w is being changed, we need to check if
                //exchange_cost aka shortest edge path is the same
                //if so, check/track bribe cost
                int t1 = P[endpos],t2 = v; //index of current and new
                float te1 = 0,te2 = 0; //bribe values of current and new
                if( w == endpos && D[w] == D[v]+graph->weight(v,w))
                {
                    while(P[t1] != -1)
                    {
                        te1 += graph->get_bribe(t1);
                        t1 = P[t1];
                    }
                    while(P[t2] != -1)
                    {
                        te2 += graph->get_bribe(t2);
                        t2 = P[t2];
                    }
                    if(te1 <= te2)
                        break;
                }
                //end of checking the same path cost 

                D[w] = D[v] + graph->weight(v, w);
                temp2.distance = D[w];
                temp2.vertex = w;

                //update previous vertex array
                P[w] = v;

                // Insert new distance in heap
                H.push(temp2);
            }
        }
    }
    
    //creating shortest pathing by finding all previous vertices
    //updates bribe cost and exchange cost
    int temp3 = endpos;
    for(int x = graph->getNumNodes()-1; x >= 0; x--)
    {
        if(temp3 == -1)
            break;
        order[x] = temp3;
        temp3 = P[temp3];
    }
    for(int k = 0; k < graph->getNumNodes(); k++)
    {
        if(order[k] != -1)
        {
            solution_path += graph->get_node_name(order[k]) + "s, ";
            bribe_cost += graph->get_bribe(order[k]);
        }
    }
    exchange_cost = D[endpos];
    bribe_cost -= graph->get_bribe(endpos);
    

    exchange_cost = float(int(exchange_cost * 10 + 0.5)) / 10;
    bribe_cost = float(int(bribe_cost * 10 + 0.5)) / 10;
    
    //Output result
    //add node bribes to result.
    string result;
    string new_exchange = to_string(exchange_cost).substr(0, to_string(exchange_cost).find(".")+2);
    string new_bribe = to_string(bribe_cost).substr(0, to_string(bribe_cost).find(".")+2);
    
    if(D[endpos] == 9999)
        result = "There is no path from "+startcurr+"s to "+endcurr+"s.\n";
    else
    {
        result = "The shortest path from "+startcurr+"s to "+endcurr+"s is:\n";
        result = result + solution_path + "with sum exchange cost of "+ new_exchange +
                " and bribe cost of "+ new_bribe +"\n";
    }
        
    return result;
}
