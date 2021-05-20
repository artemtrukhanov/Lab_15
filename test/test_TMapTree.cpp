#include <../gtest/gtest.h>
#include "TMapTree.h"

using namespace std;

TEST(TMapTree, can_create_tree_map)
{
	TMapTree<int, int> a;
	ASSERT_NO_THROW(a);
}

TEST(TMapTree, can_add_elem)
{
	TMapTree<string, int> a;
	a.Add("Hello", 10);
	EXPECT_EQ(10, a["Hello"]);
}

TEST(TMapTree, can_find_elem)
{
	TMapTree<string, int> a;
	a.Add("Hello", 10);
	a.Add("World", 20);
	a.Add("nice", 30);
	EXPECT_EQ(20, a.Find("World"));
}

TEST(TMapTree, can_delete_elem)
{
	TMapTree<string, int> a;
	a.Add("Hello", 10);
	a.Add("World", 20);
	a.Add("nice", 30);
	a.Delete("nice");
	ASSERT_ANY_THROW(a.Find("nice"));
}

TEST(TTreeMap, can_index_elem)
{
	TMapTree<int, double> e;
	e.Add(2, 2);
	e.Add(1, 1);
	e.Add(3, 3);
	vector<double> v;
	v.push_back(e[1]);
	v.push_back(e[3]);
	v.push_back(e[2]);
	vector<double> expv = { 1,3,2 };
	EXPECT_EQ(expv, v);
}

TEST(TTreeMap, can_iterate_object)
{
	TMapTree<string, int> a;
	a.Add("Hello", 20);
	a.Add("World", 30);
	a.Add("nice", 10);
	int sorted[3] = { 20, 30, 10 };
	int i = 0;
	TMapTree<string, int>::iterator it = a.Begin();
	while (it.IsEnd()) {
		EXPECT_EQ(sorted[i], it.Get()->GetVal());
		it.GoNext();
		i++;
	}
}

