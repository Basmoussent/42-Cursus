#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template<typename T>
void	iter(T *array, size_t arr_len, void (*foo)(T &))
{
	if (array == NULL || foo == NULL)
		return ;
	for (size_t i = 0; i < arr_len; i++)
		foo(array[i]);
}

#endif