#!/bin/bash
echo "GENERATING SIXES"
python gen_sixes.py > generated_data/sixes.txt
echo "GENERATING USED WORDS LIST"
python gen_word_list.py > generated_data/output.txt
echo "SPLITTING INTO EASY AND HARD LISTS"
python split_difficulty.py
echo "TESTING OUTPUTS"
python test_output.py generated_data/easy.txt
python test_output.py generated_data/hard.txt
python test_output.py generated_data/more.txt
echo "GENERATING DAWG"
python dawg_gen.py generated_data/easy.txt generated_data/easy.dawg
python dawg_gen.py generated_data/hard.txt generated_data/hard.dawg
python dawg_gen.py generated_data/more.txt generated_data/more.dawg
echo "GENERATING .H FILE"
echo '' > generated_data/dict_dawg.h
python create_dawg_progmem.py easy >> generated_data/dict_dawg.h
python create_dawg_progmem.py hard >> generated_data/dict_dawg.h
python create_dawg_progmem.py more >> generated_data/dict_dawg.h
echo "DONE"
