class Solution:
    def check(self, nums:List[int], target:int, mid:int)->bool:
        return nums[mid] <= nums[len(nums) - 1]
    def search(self, nums: List[int], target: int) -> int:
        low=0
        high=len(nums)-1
        ans=-1
        while(low<=high):
            mid=low+(high-low)//2
            if(self.check(nums,target,mid)):
                ans=mid
                high=mid-1
            else:
                low=mid+1



        if target >= nums[ans] and target <= nums[len(nums) - 1]:
            low = ans
            high = len(nums) - 1
        else :
            low = 0
            high = ans - 1

        ans = -1

        while(low <= high):
            mid = low + (high - low)//2
            if(nums[mid] <= target):
                if(nums[mid] == target):
                    ans = mid
                low = mid + 1
            else :
                high = mid - 1

        return ans;
