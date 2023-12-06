class Solution {
public:
    int totalMoney(int n) {
        // Step 1: Calculate the number of complete weeks and remaining days
        int week_count = n / 7;
        int remaining_days = n % 7;
        
        // Step 2: Calculate the contribution from complete weeks using the arithmetic sum formula
        int total = ((week_count * (week_count - 1)) / 2) * 7;

        // Step 3: Calculate the contribution from complete weeks (additional on Mondays)
        total += week_count * 28;

        // Step 4: Calculate the contribution from remaining days using the arithmetic sum formula
        total += ((remaining_days * (remaining_days + 1)) / 2) + (week_count * remaining_days);

        // Step 5: Return the total contribution
        return total;
    }
};
