from collections import Counter
import re

fh = open('twl.txt', 'r')
ALL_WORDS = set()
for line in fh:
    line = line.strip()
    ALL_WORDS.add(line)

fh.close()

N = 10000

SIXES = []
fh = open('count_1w.txt', 'r')
for line in fh:
    word, _ = line.split()
    word = word.upper()
    if re.match(r'^[A-Z]{6}$', word) and word in ALL_WORDS:
        SIXES.append(word)
    if len(SIXES) >= N:
        break

M = 3600
postfixes = Counter()
for six in SIXES:
    for i in xrange(0, 2):
        postfixes[six[i:]] += 1

postfix_usage = Counter()
for six in SIXES:
    for i in xrange(0, 2):
        postfix_usage[six] += postfixes[six[i:]]

frequent_sixes = [
    k
    for k, v in sorted(postfix_usage.items(), key=lambda x: -x[1])[:M]
]


for six in sorted(frequent_sixes):
    print six
#print 'MUUMUU'
