//Given a list containing future price predictions of two different stocks for the next n-days, find the maximum profit that can be earned by selling the stocks.
//https://www.techiedelight.com/find-maximum-profit-that-can-be-earned-by-selling-stocks/



// Utility function to return the maximum of two integers
int max(int i, int j) {
    return i > j ? i : j;
}
 
// Recursive function to find the maximum profit that can be earned by selling stocks.
// Here, arrays `x[0…n]` and `y[0…n]` contains the future price predictions of the
// two different stocks for the next n-days
int maxProfit(int x[], int y[], int n)
{
    // base case
    if (n < 0) {
        return 0;
    }
 
    // store the maximum profit gained
    int profit = 0;
 
    // sell the first stock on the n'th day, and recur for the (n-1)'th day
    profit = max(profit, x[n] + maxProfit(x, y, n - 1));
 
    // sell the second stock on the n'th day, and recur for the (n-2)'th day
    // (no transaction can be made on the (n-1)'th day)
    profit = max(profit, y[n] + maxProfit(x, y, n - 2));
 
    // return the maximum profit
    return profit;
}
 
// Utility function to return the maximum of two integers
int max(int i, int j) {
    return i > j ? i : j;
}
 
// Function to find the maximum earnings that can be earned by selling the stocks.
// Here, arrays `x[0…n-1]` and `y[0…n-1]` contains the future price predictions
// of the two different stocks for the next n-days
int maxProfit(int x[], int y[], int n)
{
    // Create an auxiliary array `T[]` to save solutions to the subproblems
    // Here, `T[i]` stores the maximum earnings till day `i`
    int T[n + 1];
 
    // Base cases
    T[0] = 0;
    T[1] = max(x[0], y[0]);
 
    // Fill the auxiliary array `T[]` in bottom-up manner
    for (int i = 2; i <= n; i++) {
        T[i] = max(x[i - 1] + T[i - 1], y[i - 1] + T[i - 2]);
    }
 
    // T[n] stores the maximum earnings till day `n`
    return T[n];
}
 


int main()
{
    int x[] = { 5, 3, 4, 6, 3 };
    int y[] = { 8, 4, 3, 5, 10 };
    int n = sizeof(x) / sizeof(x[0]);
 
    printf("Maximum profit earned is %d", maxProfit(x, y, n - 1));
 
    return 0;
}




