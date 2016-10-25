#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length) // может создать вектор с положительной длины
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector) //  не может создать слишком большой вектор
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length) // исключение при создании вектора с отрицательной длиной
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex) // исключение при создании вектора с отрицательной StartIndex
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector) // может создать копию вектора
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one) // копия вектора равна  исходному вектору
{
	TVector<int> v(10);
	TVector<int> v1(v);

	EXPECT_EQ(1, v == v1);
	//ADD_FAILURE();
}

TEST(TVector, copied_vector_has_its_own_memory) // скопированный вектор имеет свою собственную память
{
	TVector<int> v(10);
	TVector<int> v1(v);
	v[0] = 321;		// у одного вектора нулевую ячейку зададим 321 у другого 123, если бы у них была одна память то и у v и v1 указывали бы на последнее присовееное значение, то есть 123
	v1[0] = 123;	// а если у них разная память, то каждый будет указывать на память со своим значением

	EXPECT_EQ(0, v[0] == v1[0]);
  //ADD_FAILURE();
}

TEST(TVector, can_get_size) // проверить размер
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index) // проверить первый индекс вектора
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element) // проверить присваивание значения элементу вектора
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index) // исключение, когда установлен элемент с отрицательным индексом
{
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[-3]);
  //ADD_FAILURE();
}

TEST(TVector, throws_when_set_element_with_too_large_index) // исключение, когда установлен элемент со слишком большим индексом
{
	TVector<int> v(4,2);

	ASSERT_ANY_THROW(v[8]);
  //ADD_FAILURE();
}

TEST(TVector, can_assign_vector_to_itself) // может присвоить себе вектор  
{
	TVector <int> v1 (4);
	ASSERT_NO_THROW (v1 = v1); 
}

TEST(TVector, can_assign_vectors_of_equal_size) // может присваивать векторов одинакового размера 
{
	const int size1 = 2, size2 = 5;
	TVector<int> v1(size1), v2(size2);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = i;
	}
	v2 = v1;

	EXPECT_EQ(v2, v1);
	//ADD_FAILURE();
}

TEST(TVector, assign_operator_change_vector_size) // присваивать оператор изменения вектора размера 
{
	const int size1 = 2, size2 = 5;
	TVector<int> v1(size1), v2(size2);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = i;
	}
	v2 = v1;

	EXPECT_EQ(v2, v1);
	//ADD_FAILURE();
}

TEST(TVector, can_assign_vectors_of_different_size) // может назначить векторы разного размера 
{
		TVector <int> v1 (3), v2 (5);
	for (int i = 0; i < 3; i ++)
		v1 [i] = 1;
	v2 = v1;
	EXPECT_NE (0, v2 [0]);
	
}

TEST(TVector, compare_equal_vectors_return_true) // сравнить равные векторы возвращает истину
{
	const int size1 = 2, size2 = 5;
	TVector<int> v1(size1), v2(size2);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = i;
	}
	v2 = v1;

	EXPECT_EQ(1,v2 == v1);
	//ADD_FAILURE();
}

TEST(TVector, compare_vector_with_itself_return_true) // сравнить вектор с собой возвращает истину 
{
	TVector<int> v1(5);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = i;
	}
	TVector<int> v2(v1);

	EXPECT_EQ(1,v2 == v1);
	//ADD_FAILURE();
}

TEST(TVector, vectors_with_different_size_are_not_equal) // векторы с различным размером не равны
{
	TVector<int> v1(5), v2(10);

	EXPECT_EQ(1,v2 != v1);
	//ADD_FAILURE();
}

TEST(TVector, can_add_scalar_to_vector) // можно добавить скаляр вектора
{
	TVector<int> v1(5);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = i;
	}
	v1[0] = v1[0] + 3;

	EXPECT_EQ(3,v1[0]);
	//ADD_FAILURE();
}

TEST(TVector, can_subtract_scalar_from_vector) // можно вычесть скаляр из вектора
{
	TVector<int> v1(5);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = i;
	}
	v1[4] = v1[4] - 2;

	EXPECT_EQ(2,v1[4]);
	//ADD_FAILURE();
}

TEST(TVector, can_multiply_scalar_by_vector) // можно умножить скалярные вектором
{
	TVector<int> v1(5);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = i;
	}
	v1[4] = v1[4]*2;

	EXPECT_EQ(8,v1[4]);
	//ADD_FAILURE();
}

TEST(TVector, can_add_vectors_with_equal_size) // могут добавлять векторы с одинаковым размером
{
	TVector<int> v1(5), v2(5), v3(5);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = i;
		v2[i] = i;
		v3[i] = i*2;
	}	

	EXPECT_EQ(v3, v1 + v2);
	//ADD_FAILURE();
}

TEST(TVector, cant_add_vectors_with_not_equal_size) // не могут добавлять векторы с не одинакового размера
{
	TVector<int> v1(5), v2(10);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = i;
		v2[i] = i;
	}	

	EXPECT_EQ(NULL, v1 + v2);
	//ADD_FAILURE();
}

TEST(TVector, can_subtract_vectors_with_equal_size) // можно вычесть векторы с одинакового размера
{
	TVector<int> v1(5), v2(5), v3(5);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = i;
		v2[i] = i;
		v3[i] = 0;
	}	

	EXPECT_EQ(v3, v1 - v2);
	//ADD_FAILURE();
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size) // не могут вычитать векторы с не одинакового размера
{
	TVector<int> v1(5), v2(10);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = i;
		v2[i] = i;
	}	

	EXPECT_EQ(NULL, v1 - v2);
	//ADD_FAILURE();
}

TEST(TVector, can_multiply_vectors_with_equal_size) // можно умножить векторы с одинакового размера
{
	TVector<int> v1(5), v2(5), v3(5);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = 2;
		v2[i] = 3;
		v3[i] = 6;
	}	

	EXPECT_EQ(v3, v1 * v2);
	//ADD_FAILURE();
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size) // нельзя умножить векторы с одинакового размера
{
	TVector<int> v1(5), v2(10);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = i;
		v2[i] = i;
	}	

	EXPECT_EQ(NULL, v1 * v2);
	//ADD_FAILURE();
}

