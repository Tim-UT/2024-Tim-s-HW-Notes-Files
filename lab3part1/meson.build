project('lab3part1', 'c',
  default_options : ['c_std=gnu18', 'warning_level=3'],
)

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

exe = executable('part1', 'part1.c', dependencies : m_dep)

subdir('tests')
