class Solution
{
public:
    struct Point
    {
        int x, y;
    };
    struct Rect
    {
        Point p1, p2;
        int area() const { return (p2.x - p1.x) * (p2.y - p1.y); }
    };

    Rect intersection(const Rect &r1, const Rect &r2)
    {
        int x1 = max(r1.p1.x, r2.p1.x);
        int y1 = max(r1.p1.y, r2.p1.y);
        int x2 = min({r1.p2.x, r2.p2.x});
        int y2 = min({r1.p2.y, r2.p2.y});
        return Rect{{x1, y1}, {x2 > x1 ? x2 : x1, y2 > y1 ? y2 : y1}};
    }

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        Rect a{{A, B}, {C, D}}, b{{E, F}, {G, H}};
        return a.area() - intersection(a, b).area() + b.area();
    }
};