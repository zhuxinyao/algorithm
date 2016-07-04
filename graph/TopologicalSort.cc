#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

//Topological sort
//leetcode 210 Course Schedule II
vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
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
		ret.push_back(tmp);
		for (int i = 0; i < graph[tmp].size(); i++) {
			indegree[graph[tmp][i]]--;
			if (indegree[graph[tmp][i]] == 0)
				Q.push(graph[tmp][i]);
		}
	}
	
	if (count == numCourses)
		return ret;
	else
		return vector<int>();
}
