template <typename T>
Array<T>::Array() : _elems(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    _elems = new T[n];
    for (unsigned int i = 0; i < _size; ++i) {
        _elems[i] = T();
    }
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size) {
    _elems = new T[_size];
    for (size_t i = 0; i < other.size(); ++i) {
        _elems[i] = other[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _elems;
        _size = other._size;
        _elems = new T[_size];
        for (size_t i = 0; i < other.size(); ++i) {
            _elems[i] = other[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _elems;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
    if (i >= _size) {
        throw std::out_of_range("Array index out of bounds");
    }
    return _elems[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
    if (i >= _size) {
        throw std::out_of_range("Array index out of bounds");
    }
    return _elems[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
    os << '{';
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i != 0) {
            os << ", ";
        }
        os << arr[i];
    }
    os << '}';
    return os;
}
