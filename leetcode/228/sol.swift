class Solution {
    func summaryRanges(_ nums: [Int]) -> [String] {
        var res: [String] = []
        var cur = 0
        let n = nums.count
        while cur < n {
            var start = cur
            while cur + 1 < n && nums[cur + 1] == nums[cur] + 1 {
                cur += 1
            }
            if start == cur {
                res.append("\(nums[start])")
            } else {
                res.append("\(nums[start])->\(nums[cur])")
            }
            cur += 1
        }
        return res
    }
}