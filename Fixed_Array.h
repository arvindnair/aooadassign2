// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS507_FIXED_ARRAY_H_
#define _CS507_FIXED_ARRAY_H_

#include <exception>          // for throwing fixed_size_exception exception.
#include <cstring>            // for size_t definition.
#include <cstdlib>            // for printing exception message.
#include "Array.h"            // for Array ADT inclusion.

// Arvind, your Array/Fixed_Array will not satisfy LSP.

// Dr.Hill, I have made the resize method in the Array class virtual, 
// which will then satisfy LSP by preserving its calling properties 
// through references.

/**
* @class Fixed_Array
*
* Implementation of a fixed size array, i.e., one that is not
* resizeable. It is derived from Array so it can inherit of 
* the Array class's methods.
*/
template <typename T, size_t N>
class Fixed_Array : public Array <T>
{
public:

	class fixed_size_exception: public std::exception
	{
	public:
		fixed_size_exception (void)
			:std::exception()
		{
			//print out the message that the fixed array is not resizable.
			std::cout<<"The fixed array is not resizable."<<std::endl;
		}

	};
	/// Default constructor.
	Fixed_Array (void);

	/**
	* Copy constructor.
	*
	* @param[in]      arr        Source array
	*/
	Fixed_Array (const Fixed_Array <T, N> & arr);

	/**
	* Initializing constructor. The source array can be of any size
	* as long as they are of the same type.
	*
	* @param[in]      arr        Source array
	*/
	template <size_t M>
	Fixed_Array (const Fixed_Array <T, M> & arr);

	/**
	* Initializing constructor. Fills the contents of the 
	* array with the specified \a fill value.
	*
	* @param[in]      fill       The file value.
	*/
	Fixed_Array (T fill);

	/// Destructor.
	~Fixed_Array (void);

	/**
	* Assignment operator
	*
	* @param[in]      rhs        Right-hand side of operator.
	*/
	const Fixed_Array & operator = (const Fixed_Array <T, N> & rhs);

	/**
	* Assignment operator
	*
	* @param[in]      rhs        Right-hand side of operator.
	*/
	template <size_t M>
	const Fixed_Array & operator = (const Fixed_Array <T, M> & rhs);

	/**
	* Redefining the resize function of Array class to take in a
	* parameter for increasing size but cannot do so as fixed array
	* cannot be resized. Hence, exception is thrown to indicate the same.
	*
	* @param[in]       new_size                   New size of the array.
	* @exception       fixed_size_exception       The fixed array cannot be resized.
	*/
	void resize (size_t new_size);

};



// include the inline files
#include "Fixed_Array.inl"

// include the source file since template class
#include "Fixed_Array.cpp"

#endif  // !defined _CS507_FIXED_ARRAY_H_
