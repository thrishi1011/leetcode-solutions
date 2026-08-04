class Solution(object):
    def findMissingElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        minnum = min(nums)
        maxnum = max(nums)

        for i in range(minnum, maxnum+1):
            if i not in nums:
                ans.append(i)

        ans.sort()
        return ans