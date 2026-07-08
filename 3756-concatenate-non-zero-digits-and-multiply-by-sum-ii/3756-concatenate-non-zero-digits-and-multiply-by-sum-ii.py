MOD = 10**9 + 7

class Solution(object):
    def sumAndMultiply(self, s, queries):
        n = len(s)

        # powers of 10
        pow10 = [1] * (n + 1)
        for i in range(1, n + 1):
            pow10[i] = (pow10[i - 1] * 10) % MOD

        # segment tree node = (value, digit_sum, non_zero_count)
        tree = [(0, 0, 0)] * (4 * n)

        def merge(a, b):
            val1, sum1, cnt1 = a
            val2, sum2, cnt2 = b

            val = (val1 * pow10[cnt2] + val2) % MOD
            return (val, sum1 + sum2, cnt1 + cnt2)

        def build(node, l, r):
            if l == r:
                if s[l] == '0':
                    tree[node] = (0, 0, 0)
                else:
                    d = int(s[l])
                    tree[node] = (d, d, 1)
                return

            mid = (l + r) // 2
            build(node * 2, l, mid)
            build(node * 2 + 1, mid + 1, r)
            tree[node] = merge(tree[node * 2], tree[node * 2 + 1])

        def query(node, l, r, ql, qr):
            if qr < l or r < ql:
                return (0, 0, 0)

            if ql <= l and r <= qr:
                return tree[node]

            mid = (l + r) // 2
            left = query(node * 2, l, mid, ql, qr)
            right = query(node * 2 + 1, mid + 1, r, ql, qr)
            return merge(left, right)

        build(1, 0, n - 1)

        ans = []
        for l, r in queries:
            val, digit_sum, _ = query(1, 0, n - 1, l, r)
            ans.append((val * digit_sum) % MOD)

        return ans