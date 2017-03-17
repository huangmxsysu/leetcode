def readBinaryWatch(self, num):
    return ['%d:%02d'.format(h,m) for m in range(60) for h in range(12) if (bin(h) + bin(m)).count('1') == num]