package main

import (
	"fmt"
	"math"
)

func lengthOfLongestSubstring(str string ) int {
	m := make(map[rune]int)
	n := len(str)
	l := 0
	r := 0
	result := 0

	runes := []rune(str)

	for ; r < n; r++ {
		curr := runes[r]
		if pos, ok := m[curr]; ok {
			l = int(math.Max(float64(pos), float64(l)))
		}
		result = int(math.Max(float64(result), float64(r - l + 1)))
		m[curr] = r + 1
	}
	return result
}


func main() {
	data := []string{"abcdef", "aaaa", "ababxyz"}
	for _, v := range data {
		o := lengthOfLongestSubstring(v)
		fmt.Printf("String [%v] : (%v)", v, o)
	}
}
