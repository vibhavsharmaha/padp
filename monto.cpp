/* C++ program for estimation of Pi using Monte
Carlo Simulation */
#include <bits/stdc++.h>
#include<omp.h>
// Defines precision for x and y values. More the
// interval, more the number of significant digits
using namespace std;

int main()
{
	int interval, i,n;
	double rand_x, rand_y, origin_dist, pi;
	int circle_points = 0, square_points = 0;

	// Initializing rand()
	srand(time(NULL));

	// Total Random numbers generated = possible x
	// values * possible y values
	int t;
	printf("Enter the num of threads : ");
	scanf("%d",&t);
	printf("Enter the intervals: ");
	scanf("%d",&n);

	//Extra piece of code for parallelization
	double x = omp_get_wtime();
	omp_set_num_threads(t);
#pragma omp parallel
	for (i = 0; i < (n * n); i++) {

		// Randomly generated x and y values
		rand_x = double(rand() % (n + 1)) / n;
		rand_y = double(rand() % (n + 1)) / n;

		// Distance between (x, y) from the origin
		origin_dist = rand_x * rand_x + rand_y * rand_y;

		// Checking if (x, y) lies inside the define
		// circle with R=1
		if (origin_dist <= 1)
			circle_points++;

		// Total number of points generated
		square_points++;

		// estimated pi after this iteration
		pi = double(4 * circle_points) / square_points;

		// For visual understanding (Optional)
		

		// Pausing estimation for first 10 values (Optional)
		
	}

	// Final Estimated Value
	cout << "\nFinal Estimation of Pi = " << pi;
	double y = omp_get_wtime();

printf("Time for %d threads %lf\n",t,y-x);

	return 0;
}

