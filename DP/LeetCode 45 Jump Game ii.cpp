class Solution {
public:
    int D[30001];
    int jump(vector<int>& nums) {
        fill(D + 1, D + 30001, 2147483646);

        for (int curr = 0; curr < nums.size() - 1; curr++) {
            int next;
            cout << curr << ' ' << nums[curr] << '\n';
            for (next = 1; next <= nums[curr]; next++) { // curr���� ���� ������ ����.
                D[curr + next] = min(D[curr] + 1, D[curr + next]); //������ִ� �� vs ���� �ٴ°�+1
                if (curr + next >= nums.size() - 1) {
                    break;
                    curr = nums.size();
                }
            }
            next = 1;
            while (curr + next < nums.size() && nums[curr] + curr >= nums[curr + next] + curr + next) {
                if (next >= nums[curr]) break;
                if (curr + next > nums.size() - 1) break;
                next++;
            }
            curr += next - 1;
        }

        return D[nums.size() - 1];
    }
};