// -*- C++ -*-
// $Id: Queue.h 380 2015-02-08 07:30:55Z arvnair $

//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include <exception>          // for throwing empty_exception exception.
#include <cstring>            // for size_t definition.
#include <cstdlib>            // for printing exception message.
#include "Array.h"            // for Array ADT inclusion.

#define DEFAULT_SIZE 10       // specify a buffer size to avoid resizing every 
                              // time an enqueue is made. 

/**
* @class Queue
*
* Basic queue for abitrary elements.
*/
template <typename T>
class Queue
{
public:
	/// Type definition of the type.
	typedef T type;

	/**
	* @class empty_exception
	*
	* Exception thrown to indicate the queue is empty.
	*/
	class empty_exception : public std::exception
	{
	public:
		/// Default constructor.
		empty_exception (void)
			: std::exception () 
		{
			//print out the message queue is empty.
			std::cout<<"The queue is empty"<<std::endl; 
		}
	};

	/// Default constructor.
	Queue (void);

	/// Copy constructor.
	Queue (const Queue & q);

	/// Destructor.
	~Queue (void);

	/**
	* Assignment operator
	*
	* @param[in]      rhs           Right-hand side of operator
	* @return         Reference to self
	*/
	const Queue & operator = (const Queue & rhs);

	/**
	* Enqueue a new \a element onto the queue. The element is inserted
	* after all the other elements in the list.
	*
	* @param[in]      element       Element to add to the queue
	*/
	void enqueue (T element);
	
	/**
	* Remove the first-most element from the queue.
	*
	* @return         Element removed from the front of the queue.
	* @exception      empty_exception    The queue is empty
	*/    
	T dequeue (void);

	/**
	* Get the first-most element on the queue. If there are no element 
	* on the queue, then the queue_is_empty exception is thrown.
	*
	* @return         Element on front of the queue.
	* @exception      empty_exception    The queue is empty
	*/
	T front (void) const;

	/**
	* Get the behind-most element on the queue. If there are no element 
	* on the queue, then the queue_is_empty exception is thrown.
	*
	* @return         Element on back of the queue.
	* @exception      empty_exception    The queue is empty
	*/
	T rear (void) const;

	/**
	* Test if the queue is empty
	*
	* @retval         true          The queue is empty
	* @retval         false         The queue is not empty
	*/
	bool is_empty (void) const;

	/**
	* Number of elements on the queue.
	*
	* @return         Size of the queue.
	*/
	size_t size (void) const;

	/// Remove all elements from the queue.
	void clear (void);

	/**
	* Test the queue for equality.
	*
	* @param[in]       rhs                  Right hand side of equal to sign
	* @retval          true                 Left side is equal to right side
	* @retval          false                Left side is not equal to right side
	*/

	bool operator == (const Queue<T> & rhs) const;

	/**
	* Test the queue for inequality.
	*
	* @param[in]       rhs                  Right-hand size of not equal to sign
	* @retval          true                 Left side is not equal to right side
	* @retval          false                Left size is equal to right side
	*/

	bool operator != (const Queue<T> & rhs) const;

private:
	// add member variable here

	//Current maximum length of the queue.
	size_t queue_maxlen_;

	//Points to the first-most element of the queue.
	size_t front_;

	//Points to the behind-most element of the queue.
	size_t rear_;

	//Using Array as Wrapper (Facade) for queue ADT.
	Array <T> queue_data_;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _CS507_QUEUE_H_
