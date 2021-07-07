/* Sample tester
 * We've included std::list below to show you how your types should behave.
 * You can use that for debugging.
 * Add the -g flag if you want to use gdb or cgdb
 */

// Use this to test, but not for your actual program.
#include <list>

// This is yours
#include "MyList.h"

int main()
{
    MyList<int> k;
    k.push_front(5);
    k.push_back(10);
    k.insert(0,51);
    k.erase(3);
    MyList<int> l;
    l = k;
    //std::list<int> l;
    // Make your hpp file with empty definitions other than your constructor
    // Build one function at a time, and only add one "test" line at a time to this file.
    // Uncomment and add lines below here 1 at a time.
    // This file is just an example, and may not behave as expected!
    // Test all your MyList functions here or in multiple mains (I suggest one function test per file)

    //should we worry about user inputting invalid position?
    cout<<"RESULTS"<<endl;
    int j = 0;
    cout<<"Size: "<<l.size()<<endl;
    for(auto i = 0; i < l.size()+j; i++)
    {
        cout << l.front() << endl;
        l.pop_front();
        j++;
    }
    return 0;
}

