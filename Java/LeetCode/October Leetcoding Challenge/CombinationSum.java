class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> combinations = new ArrayList<>();
        Stack<Integer> current = new Stack<>();
        getCombinations(candidates, combinations, current, candidates.length, target);
        return combinations;
    }

    private void getCombinations(int[] candidates, List<List<Integer>> combinations, Stack<Integer> current, int pos, int target) {
        if ((pos == 0) || (target < 0)) {
            return;
        }
        if (target == 0) {
            combinations.add((List<Integer>) current.clone());
            return;
        }
        getCombinations(candidates, combinations, current, pos - 1, target);
        if (candidates[pos - 1] > target) {
            return;
        }
        current.push(candidates[pos - 1]);
        getCombinations(candidates, combinations, current, pos, target - candidates[pos - 1]);
        current.pop();
    }
}
