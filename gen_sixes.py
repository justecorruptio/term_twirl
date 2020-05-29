import re

fh = open('twl.txt', 'r')
ALL_WORDS = set()
for line in fh:
    line = line.strip()
    ALL_WORDS.add(line)

fh.close()

N = 3000
SIXES = []
fh = open('count_1w.txt', 'r')
for line in fh:
    word, _ = line.split()
    word = word.upper()
    if re.match(r'^[A-Z]{6}$', word) and word in ALL_WORDS:
        SIXES.append(word)
    if len(SIXES) >= N:
        break

for six in sorted(SIXES):
    print six
