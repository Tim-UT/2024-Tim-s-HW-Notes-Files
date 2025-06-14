fs = import('fs')

tests = [
    'public/test',
]

foreach test : tests
    test(test, files('runner.py'), args : [test, exe.full_path()])
endforeach
