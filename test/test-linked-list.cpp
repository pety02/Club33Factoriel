#include "catch2/catch_all.hpp"
#include "simulator-lib/linked-list.h"

TEST_CASE("creation of new empty list")
{
	LinkedList<int> mockList;
	
	REQUIRE(mockList.size() == 0);
}

TEST_CASE("list with three elements")
{
	LinkedList<int> mockList;
	mockList.pushBack(15);
	mockList.pushBack(3);
	mockList.pushBack(2);
	
	REQUIRE(mockList.size() == 3);
}

TEST_CASE("if list is empty")
{
	SECTION("new empty list")
	{
		LinkedList<int> mockList;
		
		REQUIRE(mockList.size() == 0);
	}

	SECTION("not empty list becomes empty") 
	{
		LinkedList<int> mockList;
		mockList.pushFront(1);
		mockList.pushFront(2);
		
		REQUIRE(mockList.isEmpty() == false);
		
		mockList.popFront();
		mockList.popFront();
		
		REQUIRE(mockList.isEmpty() == true);
	}
}

TEST_CASE("reversed list")
{
	LinkedList<int> mockList;
	mockList.pushFront(1);
	mockList.pushFront(2);
	int backEl = mockList.back();
	mockList.reverse();
	
	REQUIRE(mockList.front() == backEl);
}

TEST_CASE("get size of a list")
{
	LinkedList<int> mockList;
	mockList.pushFront(1);
	mockList.pushFront(2);
	
	REQUIRE(mockList.size() == 2);
}