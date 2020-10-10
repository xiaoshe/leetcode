from typing import *
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def go(s, stack):
            l = len(stack)
            if l > 4:
                return
            if l == 4 and not s:
                ret.append('.'.join(stack))
                return
                
            if not s:
                return
    
            if s[0] == '0':
                stack.append(s[0])
                go(s[1:], stack)
                del stack[-1]
                return
    
            l2 = len(s)
            if l2 >= 1:
                stack.append(s[0])
                go(s[1:], stack)
                del stack[-1]
            if l2 >= 2 and int(s[0:2]) < 256:
                stack.append(s[0:2])
                go(s[2:], stack)
                del stack[-1]
            if l2 >= 3 and int(s[0:3]) < 256:
                stack.append(s[0:3])
                go(s[3:], stack)
                del stack[-1]

        ret = []
        stack = []
        go(s, stack)
        return ret

s = Solution()
print(s.restoreIpAddresses("0000"))
print(s.restoreIpAddresses("25525511135"))
print(s.restoreIpAddresses("101023"))
