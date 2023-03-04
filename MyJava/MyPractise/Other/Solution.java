import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

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
        if (n >= 0) System.arraycopy(nums2, 0, nums1, m, n);
        Arrays.sort(nums1);
    }

    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, int[]> res = new HashMap<Integer, int[]>();
        for (int i : nums1) {
            if (res.containsKey(i)) {
                int[] temp = res.get(i);
                temp[0] += 1;
                res.put(i, temp);
            } else
                res.put(i, new int[]{1, 0});
        }
        for (int i : nums2) {
            if (res.containsKey(i)) {
                int[] temp = res.get(i);
                temp[1] += 1;
                res.put(i, temp);
            }
        }
        ArrayList<Integer> coincide = new ArrayList<Integer>();
        for (Map.Entry<Integer, int[]> entry : res.entrySet()) {
            int[] temp = entry.getValue();
            int i = Math.min(temp[0], temp[1]);
            while (i > 0) {
                coincide.add(entry.getKey());
                i -= 1;
            }
        }
        int[] d = new int[coincide.size()];
        for (int i = 0; i < coincide.size(); i++) {
            d[i] = coincide.get(i);
        }
        return d;
    }
}