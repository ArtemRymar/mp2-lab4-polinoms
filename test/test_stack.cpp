#include "polinoms.h"
#include "gtest.h"



TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<Monom> list);
}


TEST(List, can_create_list_with_vector)
{
	vector<Monom> a{ {1.3, 234},{23.3, 123} };
	ASSERT_NO_THROW(List<Monom> list(a));
}

TEST(List, can_create_list_with_list)
{
	vector<Monom> a{ {1.3, 234},{23.3, 123} };
	List<Monom> fir(a);
	ASSERT_NO_THROW(List<Monom> list(fir));
}

TEST(List, can_return_size)
{
	vector<Monom> a{ {1.3, 234},{23.3, 123} };
	List<Monom> list(a);
	ASSERT_NO_THROW(list.size());
	EXPECT_EQ(1, list.size());
}

TEST(List, empty_is_empty)
{
	List<Monom> list;
	ASSERT_NO_THROW(list.isEmpty());
	EXPECT_EQ(1, list.isEmpty());
}


TEST(List, error_when_unexpected_pos_in_ToPos)
{
	vector<Monom> a{ {1.3, 234},{23.3, 123} };
	List<Monom> list(a);
	ASSERT_ANY_THROW(list.ToPos(3));
}



TEST(List, error_when_ex_on_null)
{
	vector<Monom> a{ {1.3, 234},{23.3, 123} };
	List<Monom> list(a);
	List<Monom> list2;
	ASSERT_ANY_THROW(list2 = list * 0);
}

TEST(List, error_when_sum_opposite_lists)
{
	vector<Monom> a{ {1.3, 234},{23.3, 123} };
	vector<Monom> b{ {-1.3, 234},{-23.3, 123} };
	List<Monom> list(a);
	List<Monom> list2(b);
	List<Monom> list3;

	ASSERT_ANY_THROW(list3 = list + list2);
}

TEST(List, error_when_ex_on_null_polinom)
{
	vector<Monom> a{ {1.3, 234},{23.3, 123} };
	List<Monom> list(a);
	List<Monom> list2;
	List<Monom> list3;

	ASSERT_ANY_THROW(list3 = list * list2);
}
