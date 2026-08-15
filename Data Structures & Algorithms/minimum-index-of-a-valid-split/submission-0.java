public class Solution {
    public int minimumIndex(List<Integer> nums) {
        Map<Integer, Integer> left = new HashMap<>();
        Map<Integer, Integer> right = new HashMap<>();
        int n = nums.size();

        for (int num : nums) {
            right.put(num, right.getOrDefault(num, 0) + 1);
        }

        for (int i = 0; i < n; i++) {
            int num = nums.get(i);
            left.put(num, left.getOrDefault(num, 0) + 1);
            right.put(num, right.get(num) - 1);

            int leftLen = i + 1;
            int rightLen = n - i - 1;

            if (2 * left.get(num) > leftLen && 2 * right.get(num) > rightLen) {
                return i;
            }
        }

        return -1;
    }
}