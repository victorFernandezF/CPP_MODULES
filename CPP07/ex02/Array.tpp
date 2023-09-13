/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:33:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/13 11:09:23 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

// DEFAULT CONTRUCTOR
template <typename T>
Array<T>::Array(): _array(NULL), _size(0){}

// CONSTRUCTOR WITH PARAMETER
template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n){
	for (size_t i = 0; i < n; i++){
		this->_array[i] = T();
	}
}

// COPY CONTRUCTOR
template <typename T>
Array<T>::Array (const Array<T> &copy){
	this->_size = copy.size();
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = copy._array[i];
}

// ASSIGNMENT OPERATOR '='
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

// SUBSCRIPT OPERATOR '[]'
template <typename T>
T &Array<T>::operator[](unsigned int index){
	if (_array == NULL || index >= this->_size)
		throw outOfBounds();
	return this->_array[index];
}

// DESTRUCTOR
template <typename T>
Array<T>::~Array(){
	delete [] this->_array;
}

// ----------- FUNCTIONS -----------

//PRINT ARRAY FUNCTION
template <typename T>
void Array<T>::print(std::string name){
	for (unsigned int i = 0; i < this->_size; i++)
		std::cout<<name<<"["<<i<<"] "<<this->_array[i]<<"\n";
}

 // SIZE FUNCTION
template <typename T>
T Array<T>::size () const{
	return this->_size;
}

// EXCEPTION
template <typename T>
class Array<T>::outOfBounds : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Index is out of bounds");
	}
};

#endif