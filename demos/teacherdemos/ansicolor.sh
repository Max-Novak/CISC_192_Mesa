
/*

 This small script prints all available ANSI-colors on the terminal.

#!/bin/bash
*/
 
for i in 30 31 32 33 34 35 36 37 39.40 41 42 43 44 45 46 47 49 
do
 for j in 30 31 32 33 34 35 36 37 39.40 41 42 43 44 45 46 47 49  
 do
   # skip if same fore- and backgroundcolor
   if [ $j -eq $[ i + 10 ] ]; then
     continue
   fi
   echo -e $i $j "\033[${i};${j}mCOLOR\033[0m"
 done
done

#for i in 30 31 32 33 34 35 36 37 39
#do
# for j in 40 41 42 43 44 45 46 47 49 
