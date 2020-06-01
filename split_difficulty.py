CUTOFF = 30000

raw_easy = set()

fh = open('count_1w.txt', 'r')
for i, line in enumerate(fh):
    word, _ = line.split('\t')
    if i < CUTOFF:
        raw_easy.add(word.upper())
fh.close()

fh = open('output.txt', 'r')

easy_words = []
hard_words = []
for line in fh:
    word = line.strip()
    if word in raw_easy:
        easy_words.append(word)
    else:
        hard_words.append(word)

fh.close()

fh = open('easy.txt', 'w')
for word in sorted(easy_words):
    fh.write(word + '\n')
fh.close()

fh = open('hard.txt', 'w')
for word in sorted(hard_words):
    fh.write(word + '\n')
fh.close()
