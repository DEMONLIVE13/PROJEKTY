#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
    int x, y;
    bool operator <(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

int orientation(Point p, Point q, Point r) {
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

std::vector<Point> convexHull(std::vector<Point> points) {
    int n = points.size(), k = 0;
    if (n <= 3) return points;
    std::vector<Point> H(2 * n);

    sort(points.begin(), points.end());

    for (int i = 0; i < n; ++i) {
        while (k >= 2 && orientation(H[k - 2], H[k - 1], points[i]) <= 0) k--;
        H[k++] = points[i];
    }

    for (int i = n - 1, t = k + 1; i >= 0; --i) {
        while (k >= t && orientation(H[k - 2], H[k - 1], points[i]) <= 0) k--;
        H[k++] = points[i];
    }

    H.resize(k - 1);
    return H;
}

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int countBoundaryPoints(const std::vector<Point>& points) {
    int boundaryPoints = 0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int dx = std::abs(points[j].x - points[i].x);
        int dy = std::abs(points[j].y - points[i].y);
        boundaryPoints += gcd(dx, dy) + 1;
    }
    return boundaryPoints - n;
}

long long shoelaceArea(const std::vector<Point>& points) {
    long long area = 0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (long long)points[i].x * points[j].y;
        area -= (long long)points[i].y * points[j].x;
    }
    return std::abs(area) / 2;
}

int main() {
    int Z;
    std::cin >> Z;
    while (Z--) {
        int Ni;
        std::cin >> Ni;
        std::vector<Point> points(Ni);
        for (int i = 0; i < Ni; i++) {
            std::cin >> points[i].x >> points[i].y;
        }

        std::vector<Point> hull = convexHull(points);
        long long area = shoelaceArea(hull);
        int boundaryPoints = countBoundaryPoints(hull);
        long long interiorPoints = area - (boundaryPoints / 2) + 1;

        // Wyświetlanie wyniku z etykietą "wynik:"
        std::cout << "wynik: " << interiorPoints << std::endl;
    }
    return 0;
}













