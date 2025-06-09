# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    for a in 0..(nums.length - 1)
        b = target - nums[a]
        target_index = nums.index(b)
        if(target_index)
            if(a != target_index)
                return [a, target_index]
            end
        end
    end
end

print two_sum([3,2,4], 6)
