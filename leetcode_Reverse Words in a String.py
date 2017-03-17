
def reverseWords(s):
    return ' '.join([word[::-1] for word in s[::-1].split()])

ss = "huang mu xuan like    cs"
print(ss[::-1].split())
ss_temp1 = [ x[::-1] for x in ss.split()]
print(ss_temp1)
ss_temp = map(lambda x : x[::-1],ss.split())
print(list(ss_temp))
print(type(ss_temp1))
print(type(ss_temp))
aa = list(ss_temp)
print(type(aa))
aaa=' '.join(aa)
print(aaa)
print(' '.join(ss_temp))
sss=reverseWords(ss)
print(sss)
a = [ 1, 3, 4, 5, 6]
print(a[::-1])