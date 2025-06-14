fs = import('fs')

tests = [
    'private/3in',
    'public/1ft-5in',
    'public/6ft',
]

foreach test : tests
    test(test, files('runner.py'), args : [test, exe.full_path()])
endforeach
