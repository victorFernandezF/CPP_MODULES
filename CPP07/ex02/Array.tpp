/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:33:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/12 13:02:00 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <class T>
Array<T>::Array(): _array(nullptr), _size(0){
	std::cout<<"Contructor called\n";
}

template <class T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n){
	for (size_t i = 0; i < n; i++){
		this->_array[i] = T();
	}
}

template <class T>
T Array<T>::size () const{
	return this->_size;
}

template <class T>
Array<T>::Array (const Array<T> &copy){
	this->_size = copy.size();
	this->_array = new T[this->_size];
	for (int i = 0; i < this->_size; i++)
		this->_array[i] = copy._array[i];
}

template <class T>
Array<T> &Array<T>::operator=(const Array &copy){
	if (this->_array != NULL)
		delete [] this->_array;
	if (copy.size() != 0){
		this->_size = copy.size();
		this->_array = new T[copy.size()];
		for (int i = 0; i < copy.size(); i++)
			this->_array[i] = copy._array[i];
	}
	return (*this);
}



template <class T>
T &Array<T>::operator[](unsigned int index){
	if (!this->_array[index])
		throw std::exception();
	return this->_array[index];
}


template <class T>
Array<T>::~Array(){
	std::cout<<"Destructor called\n";	
	delete [] this->_array;
}

template <class T>
void Array<T>::print(){
	for (int i = 0; i < this->_size; i++)
		std::cout<<"array["<<i<<"] "<<this->_array[i]<<"\n";
}

template <class T>
void Array<T>::edit(){
	for (int i = 0; i < this->_size; i++)
		this->_array[i] = this->_array[i] + i;
}

#endif