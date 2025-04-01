package main

func dfs(root *TreeNode, ans *int) (sum int, sz int) {
	if root == nil {
		return
	}
	sum = root.Val
	sz = 1

	if root.Left != nil {
		s1, s2 := dfs(root.Left, ans)
		sum += s1
		sz += s2
	}

	if root.Right != nil {
		s1, s2 := dfs(root.Right, ans)
		sum += s1
		sz += s2
	}

	if sum/sz == root.Val {
		*ans++
	}
	return sum, sz
}

func averageOfSubtree(root *TreeNode) int {
	ans := 0
	dfs(root, &ans)
	return ans
}
