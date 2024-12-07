#pragma once
#include <unordered_set>
#include <unordered_map>

#include <iostream>

#include <vector>
#include <queue>

#include "graph_base.hpp"

template <typename T>
class graph : public graph_base<T> {
public:
	graph() = default;

	graph(const vector<pair<T, T>>& edges) {
		for (const auto& edge : edges) {
			add(edge);
		}
	}

	void add(const pair<T, T>& edge) override {
		edgeList[edge.first].insert(edge.second);
		edgeList[edge.second].insert(edge.first);
	}

	void remove(const T& vertex) override {
		auto vertexInfo = edgeList.find(vertex);
		if (vertexInfo == edgeList.end()) {
			return;
		}
		auto& connectedVertexes = (*vertexInfo).second;
		for (auto& connectedVertex : connectedVertexes) {
			edgeList[connectedVertex].erase(vertex);
		}
		edgeList.erase(vertex);
	}

	bool contains(const T& vertex) override {
		return edgeList.find(vertex) != edgeList.end();
	}

	size_t path(const T& startVertex, const T& endVertex) override {
		auto startVertexInfo = edgeList.find(startVertex);
		auto endVertexInfo = edgeList.find(endVertex);
		if (startVertexInfo == edgeList.end() || endVertexInfo == edgeList.end()) {
			return 0;
		}
		unordered_map<T, size_t> visited;
		queue<pair<T, unordered_set<T>>> q;
		visited[startVertex] = 0;
		q.push(*startVertexInfo);
		while (q.size()) {
			auto& connectedVertexes = q.front();
			for (auto& connectedVertex : connectedVertexes.second) {
				if (connectedVertex == endVertex) {
					return visited[connectedVertexes.first] + 1;
				}
				if (visited.find(connectedVertex) == visited.end()) {
					visited[connectedVertex] = visited[connectedVertexes.first] + 1;
					q.push({ connectedVertex, edgeList[connectedVertex] });
				}
			}
			q.pop();
		}
		return 0;
	}

private:
	unordered_map<T, unordered_set<T>> edgeList;
};
