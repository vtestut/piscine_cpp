/******************************************************************************/
/*							       PUBLIC									  */
/******************************************************************************/

template <typename T>
unsigned int Array<T>::size() const 
{
	return _size;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

template <typename T>
Array<T>::Array() : _elems(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) 
{
	_elems = new T[n];
	for (unsigned int i = 0; i < _size; ++i)
		_elems[i] = T();
}

template <typename T>
Array<T>::Array(const Array& obj) : _size(obj._size) 
{
	_elems = new T[_size];
	for (size_t i = 0; i < obj.size(); ++i)
		_elems[i] = obj[i];
}

template <typename T>
Array<T>::~Array() 
{
	delete[] _elems;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

template <typename T>
Array<T>& Array<T>::operator=(const Array& obj) 
{
	if (this != &obj)
	{
		delete[] _elems;
		_size = obj._size;
		_elems = new T[_size];
		for (size_t i = 0; i < obj.size(); ++i)
			_elems[i] = obj[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= _size)
		throw std::out_of_range("Array index is out of bounds");
	return _elems[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
	if (i >= _size)
		throw std::out_of_range("Array index is out of bounds");
	return _elems[i];
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& obj) {
	os << '{';
	for (size_t i = 0; i < obj.size(); ++i) {
		if (i != 0)
			os << ", ";
		os << obj[i];
	}
	os << '}';
	return os;
}
