#include "graph.hpp"

int main() {
	graph<int> gel({ {1,2},{1,3},{1,4},{2,3},{3,4}, {5, 6}, { 4, 6 }, { 2,5 }, {6, 7}, {6, 8}, {8, 9} });
	cout << gel.path(1, 5);
	gel.remove({ 1,2 });
	cout << gel.path(1, 5);
	gel.add({ 1,2 });
	cout << gel.path(1, 5);
	return 0;
}
