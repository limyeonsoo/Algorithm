class Solution {
    public int[] twoSum(int[] nums, int target) {
        var map = new HashMap<Integer, Integer>();
        var answer = new int[2];
        int index = -1;
        for(var left: nums) {
            var right = target - left;
            index++;
            if(map.containsKey(right)) {
                answer[0] = index;
                answer[1] = map.get(right);
                break;
            }
            map.put(left, index);
        }
        
        return answer;
    }
}

class Solution1 {
    public int[] twoSum(int[] nums, int target) {
        int left = 0, right = 0;
        var answer = new int[2];
        for(left = 0; left < nums.length - 1; left++) {
            for(right = left + 1; right < nums.length; right++) {
                if(nums[left] + nums[right] == target) {
                    answer[0] = left;
                    answer[1] = right;
                    return answer;
                }
            }
        }
        
        return answer;
    }
}
