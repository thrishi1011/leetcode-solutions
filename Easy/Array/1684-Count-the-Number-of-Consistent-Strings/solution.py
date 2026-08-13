class Solution(object):
    def countConsistentStrings(self, allowed, words):
        """
        :type allowed: str
        :type words: List[str]
        :rtype: int
        """

        cnt = len(words)
        for word in words:
            for ch in word:
                if ch not in allowed:
                    cnt -= 1
                    break

        return cnt