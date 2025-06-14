fs = import('fs')

tests = [
    'public/part2-1',
    'public/part2-2',
]

foreach test : tests
    test(test, files('runner.py'), args : [test, exe.full_path()])
endforeach
