fs = import('fs')

tests = [
    'private/5-free',
    'public/1-free',
    'public/2-free',
]

foreach test : tests
    test(test, files('runner.py'), args : [test, exe.full_path()])
endforeach
