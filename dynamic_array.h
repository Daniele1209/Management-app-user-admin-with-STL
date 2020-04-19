#pragma once
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include "turret.h"
#define _CRT_SECURE_NO_WARNINGS

template <typename T>
class Dynamic_vector
{
private:
	int capacity, size;
	T* elems;

public:
	Dynamic_vector(int cap = 10);
	~Dynamic_vector();
	int get_size() const;
	void add(T elem);
	T& operator[](int position);
	Dynamic_vector(const Dynamic_vector& vector);
	int find_element(std::string str);
	int delete_item(int index);
	T& find(std::string str);
	T& get(int index);

private:
	void resize();

public:
	class iterator
	{
	private:
		T* ptr;

	public:
		iterator(T* pointer) : ptr{ pointer } {}
	};

};

template<typename T>
inline Dynamic_vector<T>::Dynamic_vector(int cap) : capacity{ cap }, size{ 0 }
{
	this->elems = new T[this->capacity];
}

template<typename T>
inline Dynamic_vector<T>::~Dynamic_vector()
{
	delete[] this->elems;
}

template<typename T>
inline int Dynamic_vector<T>::get_size() const
{
	return this->size;
}

template<typename T>
inline int Dynamic_vector<T>::find_element(std::string location) {
	for (int i = 0; i < get_size(); i++)
		if (elems[i].get_location() == location)
			return i;
	return -1;
}

template<typename T>
inline void Dynamic_vector<T>::add(T elem)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size++] = elem;
}

template<typename T>
inline int Dynamic_vector<T>::delete_item(int index)
{	
	for (int i = index + 1; i < this->size; i++)
		this->elems[i - 1] = this->elems[i];
	this->size--;
	return 0;
}

template<typename T>
inline T& Dynamic_vector<T>::operator[](int position)
{
	return this->elems[position];
}

template<typename T>
inline T& Dynamic_vector<T>::get(int position)
{
	return this->elems[position];
}

template<typename T>
inline T& Dynamic_vector<T>::find(std::string str)
{
	for (int i = 0; i < this->get_size(); ++i)
		if (elems[i].get_location() == str)
			return elems[i];
	throw 404;
}

template<typename T>
inline Dynamic_vector<T>::Dynamic_vector(const Dynamic_vector& vector)
{
	this->capacity = vector.capacity;
	this->size = vector.size;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = vector.elems[i];
}

template<typename T>
inline void Dynamic_vector<T>::resize()
{
	this->capacity *= 2;
	T* aux = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		aux[i] = this->elems[i];
	delete[] this->elems;
	this->elems = aux;
}
