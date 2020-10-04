class Solution {
    public int findPairs(int[] nums, int k) {
        Set<Integer> visited = new HashSet<>();
        Set<Integer> higher = new HashSet<>();
        for (int num : nums) {
            if (visited.contains(num - k)) {
                higher.add(num);
            }
            if (visited.contains(num + k)) {
                higher.add(num + k);
            }
            visited.add(num);
        }
        return higher.size();
    }
}
