#include <assert.h>
#include "common.h"
#include "point.h"

#include <math.h>

void point_translate(struct point *p, double x, double y)
{
	p->x += x;
	p->y += y;
}

double point_distance(const struct point *p1, const struct point *p2)
{
	double dx = p1->x - p2->x;
	double dy = p1->y - p2->y;
	double dist = sqrt(dx * dx + dy * dy);
	return dist;
}

int point_compare(const struct point *p1, const struct point *p2)
{
	struct point origin;
	point_set(&origin, 0.0, 0.0);
	
	double dist1 = point_distance(p1, &origin);
	double dist2 = point_distance(p2, &origin);

	if (dist1 < dist2)
		return -1;
	else if (dist1 > dist2)
		return 1;
	else
		return 0;
}
