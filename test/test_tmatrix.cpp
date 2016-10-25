#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length) // может создать матрицу с положительной длины
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix) // не может создать слишком большую матрицу
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length) // не можем созадть матрицу с отрицательной длинной
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix) // созадть копию матрицы
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one) // скопированая матрица равна одному источнику
{
 
	TMatrix <int> m (5); 
	m[0][0] = 1; 
	TMatrix <int> m1 (m); 
	EXPECT_EQ (m, m1); 

}

TEST(TMatrix, copied_matrix_has_its_own_memory) // скопирована матрица имеет свою собственную память
{
	TMatrix <int> m (4);
	TMatrix <int> m1 (m);
    m [0][0] = 1; 
    EXPECT_NE (m [0][0], m1 [0][0]); 
}

TEST(TMatrix, can_get_size) // получить размер
{
	TMatrix <int> m (3); 
	EXPECT_EQ (3, m.GetSize ()); 
}

TEST(TMatrix, can_set_and_get_element) // можно установить и получить элемент
{
  
	TMatrix <int> m (6); 
	m [0][1] = 1; 
	EXPECT_EQ (1, m [0][1]); 
}

TEST(TMatrix, throws_when_set_element_with_negative_index)  // исключение, когда установлен элемент с отрицательным индексом
{
  TMatrix <int> m (3); 
	ASSERT_ANY_THROW (m [0][-1]); 
}

TEST(TMatrix, throws_when_set_element_with_too_large_index) // исключение, когда установлен элемент со слишком большим индексом
{
  TMatrix <int> m (5); 
    ASSERT_ANY_THROW (m [0][5]); 
}

TEST(TMatrix, can_assign_matrix_to_itself) // может присвоить себе матрицу
{
  TMatrix <int> m (5); 
	ASSERT_NO_THROW (m = m); 
}

TEST(TMatrix, can_assign_matrices_of_equal_size) // может назначить матрицы одинакового размера
{
	TMatrix <int> m1 (3), m2 (3); 
	for (int i = 0; i < 3; i ++) 
		m1 [i][i] = i; 
	m2 = m1; 
	EXPECT_EQ (m1, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size) // назначить оператора размер изменение матрицы
{
  TMatrix <int> m1 (10), m2 (5); 
    m1 = m2; 
    EXPECT_EQ (5, m1.GetSize ()); 
}

TEST(TMatrix, can_assign_matrices_of_different_size) // может назначить матриц различного размера
{
  TMatrix <int> m1 (10), m2 (5); 
	for (int i = 0; i < 10; i ++) 
		m1 [i][i] = i; 
	m2 = m1; 
	EXPECT_EQ (m1, m2); 
}

TEST(TMatrix, compare_equal_matrices_return_true) // сравнить равные матрицы возвращает истину
{
 TMatrix <int> m1 (3), m2 (3); 
	EXPECT_EQ(true, m1 == m2); 
}

TEST(TMatrix, compare_matrix_with_itself_return_true) // сравнить матрицу с собой возвращает истину
{
  TMatrix <int> m1 (10); 
	EXPECT_EQ (true, m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal) //матрицы с различным размером не равны
{
  TMatrix <int> m1 (2), m2 (4); 
	EXPECT_EQ (true, m1 != m2); 
}

TEST(TMatrix, can_add_matrices_with_equal_size) // могут добавлять матрицы с одинаковым размером
{
  TMatrix <int> m1 (5), m2 (5), m (5), testM (5); 
	m1 [0][0] = 1;
	m1 [1][1] = 3;
	m2 [0][0] = 5;
	m2 [1][1] = 7;
	m = m1 + m2; 
	testM [0][0] = 6; 
	testM [1][1] = 10; 
	EXPECT_EQ (testM, m); 
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size) // не могут добавлять матрицы с не одинакового размера
{
  TMatrix <int> m1 (2), m2 (4); 
	ASSERT_ANY_THROW (m1 + m2); 
}

TEST(TMatrix, can_subtract_matrices_with_equal_size) // можно вычесть матрицы с одинакового размера
{
  TMatrix <int> m1 (5), m2 (5), m (5), testM (5); 
	m1 [0][0] = 7;
	m1 [1][1] = 5; 
	m2 [0][0] = 3;
	m2 [1][1] = 1;
	m = m1 - m2; 
	testM [0][0] = 4; 
	testM [1][1] = 4; 
	EXPECT_EQ (testM, m); 

}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size) // не может вычесть матрицы с не одинакового размера
{
  	TMatrix <int> m1 (4), m2 (2); 
	ASSERT_ANY_THROW (m1 - m2); 
}
