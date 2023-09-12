/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:33:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/12 18:58:44 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array(): _array(NULL), _size(0){
	//std::cout<<"Contructor called\n";
}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n){
	for (size_t i = 0; i < n; i++){
		this->_array[i] = T();
	}
}

template <typename T>
T Array<T>::size () const{
	return this->_size;
}

template <typename T>
Array<T>::Array (const Array<T> &copy){
	this->_size = copy.size();
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = copy._array[i];
}

template <typename T>
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

template <typename T>
T &Array<T>::operator[](unsigned int index){
	if (_array == NULL || index >= this->_size)
		throw outOfBounds();
	return this->_array[index];
}

template <typename T>
Array<T>::~Array(){
	//std::cout<<"Destructor called\n";	
	delete [] this->_array;
}

template <typename T>
void Array<T>::print(){
	for (unsigned int i = 0; i < this->_size; i++)
		std::cout<<"array["<<i<<"] "<<this->_array[i]<<"\n";
}

template <typename T>
void Array<T>::edit(){
	for (int i = 0; i < this->_size; i++)
		this->_array[i] = this->_array[i] + 1;
}

template <typename T>
class Array<T>::outOfBounds : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Index is out of bounds");
	}
};

#endif