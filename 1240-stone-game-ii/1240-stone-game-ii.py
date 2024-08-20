from functools import lru_cache


class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        suffix_sums = [0 for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            suffix_sums[i] = piles[i] + suffix_sums[i + 1]

        @lru_cache(maxsize=None)
        def take_stones(i, m):
            if i >= n:
                return 0
            if i + 2 * m >= n:
                return suffix_sums[i]
            return suffix_sums[i] - min(
                take_stones(i + x, max(m, x)) for x in range(1, 2 * m + 1)
            )

        return take_stones(0, 1)