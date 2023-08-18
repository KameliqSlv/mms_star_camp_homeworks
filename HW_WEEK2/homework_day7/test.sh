#!/bin/bash

gcc rec.c -lm -o program


if [ $? -ne 0 ]; then
  echo "Error"
  exit 1
fi

for input_file in tests/*.in; do
test_case="${%.*}"
output_file="${test_case}.out"
temp_output_file="${test_case}_temp.out"  
program < "$input_file" > "$temp_output_file" 
   
if diff -wB "$output_file" "$temp_output_file" >/dev/null; then
echo "Its ok"
else
echo "Error"
fi

    rm "$temp_output_file"  

done
rm program
