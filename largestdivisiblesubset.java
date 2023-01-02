//every pair of subset modulus should be zero, for eg-[1,2,4,8]->subset[2,4,8] we will check the condition si%sj==0 0r sj%si==0 so 8%4==0 and 4%2==0 and 8%2==0 so it satisfies the conditions.
//sort the array and check use recursion and backtrcking along with condition  to find the largest subset of the array.
public class Solution {
  List<Integer> res;
  int[] mem;
public List<Integer> largestDivisibleSubset(int[] nums) {
    Arrays.sort(nums);
    mem = new int[nums.length];
    Arrays.fill(mem, -1);
    res = new ArrayList<>();
    helper(nums, 0, new ArrayList<>(), 1);
    return res;
}
private void helper(int[] nums, int index, List<Integer> curr, int prev) {
    if (curr.size() > res.size()) {
        res = new ArrayList<>(curr);
    }
    for (int i = index; i < nums.length; i++) {
        if (curr.size() > mem[i] && nums[i] % prev == 0) {
            mem[i] = curr.size();
            curr.add(nums[i]);
            helper(nums, i + 1, curr, nums[i]);
            curr.remove(curr.size() - 1);//backtrack to get the new set of elements;
        }
    }
  }
}
