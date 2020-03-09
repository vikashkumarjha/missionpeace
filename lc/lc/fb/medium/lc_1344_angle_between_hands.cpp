class Solution {
    public:
        double angleClock(int hour, int minutes) {
            double h = (hour % 12 + (double)(minutes)/60) * HOUR_CONV;
            double m = minutes * MINUTE_CONV;
            double dif = abs(h - m);
            return min(360-dif, dif);
        }
        const int HOUR_CONV = 30;
        const int MINUTE_CONV = 6;
};
