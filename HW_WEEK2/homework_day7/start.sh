#!/bin/bash

bin="$1"
diff="dif -iad"

declare -a file_base = ("file1" "file2" "file3")

for file in "${file_base[@]}"; do
file_in = "$file.in"
file_out_val= "$file.out"
file_out_tst="$file.out.tst"

if[! -f "$file_in"]; then
printf "In file %s is missing\n" "$file_in"
continue;
fi
if[! -f "$file_out_val"]; then
printf "Validation file %s is missing\n" "$file_out_val"
continue;
fi

printf "Testing against %s\n" "$file_in"

"./$bin" < "$file_in" > "$file_out_val"

$diff "$file_out_tst" "$file_out_val"

e_code = $?
if[$e_code != 0]
  printf "TEST FAIL : %d\n" "$e_code"
    else
            printf "TEST OK!\n"
    fi

    # Pause by prompt
    read -p "Enter a to abort, anything else to continue: " input_data
    # Iff input is "a" then abort
    [ "$input_data" == "a" ] && break
done

exit 0
