import sys

class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        words = str.split()
        if len(pattern) != len(words):
            return False

        mapa = {}
        mapb = {}
        for i in range(len(pattern)):
            ka = pattern[i]
            kb = words[i]
            if ka not in mapa:
                if kb not in mapb:
                    # 都不存在
                    mapa[ka] = kb
                    mapb[kb] = ka
                else:
                    return False
            else:
                if kb not in mapb:
                    return False
                else:
                    # 都存在
                    if mapa[ka] != kb or mapb[kb] != ka:
                        return False
        return True

s = Solution()
ret = s.wordPattern(sys.argv[1], sys.argv[2])
print(ret)
