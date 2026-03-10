#pragma once

#include <vector>
#include "Scalars.hpp"

// Meant to be interfaces the same way a glsl array is
template<typename T>
class VariableArray
{
private:
	std::vector<T> _backingVector;

public:
	VariableArray() = default;

	void push(const T& element);
	// Mutable access (set or get)
	T& operator[](size_t index);
	// Const access (get only)
	const T& operator[](size_t index) const;
	uint length() const;
};

