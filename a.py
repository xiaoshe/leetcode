def f(word, index):
    l = len(word)
    if index > l / 2:
        return word
    t = word[0:index] + word[l-index-1] + word[index+1:
    a = word[index]
    word[index] = word[l-index-1]
    word[l-index-1] = a
    f(word, index+1)
    print(word)

s = "123456"
f(s, 0)
