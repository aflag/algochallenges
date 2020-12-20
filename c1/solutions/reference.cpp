#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

void populate(unordered_set<int>& people, int size);
int find_islands(vector<unordered_set<int>>& graph);
void expand_from(unordered_set<int> &unseen, int p, const vector<unordered_set<int>> &graph);

int main(void) {
    string line;
    while (getline(cin, line)) {
        int n_people;
        istringstream(line) >> n_people;
        vector<unordered_set<int>> graph;
        for (int p1 = 0; p1 < n_people; ++p1) {
            unordered_set<int> neighbors;
            populate(neighbors, n_people);
            neighbors.erase(p1);
            getline(cin, line);
            int nf;
            istringstream notfriends(line);
            while (notfriends >> nf) {
                neighbors.erase(nf);
            }
            graph.push_back(neighbors);
        }
        int islands = find_islands(graph);
        if (islands == 1) {
            cout << 0 << endl;
        } else {
            cout << islands << endl;
        }
    }
    return 0;
}

void populate(unordered_set<int>& population, int n_people) {
    for (int i = 0; i < n_people; ++i) {
        population.insert(i);
    }
}

int pop(unordered_set<int>& c) {
    int result = *begin(c);
    c.erase(begin(c));
    return result;
}

int find_islands(vector<unordered_set<int>>& graph) {
    unordered_set<int> unseen;
    populate(unseen, graph.size());
    int n_islands = 0;
    while (!unseen.empty()) {
        int p = pop(unseen);
        expand_from(unseen, p, graph);
        ++n_islands;
    }
    return n_islands;
}

void expand_from(unordered_set<int>& unseen, int p, const vector<unordered_set<int>>& graph) {
    queue<int> nodes;
    nodes.push(p);
    while (!nodes.empty()) {
        int curr = nodes.front();
        nodes.pop();
        unseen.erase(curr);
        for (auto it = graph[curr].begin() ; it != graph[curr].end(); ++it) {
            if (unseen.find(*it) != unseen.end()) {
                nodes.push(*it);
            }
        }
    }
}
