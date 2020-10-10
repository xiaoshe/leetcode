import sys
class Solution:
    def simplifyPath(self, path: str) -> str:
        ret = []
        for x in path.split("/"):
            if not x or x == '.':
                continue
            if x == "..":
                if ret:
                    del ret[-1]
            else:
                ret.append(x)
        return '/' + '/'.join(ret)

s = Solution()
r = s.simplifyPath(sys.argv[1])
print(r)
