fs = import('fs')

tests = [
    'public/part1-1',
    'private/part1-2',
]

foreach test : tests
    test(test, files('runner.py'), args : [test, exe.full_path()])
endforeach
