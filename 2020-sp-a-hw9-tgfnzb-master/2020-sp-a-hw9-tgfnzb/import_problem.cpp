/**
 * Import one instance of a homework graph problem,
 * You can change anything about this file, as long as it returns what is needed,
 * and does not break the h file.
 * It should return the stripped query line from sample_input*.csv, for example:
 * "What is the shortest path from Pesos to Euros?" (with no quotes, just a std::string)
 * More details in pa09.cpp
 **/
#include "MyGraph.h"

// Put name function here
void get_identity(std::string& my_id)
{
	my_id = "tgfnzb";
	return;
}

string import_problem()
{
    string prob_line;
    // do input processing here
    cin.ignore(256,'\n');
    getline(cin,prob_line);
    getline(cin,prob_line);
    prob_line = prob_line.substr(0,prob_line.length()-6);
    return prob_line;
}
