fs = import('fs')

tests = [
    'test',
]

foreach test : tests
    test(test, files('runner.py'), args : [test, exe.full_path()])
endforeach
