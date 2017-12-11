#include <iostream>

/*
 * name: aimi
 * id: zy1706112
 * This program calculate the minimum trangulation of octagon by using dynamic programming
 */

//The matrix of edges' weigh
int polygonWeigh[8][8] = { { 0, 14, 25, 27, 10, 11, 24, 16 },
							{ 14, 0, 18, 15, 27, 28, 16, 14 },
							{ 25, 18, 0, 19, 14, 19, 16, 10 },
							{ 27, 15, 19, 0, 22, 23, 15, 14 },
							{ 10, 27, 14, 22, 0, 14, 13, 20 },
							{ 11, 28, 19, 23, 14, 0, 15, 18 },
							{ 24, 16, 16, 15, 13, 15, 0, 27 },
							{ 16, 14, 10, 14, 20, 18, 27, 0 } };

//weigh of triangle
int weigh(int i, int j, int k)
{
	return polygonWeigh[i][j] + polygonWeigh[i][k] + polygonWeigh[j][k];
}

//work out the minimum triangulation
void minTriangulation(int vertexs, int subTriangulation[8][8])
{
	int i, j, k, r, min;
	for (i = 1; i < vertexs; i++)
		subTriangulation[i][i] = 0;
	for (r = 2; r < vertexs; r++) {
		for (i = 1; i < vertexs - r + 1; i++)
		{
			j = i + r - 1;
			subTriangulation[i][j] = subTriangulation[i + 1][j] + weigh(i - 1, i, j);
			for (k = i + 1; k < i + r - 1; k++)
			{
				min = subTriangulation[i][k] + subTriangulation[k + 1][j] + weigh(i - 1, k, j);
				if (min < subTriangulation[i][j])
					subTriangulation[i][j] = min;
			}
		}
	}
	std::cout << "The minimum trangulation of this octagon is " <<subTriangulation[1][vertexs - 1] << std::endl;
}

//The main body
int main()
{
	int vertexs = 8;
	int subTriangulation[8][8];
	minTriangulation(vertexs, subTriangulation);
	return 0;
}
