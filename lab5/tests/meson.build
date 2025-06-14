fs = import('fs')

tests = [
    'public/lab5-1',
    'public/lab5-2',
    'public/lab5-3',
    'public/lab5-4',
    'public/lab5-5',
    'private/lab5-6',
    'private/lab5-7',
    'private/lab5-8',
    'private/lab5-9',
    'private/lab5-10',
]

foreach test : tests
    test(test, files('runner.py'), args : [test, exe.full_path()])
endforeach
