print '#ifndef DICT_DAWG_H'
print '#define DICT_DAWG_H'
print 'PROGMEM const uint8_t DICT_DAWG [] = {'

data = open('output.dawg', 'r').read()
text = ['0x%02x,' % ord(c) for c in data]

for i, item in enumerate(text):
    print item,
    if i % 16 == 15:
        print

print '0x00 };'
print 'const uint16_t DICT_DAWG_LENGTH = %s;' % (len(data),)
print '#endif'
