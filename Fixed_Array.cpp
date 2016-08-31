// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//
// initializing as per array of size N using array's default constructor.
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
	: Array<T>::Array(N)
{}

//
// Fixed_Array
//
// initializing as per array using copy constructor of array class.
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
	: Array<T>::Array(arr)
{}

//
// Fixed_Array
//
// initializing as per array of size N using array's default constructor.
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
	: Array<T>::Array(N)
{
	// if M is lesser than N then copy the elements of N fixed array 
	// until M same as that of M fixed array.
	if (M<N)
	{
		for (size_t i = 0; i < M; i++)
		{
			this->operator[](i)=arr[i];
		}
	}
	// else if M is greater than or equal to N then copy the elements of N 
	// fixed array until N same as that of M fixed array.
	else
	{
		for (size_t i = 0; i < N; i++)
		{
			this->operator[](i)=arr[i];
		}
	}

}

//
// Fixed_Array
//
// initializing as per array of size N and fill using array class constructor.
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
	: Array<T>::Array(N,fill)
{}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
	// Destructor not needed as Array class handles destruction.
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	// copy all the elements of the lhs array equal to the rhs array 
	// elements respectively.
	for (size_t i = 0; i < N; i++)
	{
		this->operator[](i)=rhs[i];
	}
	return *this;
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	// if M is lesser than N then copy the elements of N fixed array(lhs) 
	// until M, same as that of M fixed array(rhs).
	if (M<N)
	{
		for (size_t i = 0; i < M; i++)
		{
			this->operator[](i)=rhs[i];
		}
	}
	// else if M is greater than or equal to N then copy the elements of N 
	// fixed array(lhs) until N same as that of M fixed array(rhs).
	else
	{
		for (size_t i = 0; i < N; i++)
		{
			this->operator[](i)=rhs[i];
		}
	}
	return *this;
}

//
// resize
//
template <typename T, size_t N>
void Fixed_Array<T, N>::resize(size_t new_size)
{
	// fixed size exception is thrown to indicate that fixed array 
	// cannot be resized.
	throw fixed_size_exception();
}