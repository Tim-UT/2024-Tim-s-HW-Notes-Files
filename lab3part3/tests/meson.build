fs = import('fs')

tests = [
    'public/part3-1',
    'public/part3-2',
    'private/part3-3',
]

foreach test : tests
    test(test, files('runner.py'), args : [test, exe.full_path()])
endforeach
