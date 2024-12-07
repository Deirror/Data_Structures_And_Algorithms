#pragma once
#include <utility>

using namespace std;

template <typename T>
class graph_base {
public:
	virtual void add(const pair<T, T>& edge) = 0;

	virtual void remove(const T& vertex) = 0;

	virtual bool contains(const T& vertex) = 0;
	virtual size_t path(const T& startVertex, const T& endVertex) = 0;
};
