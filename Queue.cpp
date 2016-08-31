// $Id: Queue.h 380 2015-02-08 07:30:55Z arvnair $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Queue
//
// setting all the data members to zero initially.
template <typename T>
Queue <T>::Queue (void)
	: queue_maxlen_(0),
	front_(0),
	rear_(0)
{}

//
// Queue
//
// copying the data members of queue into this queue.
template <typename T>
Queue <T>::Queue (const Queue & queue)
	: queue_maxlen_(queue.queue_maxlen_),
	front_(queue.front_),
	rear_(queue.rear_)
{
	// resizing the current queue to the size of the passed queue.
	queue_data_.resize(queue.queue_maxlen_);
	// if passed queue is not empty then copy its contents to the current queue,
	// as per the below conditions.
	if (!(queue.is_empty()))
	{
		// if front is lesser than rear then copy the contents from front to rear,
		// into the current queue.
		if (queue.front_<=queue.rear_)
		{
			for (size_t i = queue.front_-1; i < queue.rear_; i++)
			{
				queue_data_[i]=queue.queue_data_[i];
			}
		}
		// if front is greater than rear then first copy the contents from front to 
		// queue maxlength and then from 0 to rear into the current queue.
		else
		{
			for (size_t i = queue.front_-1; i < queue.queue_maxlen_; i++)
			{
				queue_data_[i]=queue.queue_data_[i];
			}
			for (size_t i = 0; i < queue.rear_; i++)
			{
				queue_data_[i]=queue.queue_data_[i];
			}
		}
	}
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
	// clearing the queue contents. Array class automatically takes care
	// of destruction.
	clear();
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
	// Arvind, your queue implementation is good, but it is also ineffecient.
	// The biggest concerns is your are not using the space in the array
	// efficiently after you enqueue/dequeue the data. There seems to be
	// wasted space at the front of the array after dequeue operations.
	// Please come up with a better design that only requires a resize()
	// whenever there is no space left in the entire array (including the
	// front of the array).

	// Dr.Hill, I have made the queue a circular queue. So, if there is space at
	// the front of the queue after the queue fills upto queue's maxlength then,
	// the element new elements are inserted at the front of the queue, and continue
	// till the entire queue is full i.e., there is no need for resize if there is 
	// space in front of the queue. Now, I am utilizing the space in the array 
	// efficiently after enqueue/dequeue of data. So, there is no wasted space at 
	// the front of the queue after dequeue operations. This is a better design that 
	// only requires a resize() whenever there is no space left in the entire array 
	// (including the front of the array).

	// if the front is zero the queue is empty.
	if (front_==0)
	{
		// check if the maxlength of the queue is lesser than the queue's size,
		// if it is lesser then no need to resize.
		if (queue_maxlen_<queue_data_.size())
		{
			queue_maxlen_=queue_data_.size();
		}
		// else if the maxlength of the queue is greater than the queue's size,
		// if it is lesser then resize is needed.
		else
		{
			queue_data_.resize(queue_maxlen_+DEFAULT_SIZE);
			queue_maxlen_=queue_maxlen_+DEFAULT_SIZE;
		}
		// incrementing the front accordingly.
		front_++;
	}
	// if front is not zero, queue is not empty and hence check 
	// conditions below.
	else
	{
		// if rear is greater than or equal to queue maxlength then check 
		// the conditions below.
		if (rear_>=queue_maxlen_)
		{
			// if front is greater than one i.e., there is space before the queue 
			// to store elements, hence there is no need to resize. So, set rear to zero.
			if (front_>1)
			{
				rear_=0;
			}
			// if front is 1 then there is no space before the queue to store elements, so 
			// check if resize is necessary.
			else
			{
				// if queue maxlength is lesser than queue_data_'s size no need to use 
				// resize, set queue maxlength equal to queue_data_ size.
				if (queue_maxlen_<queue_data_.size())
				{
					queue_maxlen_=queue_data_.size();
				}
				// else if queue maxlength is not lesser than queue_data_'s size 
				// resize is necessary, hence perform resize to size of maxlength 
				// plus default size and set maxlength accordingly.
				else
				{
					queue_data_.resize(queue_maxlen_+DEFAULT_SIZE);
					queue_maxlen_=queue_maxlen_+DEFAULT_SIZE;
				}
			}
		}
		// if rear is lesser than maxlength then check the 
		// below conditions.
		else
		{
			// if rear plus 1 will point to front means that the queue is 
			// full in condition where rear is lesser than front.So the queue
			// must be made larger to fill the new value.
			if ((rear_+1)==front_)
			{
				// making a temporary array.
				Array<T> temp;
				// if queue maxlength is lesser than queue_data_ size then make 
				// the temp array as large as queue_data_.
				if (queue_maxlen_<queue_data_.size())
				{
					temp.resize(queue_data_.size());
				}
				// if queue maxlength is not lesser than queue_data_ size then make
				// the temp array as large as queue_data_'s size plus default size.
				else
				{
					temp.resize(queue_maxlen_+DEFAULT_SIZE);
				}
				// now reorder from front to rear by copying from front to queue 
				// maxlength the elements into temp array.
				for (size_t i = 0,j=front_-1; j < queue_maxlen_; i++,j++)
				{
					temp[i]=queue_data_[j];
				}
				// then copy from 0 to rear then rest of the elements starting from 
				// previous filled position of temp array.
				for (size_t i = queue_maxlen_-front_+1,j=0; j < rear_; i++,j++)
				{
					temp[i]=queue_data_[j];
				}
				// setting rear to the end after reordering.
				rear_=(queue_maxlen_-front_+1)+(rear_);
				// now resize queue data to temp size.
				queue_data_.resize(temp.size());
				// make maxlength equal to temp size.
				queue_maxlen_=temp.size();
				// finally copy temp contents into queue data.
				queue_data_=temp;
				// and set front to 1 after reordering.
				front_=1;
			}
		}
	}
	// increment rear after the any of the above operations are 
	// done as per conditions.
	rear_++;
	// store the element into the appropriate position.
	queue_data_[rear_-1]=element;
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
	// Arvind, your queue implementation is good, but it is also ineffecient.
	// The biggest concerns is your are not using the space in the array
	// efficiently after you enqueue/dequeue the data. There seems to be
	// wasted space at the front of the array after dequeue operations.
	// Please come up with a better design that only requires a resize()
	// whenever there is no space left in the entire array (including the
	// front of the array).

	// Dr.Hill, I have made the queue a circular queue. So, if there is space at
	// the front of the queue after the queue fills upto queue's maxlength then,
	// the element new elements are inserted at the front of the queue, and continue
	// till the entire queue is full i.e., there is no need for resize if there is 
	// space in front of the queue. Now, I am utilizing the space in the array 
	// efficiently after enqueue/dequeue of data. So, there is no wasted space at 
	// the front of the queue after dequeue operations. This is a better design that 
	// only requires a resize() whenever there is no space left in the entire array 
	// (including the front of the array).

	//if queue is not empty remove the frontmost element of the queue 
	// and increment front.
	if (!(is_empty()))
	{
		// store front element in a temporary variable.
		T var=queue_data_[front_-1];
		// if front and rear are equal then this is the last element which is 
		// being dequeued. So, clear the queue.
		if (front_==rear_)
		{
			clear();
		}
		// if front and rear are not equal then there are other conditions 
		// to be considered.
		else
		{
			// if front is greater than rear and front is equal to maxlen of 
			// queue which means there are elements at the start of the queue 
			// in respective order. So set the front to 1 i.e., to point to 
			// the element at first position.
			if ((front_>rear_) && (front_==queue_maxlen_))
			{
				front_=1;
			}
			// in other cases just increment front.
			else
			{
				front_++;
			}
		}
		// now return the value at front position.
		return var;
	}
	// else throw queue is empty exception.
	else
	{
		throw empty_exception();
	}

}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	if (*this!=rhs)
	{
		// if array's size is lesser than the rhs queue max length then resize 
		// the queue data array, else resize is not necessary.
		if (queue_data_.size()<rhs.queue_maxlen_)
		{
			queue_data_.resize(rhs.queue_maxlen_);
		}
		// setting the data members of lhs queue equal to rhs queue members.
		front_=rhs.front_;
		rear_=rhs.rear_;
		queue_maxlen_=rhs.queue_maxlen_;
		// if rhs queue is not empty then copy the contents of rhs into lhs queue.
		if (!(rhs.is_empty()))
		{
			// if front is lesser than rear then copy the contents from front to rear,
			// into the current queue.
			if (front_<=rear_)
			{
				for (size_t i = rhs.front_-1; i < rhs.rear_; i++)
				{
					queue_data_[i]=rhs.queue_data_[i];
				}
			}
			// else if front is greater than rear then first copy the contents from front 
			// to queue maxlength and then from 0 to rear into the current queue.
			else
			{
				for (size_t i = rhs.front_-1; i < rhs.queue_maxlen_; i++)
				{
					queue_data_[i]=rhs.queue_data_[i];
				}
				for (size_t i = 0; i < rhs.rear_; i++)
				{
					queue_data_[i]=rhs.queue_data_[i];
				}
			}
		}
	}
	return *this;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
	// setting the front and rear to zero.
	front_=0;
	rear_=0;
}

