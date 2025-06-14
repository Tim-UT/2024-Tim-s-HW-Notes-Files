fs = import('fs')

tests = [
    'public/lab9-1',
    'public/lab9-2',
    'public/lab9-3',
    'public/lab9-4',
    'public/lab9-5',
]

foreach test : tests
    test(test, files('runner.py'), args : [test, exe.full_path()])
endforeach
