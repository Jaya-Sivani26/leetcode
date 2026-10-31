#include <stdlib.h>

bool canFinish(int numCourses, int** prerequisites,
               int prerequisitesSize,
               int* prerequisitesColSize) {

    int* indegree = calloc(numCourses, sizeof(int));
    int** graph = malloc(numCourses * sizeof(int*));
    int* graphSize = calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++)
        graph[i] = malloc(numCourses * sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prerequisite = prerequisites[i][1];

        graph[prerequisite][graphSize[prerequisite]++] = course;
        indegree[course]++;
    }

    int* queue = malloc(numCourses * sizeof(int));
    int front = 0;
    int rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int completed = 0;

    while (front < rear) {
        int course = queue[front++];
        completed++;

        for (int i = 0; i < graphSize[course]; i++) {
            int next = graph[course][i];

            indegree[next]--;

            if (indegree[next] == 0)
                queue[rear++] = next;
        }
    }

    return completed == numCourses;
}