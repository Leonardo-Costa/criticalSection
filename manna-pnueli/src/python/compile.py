#Leonardo Loureiro Costa

import os
import sys

source_dir = "..\\c\\"
main_file = "main.c"
funcs_file = "funcs.c"

if len(sys.argv) > 1:
    num_threads = sys.argv[1]
else:
    num_threads = "4"

command = f"gcc {os.path.join(source_dir, main_file)} {os.path.join(source_dir, funcs_file)} -o {os.path.join(source_dir, 'main')} -fopenmp && {os.path.join(source_dir, 'main')} {num_threads}"
os.system(command)
