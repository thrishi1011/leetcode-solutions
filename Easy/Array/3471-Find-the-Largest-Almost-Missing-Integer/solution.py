class Solution(object):
    def largestInteger(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        mp = {}
        ans = []

        for num in nums:
            if num in mp:
                mp[num] += 1
            else:
                mp[num] = 1

        if k == 1:
            for num in mp:
                if mp[num] == 1:
                    ans.append(num)

            if len(ans) == 0:
                return -1

            return max(ans)

        if k == n:
            return max(nums)

        if k > 1 and k < n:
            if mp[nums[0]] == 1:
                ans.append(nums[0])

            if mp[nums[n - 1]] == 1:
                ans.append(nums[n - 1])

            if len(ans) == 0:
                return -1

            return max(ans)

        return -1
