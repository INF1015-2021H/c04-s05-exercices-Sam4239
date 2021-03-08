///
/// Exemple des slides sur la copie d'objet.
///

#pragma once


#include <cstddef>
#include <cstdint>

#include <memory>
#include <utility>
#include <iostream>
#include <span>

#include <cppitertools/itertools.hpp>

using namespace std;
using namespace iter;


template <typename T>
class Vector {
	template <typename U>
	friend class Vector;

public:
	Vector() = default; // Petit truc pour dire au compilateur de générer pour nous le ctor par défaut.
	Vector(const Vector& other); // Par copie
	template <typename U>
	Vector(const Vector<U>& other); // Par copie
	Vector(Vector&& other); // Par déplacement (ou par move)
	Vector(int size, T value = {});
	Vector(span<const T> values);
	~Vector();

	Vector& operator=(const Vector& other);
	template <typename U>
	Vector& operator=(const Vector<U>& other);
	Vector& operator=(Vector&& other);

	T* getData();
	const T* getData() const;
	int getSize() const;

	void resize(int size);
	bool hasSameSize(const Vector& other) const;

	T& operator[](int index);
	const T& operator[](int index) const;

	Vector operator-() const;
	Vector operator+() const;
	Vector operator+(const Vector& rhs) const;
	Vector operator-(const Vector& rhs) const;

	Vector& operator+=(const Vector& rhs);
	Vector& operator-=(const Vector& rhs);

	template <typename>
	friend ostream& operator<<(ostream& lhs, const Vector& rhs);

private:
	unique_ptr<T[]> values_;
	int size_ = 0;
};




