fs = import('fs')

tests = [
    'public/lab7-1',
    'public/lab7-2',
    'public/lab7-3',
    'public/lab7-4',
    'public/lab7-5',
    'public/lab7-6',
    'private/lab7-7',
    'private/lab7-8',
    'private/lab7-9',
    'private/lab7-10',
]

foreach test : tests
    test(test, files('runner.py'), args : [test, exe.full_path()])
endforeach
