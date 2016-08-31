// -*- C++ -*-
// $Id: Queue.h 380 2015-02-08 07:30:55Z arvnair $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
	size_t Queue <T>::size (void) const
{
	if (is_empty())
	{
		// if the queue is empty then return the size as zero, as the 
		// number of elements in queue is zero.
		return 0;
	}
	else
	{
		// if front is lesser than rear then rear is ahead of front 
		// and there are no elements behind front, so return difference 
		// of rear with front adding one.
		if (front_<=rear_)
		{
			return (rear_-front_+1);
		}
		// if front is lesser than rear then count the elements from 
		// front to queue maxlength(adding one) and add that to rear.
		else
		{
			return ((queue_maxlen_-front_+1)+(rear_));
		}
	}
}

//
// front
//
template <typename T>
inline
	T Queue <T>::front (void) const
{
	// if queue is not empty, return the first-most element in 
	// the queue currently.
	if (!(is_empty()))
	{
		return queue_data_[front_-1];
	}
	// else throw exception queue is empty.
	else
	{
		throw empty_exception();
	}
}

//
// rear
//
template <typename T>
inline
	T Queue <T>::rear (void) const
{
	// if queue is not empty return the behind most element in 
	// the queue currently.
	if (!(is_empty()))
	{
		return queue_data_[rear_-1];
	}
	// else throw exception queue is empty.
	else
	{
		throw empty_exception();
	}
}

//
// is_empty
//
template <typename T>
inline
	bool Queue <T>::is_empty (void) const
{
	// if front is zero or if front is greater than rear then 
	// the queue is empty.
	if(front_==0)
	{
		return true;
	}
	// else queue has atleast one element left.
	else
	{
		return false;
	}
}
