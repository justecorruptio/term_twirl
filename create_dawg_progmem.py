from sys import argv

diff = argv[1]

print '#ifndef DICT_DAWG_%s_H' % (diff.upper(),)
print '#define DICT_DAWG_%s_H' % (diff.upper(),)

data = open('generated_data/' + diff + '.dawg', 'rb').read()
#text = ['0x%02x,' % ord(c) for c in data]
ptrs = []
chars = []
for i, c in enumerate(data):
    if i % 3 < 2:
        ptrs.append(ord(c))
    else:
        chars.append('0x%02x,' % ord(c))


print 'PROGMEM const uint8_t DICT_DAWG_%s [] = {' % (diff.upper(),)

count = 0
for i in xrange(0, len(ptrs), 8):
    s = ptrs[i: i + 8]
    while len(s) < 8:
        s.append(0)
    a, b, c, d, e, f, g, h = s
    assert not any([b & 0xF0, d & 0xF0, f & 0xF0, h & 0xF0])
    print '0x%02x,' % (a,),
    print '0x%02x,' % ((b & 0x0F) | ((g & 0x0F) << 4),),

    print '0x%02x,' % (c,),
    print '0x%02x,' % ((d & 0x0F) | ((g & 0xF0) << 0),),

    print '0x%02x,' % (e,),
    print '0x%02x,' % ((f & 0x0F) | ((h & 0x0F) << 4),),
    if count % 2 == 1:
        print

    count += 1

print '};'

print 'PROGMEM const uint8_t DICT_DAWG_%s_CHARS [] = {' % (diff.upper(),)

for i, item in enumerate(chars):
    print item,
    if i % 16 == 15:
        print

print '};'

print '#define DICT_DAWG_%s_START_PTR 0x%04X' % (
    diff.upper(),
    ord(data[-3]) | (ord(data[-2]) << 8),
)

fh = open('generated_data/' + diff + '.txt', 'r')
count = 0
for line in fh:
    if len(line.strip()) == 6:
        count += 1

print '#define DICT_DAWG_%s_NUM_TARGETS %s' % (
    diff.upper(),
    count,
)

print '#endif'
