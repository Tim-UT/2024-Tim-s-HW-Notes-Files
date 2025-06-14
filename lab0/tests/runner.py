#!/usr/bin/env python3

import argparse
import difflib
import pathlib
import subprocess
import sys

TESTS_DIR = pathlib.Path(__file__).resolve().parent
INPUTS_DIR = TESTS_DIR / "inputs"
OUTPUTS_DIR = TESTS_DIR / "outputs"

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

def display_str(s):
    s = s.replace("\n", "\\n").replace("\t", "\\t")
    return f'"{s}"'

def run(test, exe):
    input_path = INPUTS_DIR / test
    output_path = OUTPUTS_DIR / test
    timeout = 10

    with open(output_path, "r") as f:
        expected = f.read()

    stdin = None
    if input_path.exists():
        with open(input_path, 'r') as f:
            stdin = f.read()
    
    try:
        p = subprocess.run(
            [exe], capture_output=True, input=stdin, timeout=timeout, text=True
        )
    except subprocess.TimeoutExpired:
        eprint("Timeout")
        return 1

    if p.returncode != 0:
        eprint("Your program returned an error")
        return 1

    if p.stdout == expected:
        return 0

    stdout_lines = p.stdout.splitlines(keepends=True)
    expected_lines = expected.splitlines(keepends=True)
    for line in difflib.unified_diff(stdout_lines, expected_lines,
                                     fromfile='output', tofile='expected', n=5):
        if line.endswith("\n"):
            eprint(line, end='')
        else:
            eprint(line)
            eprint("\\ No newline at end of file")
    return 1

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("test")
    parser.add_argument("exe")
    args = parser.parse_args()

    return run(args.test, args.exe)

if __name__ == "__main__":
    sys.exit(main())
