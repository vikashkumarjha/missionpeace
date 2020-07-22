package main
import "fmt"


func twoSum(nums []int, target int) []int {
    m := map[int]int{}

    for index, v := range nums {
        if _, ok := m[target - v]; ok {
            return []int{index, m[target-v]}
        }
        m[v] = index
    }
    return []int{}
}

func main() {
    nums := []int { 2, 7, 11, 15}
    result := twoSum(nums, 9)
    fmt.Printf("\n Result [%v]", result)
}
