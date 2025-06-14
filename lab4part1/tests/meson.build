fs = import('fs')

tests = [
    'public/part1-1',
    'public/part1-2',
    'public/part1-3',
    'private/part1-4',
]

foreach test : tests
    test(test, files('runner.py'), args : [test, exe.full_path()])
endforeach
