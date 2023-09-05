#pragma once
#include<iostream>
#include<stdexcept>
#include<stack>
using namespace std;

template<typename T>
class MyQueue {
	stack<T> s1;
	stack<T> s2;

public:
	
	MyQueue() {

	}
	MyQueue<T>& enque(T val) {
		s1.push(val);
		return *this;
	}
	void dequeue() {

		if (s1.empty() && s2.empty()) {
			throw exception("Queue is empty ...");
		}
		int x;
		if (!s2.empty()) {
			x = s2.top();
			s2.pop();
			
		}
		else {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			x = s2.top();
			s2.pop();
			
		}
	}
	T peek() {  //--- Peek is almost the same as deque, if we do pop() the elemnts

		if (s1.empty() && s2.empty()) {
			throw exception("Queue is empty ...");
		}
		int x;
		if (!s2.empty()) {
			x = s2.top();
			return x;
		}
		else {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			x = s2.top();
			return x;
		}
	}

	bool empty() {
		return (s1.empty() && s2.empty());
	}
	int size() {
		return s1.size() + s2.size();
	}
};
