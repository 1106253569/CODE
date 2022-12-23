import java.util.Arrays;
import java.util.HashMap;

public class Solution {
    public static void main(String[] args) {
        int[] nums = {1, 3, -5, 4, 9, -5, 9, -15, 2};
        System.out.println(maxSubArray(nums));
    }

    public static int maxSubArray(int[] nums) {
        int sum = nums[0];
        int l = nums.length;
        int loc = 1;
        int temp = sum;
        if (l > 1) {
            while (loc < l) {
                if (temp + nums[loc] <= nums[loc])
                    temp = nums[loc];
                else
                    temp += nums[loc];
                if (sum < temp)
                    sum = temp;
                loc += 1;
            }
        }
        return sum;
    }

    public static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> res = new HashMap<Integer, Integer>();
        res.put(target - nums[0], 0);
        for (int i = 1; i < nums.length; i++) {
            if (res.containsKey(nums[i]))
                return new int[]{res.get(nums[i]), i};
            else
                res.put(target - nums[i], i);
        }
        return nums;
    }

    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int i = n; i > 0; i--) {
            nums1[m + n - i - 1] = nums2[n - i - 1];
        }
        Arrays.sort(nums1);
    }

}