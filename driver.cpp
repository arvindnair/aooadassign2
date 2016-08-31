#include <cstdio>
#include <iostream>
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Fixed_Array.h"
int main(){

	Array<char> a(10);
	a[0]='s';
	std::cout<<a[0]<<std::endl;
	Array<char> b;
	b=a;
	std::cout<<b[0]<<std::endl;
	b.resize(20);
	b.resize(20);
	std::cout<<b[0]<<std::endl;
	Stack <char> d;
	Stack <char> f;
	d.push('t');
	d.push('h');
	d.push('i');
	f=d;
	Stack <char> t(f);
	std::cout<<"F top: "<<f.top()<<std::endl;
	std::cout<<d.top()<<std::endl;
	d.pop();
	std::cout<<d.top()<<std::endl;
	d.pop();
	std::cout<<d.top()<<std::endl;
	d.pop();
	for (int i = 0; i < 50; i++)
	{
		d.push('f');
	}
	for (int i = 0; i < 49; i++)
	{
		d.pop();
	}
	try
	{
		d.pop();
		Queue <char> q;
		q.enqueue('A');
		std::cout<<q.front()<<std::endl;
		q.enqueue('R');
		std::cout<<q.front()<<std::endl;
		std::cout<<q.rear()<<std::endl;
		Queue <char> w(q);
		Queue <char> z;
		z=w;
		std::cout<<"z queue: "<<z.front()<<std::endl;
		std::cout<<z.rear()<<std::endl;
		q.dequeue();
		std::cout<<q.front()<<std::endl;
		q.dequeue();
		std::cout<<"w queue: "<<w.front()<<std::endl;
		std::cout<<w.rear()<<std::endl;
		Fixed_Array <char,10> r;
		r.fill('g');
		for (size_t i = 0; i < r.size(); i++)
		{
			std::cout<<r[i]<<std::endl;
		}
		std::cout<<"aaaa"<<std::endl;
		Fixed_Array <char,10> s('f');
		for (size_t i = 0; i < s.size(); i++)
		{
			std::cout<<s[i]<<std::endl;
		}
		std::cout<<"c1 Array:"<<std::endl;
		Fixed_Array <char,5> c1(s);
		for (size_t i = 0; i < c1.size(); i++)
		{
			std::cout<<i<<c1[i]<<std::endl;
		}
		r=s;
		for (size_t i = 0; i < r.size(); i++)
		{
			std::cout<<r[i]<<std::endl;
		}
		Fixed_Array <char,5> s1;
		s1=r;
		for (size_t i = 0; i < s1.size(); i++)
		{
			std::cout<<i<<s1[i]<<std::endl;
		}
		Queue <char> q1;
		q1.enqueue('B');
		q1.enqueue('A');
		q1.enqueue('S');
		std::cout<<q1.dequeue()<<std::endl;
		std::cout<<q1.dequeue()<<std::endl;
		std::cout<<q1.dequeue()<<std::endl;
		q1.enqueue('H');
		std::cout<<q1.front()<<q1.rear()<<std::endl;
		q1.clear();
		q1.enqueue('C');
		std::cout<<q1.front()<<q1.rear()<<std::endl;
		q1.dequeue();
		Fixed_Array <char,10> f1('g');
		for (size_t i = 0; i < f1.size(); i++)
		{
			std::cout<<i<<f1[i]<<std::endl;
		}
		std::cout<<std::endl;
		Fixed_Array <char,5> f2('G');
		f1=f2;
		for (size_t i = 0; i < f1.size(); i++)
		{
			std::cout<<i<<f1[i]<<std::endl;
		}
		std::cout<<std::endl;
		f1.set(0,'A');
		f1[1]='B';
		for (size_t i = 0; i < f1.size(); i++)
		{
			std::cout<<i<<f1[i]<<std::endl;
		}
		Queue <char> w1;
		w1.enqueue('W');
		w1.enqueue('H');
		w1.enqueue('E');
		w1.dequeue();
		w1.dequeue();
		w1.dequeue();
		w1.enqueue('o');
		w1.enqueue('y');
		Queue <char> w2;
		w2.enqueue('o');
		w2.enqueue('y');
		if(w1==w2)
		{
			std::cout<<"Success!!"<<std::endl;
		}
		else
		{
			std::cout<<"FAIL"<<std::endl;
		}
		Queue <char> w3;
		w3=w1;
		std::cout<<w3.front()<<std::endl;
		std::cout<<w3.rear()<<std::endl;
		Queue <char> w4;
		w3=w4;
		Stack <char> st1;
		st1.push('U');
		std::cout<<st1.top()<<std::endl;
		st1.push('Y');
		std::cout<<st1.top()<<std::endl;
		Stack <char> st2;
		st1=st2;
		st1.push('w');
		for (size_t i = 0; i < 50; i++)
		{
			st1.push('p');
		}
		for (size_t i = 0; i < 49; i++)
		{
			st1.pop();
		}
		std::cout<<st1.size()<<std::endl;
		std::cout<<st1.top()<<std::endl;
		st1.pop();
		std::cout<<st1.size()<<std::endl;
		std::cout<<st1.top()<<std::endl;
		st1.pop();
		std::cout<<st1.size()<<std::endl;
		Queue <char> qe;
		qe.enqueue('y');
		qe.enqueue('e');
		qe.enqueue('s');
		std::cout<<qe.size()<<std::endl;
		std::cout<<qe.front()<<std::endl;
		std::cout<<qe.rear()<<std::endl;
		std::cout<<"dequeueing: "<<qe.dequeue()<<std::endl;
		std::cout<<qe.size()<<std::endl;
		std::cout<<qe.front()<<std::endl;
		std::cout<<qe.rear()<<std::endl;
		std::cout<<"dequeueing: "<<qe.dequeue()<<std::endl;
		Queue <char> qe2(qe);
		std::cout<<qe.size()<<std::endl;
		std::cout<<qe.front()<<std::endl;
		std::cout<<qe.rear()<<std::endl;
		std::cout<<"dequeueing: "<<qe.dequeue()<<std::endl;
		std::cout<<qe.size()<<std::endl;
		Queue <char> qe1(qe);
		std::cout<<qe1.size()<<std::endl;
		std::cout<<qe2.size()<<std::endl;
		std::cout<<qe2.front()<<std::endl;
		std::cout<<qe2.rear()<<std::endl;

		Queue <char> y1;
		y1.enqueue('N');
		y1.enqueue('A');
		y1.enqueue('H');
		Queue <char> y2;
		y2.enqueue('N');
		y2.enqueue('A');
		y2.enqueue('Y');
		y2=y1;
		std::cout<<"dequeueing: "<<y2.dequeue()<<std::endl;
		std::cout<<"dequeueing: "<<y2.dequeue()<<std::endl;
		std::cout<<"dequeueing: "<<y2.dequeue()<<std::endl;

		y2=y1;
		std::cout<<"dequeueing: "<<y2.dequeue()<<std::endl;
		std::cout<<"dequeueing: "<<y2.dequeue()<<std::endl;
		std::cout<<"dequeueing: "<<y2.dequeue()<<std::endl;
		y1=y2;
		
		Stack <char> e1;
		for (size_t i = 0; i < 50; i++)
		{
			e1.push('p');
		}
		for (size_t i = 0; i < 50; i++)
		{
			e1.pop();
		}
		std::cout<<e1.size()<<std::endl;
		Stack <char> e2(e1);
		std::cout<<e2.size()<<std::endl;
		e2.push('Y');
		std::cout<<e2.top()<<std::endl;

		Stack <char> e3;
		e3.push('g');
		e1.push('h');
		e3=e1;
		std::cout<<e3.top()<<std::endl;
		e3.push('u');
		std::cout<<e3.top()<<std::endl;
		std::cout<<e3.size()<<std::endl;

		Queue <char> test;
		for (size_t i = 0; i < 9; i++)
		{
			std::cout<<test.size()<<std::endl;
			test.enqueue('T');
		}
		std::cout<<"aaaaa"<<test.size()<<std::endl;
		test.dequeue();
		std::cout<<test.size()<<std::endl;
		test.dequeue();
		std::cout<<test.size()<<std::endl;
		test.enqueue('Y');
		std::cout<<test.size()<<std::endl;
		for (size_t i = 0; i < 7; i++)
		{
			test.dequeue();
			std::cout<<test.size()<<std::endl;
		}
		std::cout<<test.front()<<std::endl;
		std::cout<<test.rear()<<std::endl;
		test.dequeue();
		std::cout<<test.size()<<std::endl;
		
		Queue <char> test1;
		for (size_t i = 0; i < 10; i++)
		{
			test1.enqueue('W');
		}
		std::cout<<"After Enqueue of W: "<<test1.size()<<std::endl;
		test1.dequeue();
		test1.dequeue();
		test1.enqueue('Y');
		Queue <char> tc4(test1);
		std::cout<<"After Enqueue of Y: "<<tc4.size()<<std::endl;
		std::cout<<"Dequeue Not Y: "<<tc4.dequeue()<<std::endl;
		std::cout<<"After Dequeue Not Y: "<<tc4.size()<<std::endl;
		std::cout<<"Should be Y: "<<tc4.rear()<<std::endl;
		Queue <char> ec1;
		ec1=test1;
		std::cout<<"After Enqueue of Y: "<<ec1.size()<<std::endl;
		std::cout<<"Dequeue Not Y: "<<ec1.dequeue()<<std::endl;
		std::cout<<"After Dequeue Not Y: "<<ec1.size()<<std::endl;
		std::cout<<"Should be Y: "<<ec1.rear()<<std::endl;

		std::cout<<"After Enqueue of Y: "<<test1.size()<<std::endl;
		std::cout<<"Dequeue Not Y: "<<test1.dequeue()<<std::endl;
		std::cout<<"After Dequeue Not Y: "<<test1.size()<<std::endl;
		std::cout<<"Should be Y: "<<test1.rear()<<std::endl;
		for (size_t i = 0; i < 10; i++)
		{
			test1.enqueue('R');
		}
		std::cout<<"After Enqueue of R: "<<test1.size()<<std::endl;
		Queue <char> tc3(test1);
		std::cout<<"Final size of tc 3: "<<tc3.size()<<std::endl;
		for (size_t i = 0; i < 7; i++)
		{
			tc3.dequeue();
		}
		std::cout<<"Should be Y: "<<tc3.front()<<std::endl;
		std::cout<<"Should be R: "<<tc3.rear()<<std::endl;
		for (size_t i = 0; i < 7; i++)
		{
			test1.dequeue();
		}
		std::cout<<"Final size of test 1: "<<test1.size()<<std::endl;
		std::cout<<"Should be Y: "<<test1.front()<<std::endl;
		std::cout<<"Should be R: "<<test1.rear()<<std::endl;

		Queue <char> test2;
		for (size_t i = 0; i < 10; i++)
		{
			test2.enqueue('R');
		}
		test2.dequeue();
		test2.enqueue('L');
		
		test1=test2;
		std::cout<<"Should be R: "<<test1.front()<<std::endl;
		std::cout<<"Should be L: "<<test1.rear()<<std::endl;

		test1=test2;

		for (size_t i = 0; i < 10; i++)
		{
			test1.enqueue('Z');
		}

		std::cout<<"Should be R: "<<test1.front()<<std::endl;
		std::cout<<"Should be Z: "<<test1.rear()<<std::endl;

		test1.dequeue();
		test1.dequeue();
		test1.enqueue('K');
		test1.enqueue('K');

		std::cout<<"Should be R: "<<test1.front()<<std::endl;
		std::cout<<"Should be K: "<<test1.rear()<<std::endl;

		test1.enqueue('T');

		std::cout<<"Should be R: "<<test1.front()<<std::endl;
		std::cout<<"Should be T: "<<test1.rear()<<std::endl;
		std::cout<<"size of test1: "<<test1.size()<<std::endl;

		Queue <char> test3;
		test1=test3;
		test1.enqueue('A');
		std::cout<<"Should be A: "<<test1.front()<<std::endl;
		std::cout<<"Should be A: "<<test1.rear()<<std::endl;
		std::cout<<"size of test1: "<<test1.size()<<std::endl;



		Queue <char> tc1;
		Queue <char> tc2(tc1);
		std::cout<<tc2.dequeue()<<std::endl;

	}
	catch(...)
	{

	}
	try
	{
		Fixed_Array <char,10> l1('l');
		Fixed_Array <char,10> l2('l');
		l1=l2;
		Fixed_Array <char,5> f5;
		Array<char> *b1=&f5;
		b1->resize(11);
	}
	catch(...)
	{

	}
	return 0;
}