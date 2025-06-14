fs = import('fs')

tests = [
    'private/part2-4',
    'private/part2-3',
    'private/part2-2',
    'private/part2-1',
]

foreach test : tests
    test(test, files('runner.py'), args : [test, exe.full_path()])
endforeach
