/*
Создайте шаблонный класс обычной очереди для работы с
с целыми значениями. Требуется создать реализации для
типичных операций над элементами:
■ IsEmpty - проверка очереди на пустоту;
■ IsFull - проверка очереди на заполнение;
■ Enqueue - добавление элемента в очередь;
■ Dequeue - удаление элемента из очереди;
■ Show - отображение всех элементов очереди на экран.
*/

#pragma once
#include <iostream>
using namespace std;

template <class Q>

class Queue
{
	Q* _queue;
	int _capacity;
	int _size;
public:
	Queue();
	Queue(int);
	~Queue();
	bool IsEmpty();
	bool IsFull();
	void Enqueue(Q num);
	Q Dequeue();
	void show();
};

template<class Q>
inline Queue<Q>::Queue() : Queue(1) {}

template<class Q>
inline Queue<Q>::Queue(int capacity) : _size(0)
{
	_capacity = capacity;
	_queue = new Q[_capacity];
}

template<class Q>
inline Queue<Q>::~Queue()
{
	delete[] _queue;
}

template<class Q>
inline bool Queue<Q>::IsEmpty()
{
	return _size == 0;
}

template<class Q>
inline bool Queue<Q>::IsFull()
{
	return _size == _capacity;
}

template<class Q>
inline void Queue<Q>::Enqueue(Q num)
{
	if (!IsFull())
	{
		_queue[_size++] = num;
	}
}

template<class Q>
inline Q Queue<Q>::Dequeue()
{
	if (!IsEmpty())
	{
		int temp = _queue[0];
		for (int i = 1; i < _size - 1; i++)
		{
			_queue[i] = _queue[i + 1];
		}
		_size--;
		return temp;
	}
	else
		return -1;
	return Q();
}

template<class Q>
inline void Queue<Q>::show()
{
	cout << "\n-------------------------------------\n";
	for (int i = 0; i < _size; i++) {
		cout << _queue[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}
