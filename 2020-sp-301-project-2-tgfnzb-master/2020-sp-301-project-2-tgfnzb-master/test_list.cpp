#include "catch.hpp"
#include "MyList.h"
template class MyList<int>;

TEST_CASE("List Sizing", "[list]")
{
  MyList<int> v;

  SECTION("An empty list has size zero")
  {
    CHECK(v.size() == 0);
  }

  SECTION("A copied list has the same size")
  {
    MyList<int> c(v);
    CHECK(v.size() == c.size());
  }

  for(int i = 0; i < 5; i++)
  {
    v.push_back(i);
  }

  SECTION("Adding elements causes the size to change")
  {
    CHECK(v.size() == 5);
  }

  SECTION("Cleared list returns size to zero")
  {
    v.push_front(10);
    v.clear();
    CHECK(v.size() == 0);
  }
}

TEST_CASE("List Elements", "[list]")
{
  MyList<int> v;

  SECTION("Elements pushed front appear at the front.")
  {
    for(int i = 0; i < 5; i++)
    {
      v.push_front(i);
      CHECK(v.front() == i);
    }
  }
  SECTION("Elements pushed back appear at the end.")
  {
    for(int i = 0; i < 5; i++)
    {
      v.push_back(i);
      CHECK(v.back() == i);
    }
  }

  MyList<int> c(v);
  SECTION("A copied list is identical")
  { 
    for(int i = 0; i < v.size(); i++)
    {
      CHECK(v.back() == c.back());
      v.pop_back();
      c.pop_back();
    }
  }
  SECTION("List copies are deep copies")
  {
    v.push_front(10);
    c.push_front(5);
    CHECK(c.front() == 5);
    CHECK(v.front() == 10);
  }
}

TEST_CASE("List Modification","[list]")
{
  MyList<int> v;
  SECTION("Assign removes and replaces to count of values")
  {
    v.push_front(1);
    v.push_front(2);
    v.assign(5,10);
    CHECK(v.front() == 10);
    CHECK(v.back() == 10);
  }
  SECTION("Push front and back pushes at respective locations")
  {
    v.push_front(1);
    v.push_back(2);
    CHECK(v.front() == 1);
    CHECK(v.back() == 2);
  }
  SECTION("Push and pop change sizing")
  {
    v.push_front(1);
    v.push_front(2);
    v.push_front(3);
    v.pop_back();
    v.pop_front();
    CHECK(v.size() == 1);
  }
  SECTION("Reverse flips element ordering")
  {
    for(int x =0 ; x < 5; x++)
    {
      v.push_back(x);
    }
    v.reverse();
    for(int x=0; x < 5; x++)
    {
      CHECK(v.back() == x);
      v.pop_back();
    }
  }
  v.insert(0,25);
  v.insert(0,25);
  v.insert(0,24);

  SECTION("Can insert in 0 big list")
  {
    CHECK(v.front() == 24);
  }

  v.remove(25);
  SECTION("Remove corrects size and removes all instances of int")
  {
    CHECK(v.size() == 1);
    CHECK(v.front() == 24);
  }

  v.erase(0);
  SECTION("Erase function Erases element at certain position")
  {
    CHECK(v.size() == 0);
  }

  SECTION("Empty list should return true")
  {
    CHECK(v.empty() == true);
  }

  
}