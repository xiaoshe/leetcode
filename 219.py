from typing import *
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        exist = {}
        i = 0
        for x in nums:
            if x not in exist:
                exist[x] = i
            else:
                if i - exist[x] <= k:
                    return True
                else:
                    exist[x] = i
            i = i+1
        return False

s = Solution()

nums = [1,2,3,1]
k = 3
print(s.containsNearbyDuplicate(nums, k))
