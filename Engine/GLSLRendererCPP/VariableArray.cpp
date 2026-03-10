#include "../Tools/Macros.hpp"
#include "VariableArray.hpp"

template<typename T>
TRICIBLE_FORCEINLINE uint VariableArray<T>::length() const {
	return _backingVector.size();
}

template<typename T>
void VariableArray<T>::push(const T& element)
{
	_backingVector.push_back(element);
}

// Mutable access (set or get)
template<typename T>
T& VariableArray<T>::operator[](size_t index) {
	return _backingVector[index];
}

// Const access (get only)
template<typename T>
const T& VariableArray<T>::operator[](size_t index) const {
	return _backingVector[index];
}