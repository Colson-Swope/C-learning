#include <stdio.h> 

#define XMAX 100
#define YMAX 100
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point {
    int x; 
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;

    struct rect screen;
};

struct rect canonrect(struct rect r) 
{
    struct rect temp; 

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = min(r.pt1.x, r.pt2.x);
    temp.pt2.y = min(r.pt1.y, r.pt2.y);
    return temp;
}

struct point makepoint(int x, int y) 
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

// add point: add two points 
struct point addpoint(struct point p1, struct point p2) 
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

// if p is in r, return 1, 0 if not 
int ptinrect(struct point p, struct rect r) 
{
    return p.x >= r.pt1.x && p.x < r.pt2.x
    && p.y >= r.pt1.y && p.y < r.pt2.y;
}

int main() 
{
    struct rect screen; 
    struct point middle;
    struct point makepoint(int, int);

    // POINTER
    struct point origin, *pp;

    pp = &origin;
    printf("origin is (%d, %d)\n", (pp->x, pp->y));
 
    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
    (screen.pt1.y + screen.pt2.y)/2);

}