class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def sort2(a, b):
            if nums[a] > nums[b]:
                nums[a], nums[b] = nums[b], nums[a]

        def sort3(a, b, c):
            sort2(a, b)
            sort2(b, c)
            sort2(a, b)

        def quicksort(left, right):
            while left < right:
                mid = (left + right) // 2
                sort3(left, mid, right)
                pivot = nums[mid]
                l, r = left + 1, right - 1
                while l <= r:
                    while nums[l] < pivot:
                        l += 1
                    while nums[r] > pivot:
                        r -= 1
                    if l <= r:
                        nums[l], nums[r] = nums[r], nums[l]
                        l, r = l + 1, r - 1
                if r - left < right - l:
                    quicksort(left, r)
                    left = l
                else:
                    quicksort(l, right)
                    right = r

        quicksort(0, len(nums) - 1)
        return nums
