#OM NAMO NARAYANA
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        target, rem = divmod(sum(nums), k)
          
        
        #if any one of the number is greater than the target then return false
        if rem or max(nums) > target: return False

				
        memo = [None] * (1 << len(nums))
        memo[-1] = True
        
        #ith bit of used is set if the number at ith index is used
        def search(used, todo):

						#if the ith element is not used yet
            if memo[used] is None:

								#maximum value that can be removed from the todo
                targ = (todo - 1) % target + 1
                  
                
                memo[used] = any(
                  								#check whether the ith element can be removed
                                  search(used | (1<<i), todo - num) 
                                  for i, num in enumerate(nums)
                  								
                  								#if the ith element is not used yet and the number at the ith index is less than num
                                  if (used >> i) & 1 == 0 and num <= targ
                                )
            #memo[used] = true if it's used
            return memo[used]

        return search(0, target * k)