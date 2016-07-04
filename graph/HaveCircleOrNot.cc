#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

//If can topological sort - if have a circle
//leetcode 207 Course Schedule I
bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
	vector<vector<int> > graph(numCourses);
	vector<int> indegree(numCourses, 0);
	vector<int> ret;
	queue<int> Q;
	int tmp, count = 0;
	
	for (int i = 0; i < prerequisites.size(); i++) {
		graph[prerequisites[i].second].push_back(prerequisites[i].first);
		indegree[prerequisites[i].first]++;
	}
	
	for (int i = 0; i < indegree.size(); i++) {
		if (indegree[i] == 0)
			Q.push(i);
	}
	
	while (!Q.empty()) {
		tmp = Q.front();
		Q.pop();
		count++;
		for (int i = 0; i < graph[tmp].size(); i++) {
			indegree[graph[tmp][i]]--;
			if (indegree[graph[tmp][i]] == 0)
				Q.push(graph[tmp][i]);
		}
	}

	return (count == numCourses);
}