//
// operator ==
//
template <typename T>
bool Queue<T>::operator == (const Queue<T> & rhs) const
{
	// if both the queues are empty then both the queues are same.
	if ((this->is_empty()) && (rhs.is_empty()))
	{
		return true;
	}
	else
	{
		// if both the queues are not empty and the number of elements
		// in both the queues are the same then proceed.
		if ((!(this->is_empty())) && (!(rhs.is_empty())) && (front_==rhs.front_) && (rear_==rhs.rear_))
		{
			// if front is lesser than rear then compare the contents 
			// from front to rear, of the lhs and rhs queues.
			if (front_<=rear_)
			{
				// check each element of both the queues if they are 
				// in correct sequence.
				for (size_t i = front_-1; i < rear_; i++)
				{
					//if any of the elements are not equal then the queue is not equal.
					if (queue_data_[i]!=rhs.queue_data_[i])
					{
						return false;
					}
				}
				// if all elements are equal in correct sequence then the 
				// queues are equal.
				return true;
			}
			// else if front is greater than rear then first compare the contents 
			// from front to queue maxlength and then from 0 to rear of the lhs 
			// and rhs queues.
			else
			{
				for (size_t i = front_-1; i < queue_maxlen_; i++)
				{
					// if any of the elements are not equal then the queue is not equal.
					if (queue_data_[i]!=rhs.queue_data_[i])
					{
						return false;
					}
				}
				for (size_t i = 0; i < rear_; i++)
				{
					// if any of the elements are not equal then the queue is not equal.
					if (queue_data_[i]!=rhs.queue_data_[i])
					{
						return false;
					}
				}
				// if all elements are equal in correct sequence then the queues 
				// are equal.
				return true;
			}
		}
		//if any one of the queues are empty or the number of elements in both the queues 
		//are the different, the queues are not same.
		return false;
	}
}

//
// operator !=
//
template <typename T>
bool Queue<T>::operator != (const Queue<T> & rhs) const
{
	// returning the opposite of == operation.
	return !(*this==rhs);
}